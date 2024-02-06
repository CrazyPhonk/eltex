#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void signal_handler(int signal){
    printf("%d\n", signal);
    if (signal == SIGINT){
        printf("SIGINT\n");
    }
    else if (signal ==SIGTSTP){
        printf("SIGTSTP\n");
    }
    else if (signal == SIGQUIT){
        printf("SIGQUIT\n");
    }
    else if (signal == SIGKILL){
    printf("SIGKILL\n");
    }
    else if (signal == SIGCONT){
        printf("SIGCONT\n");
    }
}


int main (int argc, char * argv[]){
    signal(SIGTSTP, signal_handler);
    signal(SIGINT, signal_handler);
    signal(SIGQUIT, signal_handler);
    signal(SIGKILL, signal_handler);
    signal(SIGCONT, signal_handler);
    while(1){
        sleep(1);
    }

    return 0;
}