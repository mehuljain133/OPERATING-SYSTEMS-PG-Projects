/* Unit-II Processor Management: Process overview, process states and state transition, multiprogramming, multi-tasking, levels of schedulers and scheduling algorithms. Process
Synchronization-Critical section and mutual exclusion problem, classical process synchronization
problems, deadlock prevention. Multithreading. */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// ------------------ Process Overview & States ------------------
void simulate_process_states() {
    printf("\n[PROCESS STATES SIMULATION]\n");
    printf("State: New -> Ready -> Running -> Waiting -> Terminated\n");
    printf("Transitioning process through states...\n");
    sleep(1);
    printf("Process created. State: NEW\n");
    sleep(1);
    printf("Moved to READY queue.\n");
    sleep(1);
    printf("Scheduled by CPU. State: RUNNING\n");
    sleep(1);
    printf("I/O call made. State: WAITING\n");
    sleep(1);
    printf("I/O complete. State: READY\n");
    sleep(1);
    printf("CPU scheduled again. State: RUNNING\n");
    sleep(1);
    printf("Process completed. State: TERMINATED\n");
}

// ------------------ Multiprogramming/Multitasking ------------------
void simulate_multiprogramming() {
    printf("\n[MULTIPROGRAMMING / MULTITASKING SIMULATION]\n");

    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        for (int i = 0; i < 5; i++) {
            printf("Child process running...\n");
            sleep(1);
        }
        exit(0);
    } else {
        // Parent process
        for (int i = 0; i < 5; i++) {
            printf("Parent process running...\n");
            sleep(1);
        }
        wait(NULL);
    }
}

// ------------------ Scheduling (FCFS Simulation) ------------------
void simulate_scheduling() {
    printf("\n[SCHEDULING SIMULATION - FCFS]\n");
    int burst_time[] = {5, 3, 8};
    int n = 3, waiting_time[3] = {0}, turnaround_time[3];

    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
    }

    for (int i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        printf("P%d - Burst: %d, Wait: %d, Turnaround: %d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }
}

// ------------------ Process Synchronization ------------------
pthread_mutex_t lock;
int counter = 0;

void* critical_section(void* arg) {
    pthread_mutex_lock(&lock);
    printf("Thread %ld entering critical section.\n", (long)arg);
    counter++;
    sleep(1);  // Simulate processing
    printf("Thread %ld exiting critical section. Counter = %d\n", (long)arg, counter);
    pthread_mutex_unlock(&lock);
    return NULL;
}

// ------------------ Classical Problem: Producer-Consumer ------------------
#define SIZE 5
int buffer[SIZE], in = 0, out = 0;
sem_t empty, full;
pthread_mutex_t buf_lock;

void* producer(void* arg) {
    for (int i = 0; i < 5; i++) {
        sem_wait(&empty);
        pthread_mutex_lock(&buf_lock);
        buffer[in] = i;
        printf("Producer produced %d at %d\n", i, in);
        in = (in + 1) % SIZE;
        pthread_mutex_unlock(&buf_lock);
        sem_post(&full);
        sleep(1);
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 0; i < 5; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&buf_lock);
        int item = buffer[out];
        printf("Consumer consumed %d at %d\n", item, out);
        out = (out + 1) % SIZE;
        pthread_mutex_unlock(&buf_lock);
        sem_post(&empty);
        sleep(1);
    }
    return NULL;
}

// ------------------ Deadlock Prevention (Resource Ordering) ------------------
void deadlock_prevention() {
    printf("\n[DEADLOCK PREVENTION]\n");
    printf("Using resource ordering to avoid circular wait...\n");
    printf("Processes request resources in order: R1 -> R2\n");
    printf("No circular wait, hence no deadlock!\n");
}

// ------------------ Multithreading ------------------
void simulate_multithreading() {
    printf("\n[MULTITHREADING & CRITICAL SECTION DEMO]\n");
    pthread_t t1, t2;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, critical_section, (void*)1);
    pthread_create(&t2, NULL, critical_section, (void*)2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);
}

int main() {
    printf("=== OPERATING SYSTEMS UNIT II DEMO ===\n");

    simulate_process_states();
    simulate_multiprogramming();
    simulate_scheduling();
    simulate_multithreading();
    deadlock_prevention();

    // Classical Problem Simulation
    printf("\n[PRODUCER-CONSUMER PROBLEM SIMULATION]\n");
    pthread_t prod, cons;
    sem_init(&empty, 0, SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&buf_lock, NULL);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&buf_lock);

    return 0;
}
