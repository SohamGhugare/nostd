void _start() {
    char* buf = "Hello World\n";
    
    asm volatile (
        "mov x0, #1\n"
        "mov x1, %0\n"
        "mov x2, #12\n"
        "mov x8, #64\n"
        "svc #0"
        :
        : "r"(buf)
        : "x0", "x1", "x2", "x8", "memory"
    );

    asm volatile (
        "mov x0, #0\n"
        "mov x8, #93\n"
        "svc #0"
        : :
        : "x0", "x8", "memory"
    );
}