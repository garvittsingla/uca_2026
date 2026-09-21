#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Global variable to count signal triggers
volatile sig_atomic_t signal_count = 0;

void handle_sigint(int sig) {
    if(sig == SIGINT){
        signal_count++;
        if(signal_count >= 3){
             exit(0);
        }
    }
}

int main() {
    signal(SIGINT,handle_sigint);
    printf("Program running (PID: %d). Try pressing Ctrl+C...\n", getpid());

    while (1) {
        sleep(1);
    }

    return 0;
}