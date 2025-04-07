#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Terjadi kesalahan saat membuat proses anak
        fprintf(stderr, "Fork gagal\n");
        return 1;
    } else if (pid == 0) {
        // Ini adalah proses anak
        printf("Ini adalah proses anak dengan PID: %d\n", getpid());
    } else {
        // Ini adalah proses induk
        printf("Ini adalah proses induk dengan PID: %d dan anak dengan PID: %d\n", getpid(), pid);
    }

    return 0;
}
