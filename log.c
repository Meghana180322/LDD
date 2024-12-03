#include <stdio.h>

#define BUFFER_SIZE 5

// Circular buffer to store messages
char* log_buffer[BUFFER_SIZE];
int head = 0;  // Points to the position where the next message will be stored

// Function to add a log message to the circular buffer
void add_log(char* msg) {
    // Store the message at the current position (head)
    log_buffer[head] = msg;

    // Move the head to the next position, wrapping around if needed
    head = (head + 1) % BUFFER_SIZE;
}

// Function to display the current contents of the circular buffer
void display_logs() {
    printf("Current logs in circular buffer:\n");
    for (int i = 0; i < BUFFER_SIZE; i++) {
        printf("%d: %s\n", i, log_buffer[i] ? log_buffer[i] : "Empty");
    }
}

int main() {
    // Simulate adding log messages
    add_log("Log 1");
    add_log("Log 2");
    add_log("Log 3");
    add_log("Log 4");
    add_log("Log 5");
    display_logs();  // Display logs after filling the buffer

    printf("\nAdding more logs:\n");

    // Add more logs, which will overwrite the oldest ones
    add_log("Log 6");
    add_log("Log 7");
    display_logs();  // Display logs after overwriting

    return 0;
}
