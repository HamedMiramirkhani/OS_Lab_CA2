#include "types.h"
#include "x86.h"
#include "defs.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"

static int find_index_maximum(int *counts, int num) {
    int maximum = 0;
    int index_max = 0;
    for (int i = 1; i < num; i++) {
        //cprintf("%d: %d\n",i , counts[i]);
        if (counts[i] >= maximum) {
            maximum = counts[i];
            index_max = i;
        }
    }
    return index_max;
}

int sys_find_most_caller(void) {
    return find_index_maximum(myproc()->count_calls, sizeof(myproc()->count_calls) / sizeof(myproc()->count_calls[0]));
}