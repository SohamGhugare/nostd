#include "write.h"

int write(int fd, const char *buf, int count) {
    uint64 ret;

    // write syscall
    asm volatile (
        "mov x0, %2\n"
        "mov x1, %3\n"
        "mov x2, %4\n"
        "mov x8, %1\n"
        "svc #0"
        : "=r" (ret)
        : "r" ((uint64) SYS_write),
          "r" ((uint64) fd),
          "r" ((uint64) buf),
          "r" ((uint64) count)
        : "x0", "x1", "x2", "x8", "memory"
    );

    return (int) ret;
}