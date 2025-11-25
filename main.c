#include "syscall/write.h"
#include "syscall/exit.h"

void _start() {
    char* buf = "Hello World\n";
    
    write(1, buf, 12);

    exit(0);
}