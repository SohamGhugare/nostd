#ifndef _WRITE_H_
#define _WRITE_H_

#define SYS_write 64
#define SYS_exit 93

typedef unsigned long long int uint64;

int write(int fd, const char *buf, int count);

#endif // _WRITE_H_