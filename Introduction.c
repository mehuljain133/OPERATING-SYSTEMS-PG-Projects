// Unit-I Introduction: Operating System as a resource manager, operating systems services, system calls, operating system classifications, operating systems architectures

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Simulate Resource Manager (e.g., Memory)
void resource_manager() {
    printf("Operating System: Managing resources (e.g., memory, CPU).\n");
    int memory_allocated = 1024; // Simulated memory
    printf("Allocated %d KB memory to process.\n", memory_allocated);
}

// Simulate System Call: fork(), exec(), wait()
void system_call_demo() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process: PID = %d\n", getpid());
        char *args[] = {"/bin/echo", "Child process executed using exec().", NULL};
        execvp(args[0], args);
        // execvp replaces the current process, so code below doesn't run if exec is successful
        perror("exec failed");
        exit(1);
    } else if (pid > 0) {
        // Parent process
        wait(NULL); // Wait for child to finish
        printf("Parent process: Child has completed.\n");
    } else {
        perror("fork failed");
    }
}

// Simulate OS Classifications
void os_classification() {
    printf("\nOperating System Classifications:\n");
    printf("1. Batch OS\n2. Time-Sharing OS\n3. Distributed OS\n4. Real-Time OS\n5. Network OS\n");
}

// Simulate Modular Architecture
void os_architecture() {
    printf("\nOperating System Architecture (Simple Simulation):\n");
    printf("1. Kernel Layer: Process scheduling, Memory management\n");
    printf("2. System Call Interface: User ↔ Kernel communication\n");
    printf("3. User Applications: Compilers, Shell, etc.\n");
}

int main() {
    printf("=== OPERATING SYSTEMS UNIT I DEMO ===\n\n");

    resource_manager();       // Resource management demo
    system_call_demo();       // System call demo
    os_classification();      // OS classification demo
    os_architecture();        // OS architecture demo

    return 0;
}
