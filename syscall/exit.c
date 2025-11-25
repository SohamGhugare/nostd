typedef unsigned long long int uint64;

#define SYS_exit 93

void exit(int code) {
    asm volatile (
        "mov x8, %0\n"
        "mov x0, %1\n"
        "svc #0"
        : : "r" ((uint64) SYS_exit), "r" ((uint64) code)
        : "x0", "x8", "memory"
    );
}