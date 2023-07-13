#include <unistd.h>
#include <fcntl.h>
#include <sys/syscall.h>

#define STDERR_FILENO 2

void print(const char *str) {
    while (*str != '\0') {
        syscall(SYS_write, STDERR_FILENO, str, 1);
        str++;
    }
}

int main() {
    const char *message = "\"and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
    print(message);
    return 1;
}

