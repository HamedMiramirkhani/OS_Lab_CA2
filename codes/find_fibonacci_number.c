#include "types.h"
#include "user.h"

int call_find_fibonacci_number(int number) {
    int previous_ebx;

    //First Save current ebx in previous_ebx 
    //Save number in ebx
    asm volatile(
        "movl %%ebx, %0\n\t"
        "movl %1, %%ebx"
        : "=r"(previous_ebx)
        : "r"(number)
    );

    //Save output of find_fibbonacci_number before restore ebx
    int fibonacci_num = find_fibonacci_number();

    // Restore last version of ebx
    asm volatile(
        "movl %0, %%ebx"
        :: "r"(previous_ebx)
    );

    return fibonacci_num;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf(2, "Use the function as: find_fibonacci_number<number>\n");
        exit();
    }

    int index_fibonacci_num = atoi(argv[1]);
    // Save input in ebx (use register for save input)
    int fibonacci_num = call_find_fibonacci_number(index_fibonacci_num);
    if (fibonacci_num == -1) 
        printf(2, "Number should be greater than 0 for example: 1, 2, 3, ...\n");
    else 
        printf(1, "%d\n", fibonacci_num);

    exit();
}