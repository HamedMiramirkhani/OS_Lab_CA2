#include "types.h"
#include "x86.h"
#include "defs.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"

static int fibonacci_number(int index) {
    int n1 = 0;
    int n2 = 1;
    int n3 = 0;
    if (index <= 0) 
        return -1;
    else if (index == 1)
        return n1;
    else if (index == 2)
        return n2;
    else {
        for (int i = 2; i < index; i++) {
            n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
        }
        return n3;
    }
}

int sys_find_fibonacci_number(void) {
    return fibonacci_number(myproc()->tf->ebx);
}