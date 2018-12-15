/* ls df ps pwd */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    char* commands[4][2] = { 
        { "ls", 0 }
        , { "df", 0 }
        , { "ps", 0 }
        , { "pwd", 0 }
    };

    for (int i = 0; i < 4; i++) {
        int pid;
        if ((pid = fork()) == 0) {
            execvp(commands[i][0], commands[i]);
        }
    }
    for (int i = 0; i < 4; i++) wait(0);
    printf("\ndone\n");
}