#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main() {
    pid_t pid[4];

    // Create 4 processes
    for(int i = 0; i < 4; i++) {
        pid[i] = fork();

        if(pid[i] == 0) {
            // This is the child process
            std::cout << "Child process " << i << " with PID " << getpid() << " started.\n";
            while(true); // Keep the process running
        }
    }

    // Wait for a while
    sleep(5);

    // Kill the processes and wait for them to finish
    for(int i = 0; i < 4; i++) {
        kill(pid[i], SIGTERM);
        waitpid(pid[i], NULL, 0);
        std::cout << "Child process " << i << " with PID " << pid[i] << " terminated.\n";
    }

    return 0;
}
