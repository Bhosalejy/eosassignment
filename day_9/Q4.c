#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t ret1, ret2, ret3, ret4, ret5, ret6;
    int s1, s2, s3, s4, s5, s6;

    ret1 = fork();

    if (ret1 == 0) {
        execlp("gcc", "gcc", "-c", "circle.c", NULL);
        exit(0);
    }

    ret2 = fork();

    if (ret2 == 0) {
        execlp("gcc", "gcc", "-c", "square.c", NULL);
        exit(0);
    }

    ret3 = fork();

    if (ret3 == 0) {
        execlp("gcc", "gcc", "-c", "rectangle.c", NULL);
        exit(0);
    }

    ret4 = fork();

    if (ret4 == 0) {
        execlp("gcc", "gcc", "-c", "main.c", NULL);
        exit(0);
    }

    waitpid(ret1, &s1, 0);
    waitpid(ret2, &s2, 0);
    waitpid(ret3, &s3, 0);
    waitpid(ret4, &s4, 0);

    if (WIFEXITED(s1) && WIFEXITED(s2) && WIFEXITED(s3) && WIFEXITED(s4) &&
        (WEXITSTATUS(s1) == 0) && (WEXITSTATUS(s2) == 0) && (WEXITSTATUS(s3) == 0) && (WEXITSTATUS(s4) == 0)) {
        ret5 = fork();

        if (ret5 == 0) {
            execlp("gcc", "gcc", "-o", "output", "circle.o", "square.o", "rectangle.o", "main.o", NULL);
            exit(0);
        }

        waitpid(ret5, &s5, 0);

        if (WIFEXITED(s5) && (WEXITSTATUS(s5) == 0)) {
            ret6 = fork();

         if (ret6 == 0) {
                execl("./output", NULL);
                exit(0);
            }

            waitpid(ret6, &s6, 0);

            if (WIFEXITED(s6)) {
                printf("Child process returned with exit status: %d", WEXITSTATUS(s6));
            }
        }
    }

    return 0;
}

   
