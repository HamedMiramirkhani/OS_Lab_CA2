#include "types.h"
#include "x86.h"
#include "defs.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"

static int most_callee(int *counts) {
    int most_callee = 0;
    int index_most_callee;
    for (int i = 1; i < sizeof(counts); i++) {
        if (counts[i] > most_callee) {
            most_callee = counts[i];
            index_most_callee = i;
        }
    }
    return index_most_callee;
}

int sys_find_most_callee(void) {
    return most_callee(myproc()->count_calls);
}