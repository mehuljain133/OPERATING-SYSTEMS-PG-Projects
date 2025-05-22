// Unit-IV Device Management: Goals of I/O software, Design of device drivers- interrupt service routines, upper half of kernel software, lower half of kernel software.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// ------------------ Goals of I/O Software ------------------
void io_software_goals() {
    printf("\n[GOALS OF I/O SOFTWARE]\n");
    printf("1. Device Independence\n");
    printf("2. Uniform Naming\n");
    printf("3. Error Handling\n");
    printf("4. Buffering\n");
    printf("5. Scheduling\n");
    printf("6. Device Protection\n");
}

// ------------------ Lower Half of Device Driver ------------------
void* lower_half_handler(void* device_data) {
    printf("[LOWER HALF] Handling raw hardware I/O from device: %s\n", (char*)device_data);
    sleep(1); // Simulate device access
    printf("[LOWER HALF] Completed hardware operations.\n");
    return NULL;
}

// ------------------ Interrupt Service Routine (ISR) ------------------
void interrupt_service_routine(char* device_data) {
    printf("[ISR] Interrupt received from device: %s\n", device_data);

    // Simulate deferring heavy work to lower half
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, lower_half_handler, (void*)device_data);
    pthread_detach(thread_id);
    printf("[ISR] Minimal work done in ISR, passed to lower half.\n");
}

// ------------------ Upper Half of Device Driver ------------------
void upper_half_handler(char* device_name) {
    printf("[UPPER HALF] Initiating read from device: %s\n", device_name);

    // Simulate request -> hardware interrupt
    printf("[UPPER HALF] Sending request to hardware...\n");
    sleep(1); // Simulating hardware delay

    // Trigger ISR as if hardware interrupt occurred
    interrupt_service_routine(device_name);

    // Continue with other upper-half tasks
    printf("[UPPER HALF] Waiting for lower half to complete...\n");
    sleep(2); // Simulating wait
    printf("[UPPER HALF] Received data from device.\n");
}

int main() {
    printf("=== OPERATING SYSTEMS UNIT IV DEMO ===\n");

    io_software_goals();

    printf("\n[DEVICE DRIVER SIMULATION]\n");
    upper_half_handler("Keyboard");

    printf("\n[SIMULATION COMPLETE]\n");
    return 0;
}
