#include "syscalls/write.h"

void _start() {
    char* buf = "Hello World\n";
    
    write(1, buf, 12);

    // exit syscall
    asm volatile (
        "mov x0, #0\n"
        "mov x8, %0\n"
        "svc #0"
        : 
        : "r" ((uint64) SYS_exit) 
        : "x0", "x8", "memory"
    );
}