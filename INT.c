#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>
#include <linux/init.h>
#include <linux/delay.h>

#define GPIO_PIN 529  // Define the GPIO pin number you want to use

static unsigned int irq_number;

// Interrupt handler function
static irqreturn_t gpio_irq_handler(int irq, void *dev_id) {
    int gpio_value;

    // Read the GPIO pin value
    gpio_value = gpio_get_value(GPIO_PIN);

    // Check if GPIO pin is HIGH (VCC)
    if (gpio_value == 1) {
        pr_info("GPIO Interrupt triggered!\n");  // Log message if GPIO is HIGH
    }

    return IRQ_HANDLED;  // Return that interrupt is handled
}

static int __init gpio_interrupt_init(void) {
    int ret;

    pr_info("GPIO Interrupt Module Loading\n");  // Log that module is loading

    // Request GPIO pin
    ret = gpio_request(GPIO_PIN, "gpio_interrupt");
    if (ret) {
        pr_err("Failed to request GPIO: %d\n", GPIO_PIN);
        return ret;  // If GPIO request fails, return error
    }

    // Set GPIO as input (since we're detecting state)
    ret = gpio_direction_input(GPIO_PIN);
    if (ret) {
        pr_err("Failed to set GPIO direction\n");
        gpio_free(GPIO_PIN);  // Free GPIO if setup fails
        return ret;
    }

    // Get IRQ number for the GPIO pin
    irq_number = gpio_to_irq(GPIO_PIN);
    if (irq_number < 0) {
        pr_err("Failed to get IRQ number for GPIO: %d\n", GPIO_PIN);
        gpio_free(GPIO_PIN);  // Free GPIO if IRQ setup fails
        return irq_number;
    }

    // Request IRQ
    ret = request_irq(
        irq_number,               // IRQ number from gpio_to_irq
        gpio_irq_handler,         // Interrupt handler function
        IRQF_TRIGGER_RISING,      // Trigger on rising edge (GPIO pin changes from low to high)
        "gpio_interrupt",         // Name of the interrupt
        NULL                      // Device ID (optional)
    );
    if (ret) {
        pr_err("Failed to request IRQ: %d\n", irq_number);
        gpio_free(GPIO_PIN);  // Free GPIO if IRQ setup fails
        return ret;
    }

    pr_info("GPIO Interrupt Module Loaded Successfully\n");  // Log success
    return 0;
}

static void __exit gpio_interrupt_exit(void) {
    pr_info("GPIO Interrupt Module Unloading\n");  // Log unloading

    free_irq(irq_number, NULL);  // Free the IRQ when module is unloaded
    gpio_free(GPIO_PIN);         // Free the GPIO pin when module is unloaded

    pr_info("GPIO Interrupt Module Unloaded Successfully\n");  // Log unload success
}

module_init(gpio_interrupt_init);  // Register the initialization function
module_exit(gpio_interrupt_exit);  // Register the exit function

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Meghana");
MODULE_DESCRIPTION("A simple GPIO interrupt driver");
MODULE_VERSION("1.0");
