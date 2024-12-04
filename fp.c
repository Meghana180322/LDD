#include <stdio.h> // Including header file for printf function

struct cal {
    int (*add)(int, int); // Pointer to function for addition
    int (*sub)(int, int); // Pointer to function for subtraction
};

int add_fun(int x, int y) {
    return x + y; // Function for addition
}

int sub_fun(int x, int y) {
    return x - y; // Function for subtraction
}

int main() {
    int res1, res2;
    struct cal a; // Declaring a variable of type 'cal'
    a.add = add_fun; // Assigning the add function to the add pointer
    a.sub = sub_fun; // Assigning the sub function to the sub pointer

    res1 = a.add(3, 4); // Calling the add function
    res2 = a.sub(6, 3); // Calling the sub function

    printf("%d\n", res1); // Printing the result of addition
    printf("%d", res2); // Printing the result of subtraction

    return 0; // Returning 0 to indicate successful execution
}

