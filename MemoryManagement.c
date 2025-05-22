// Unit-III Memory Management: absolute and relative code, address translation, memory management techniques- partition, paging, segmentation, virtual memory. Static and dynamic memory management.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ------------------ Absolute vs Relative Code ------------------
void absolute_vs_relative() {
    printf("\n[ABSOLUTE VS RELATIVE CODE]\n");
    int absolute_address = 1000;
    int relative_address = 200;
    int base_address = 800;

    printf("Absolute Address: %d\n", absolute_address);
    printf("Relative Address: %d + Base: %d = Physical Address: %d\n",
           relative_address, base_address, relative_address + base_address);
}

// ------------------ Address Translation ------------------
void address_translation() {
    printf("\n[ADDRESS TRANSLATION - Logical to Physical]\n");
    int page_size = 1024;
    int logical_address = 2050;
    int page_number = logical_address / page_size;
    int offset = logical_address % page_size;
    int frame_number = 5; // Example frame number
    int physical_address = frame_number * page_size + offset;

    printf("Logical Address: %d → Page: %d, Offset: %d\n", logical_address, page_number, offset);
    printf("Physical Address (using Frame %d): %d\n", frame_number, physical_address);
}

// ------------------ Partitioning ------------------
void partitioning() {
    printf("\n[MEMORY PARTITIONING]\n");

    int memory = 1000;
    int fixed_partition = 250;
    int process_sizes[] = {100, 180, 230, 300};
    int num = sizeof(process_sizes) / sizeof(process_sizes[0]);

    printf("Fixed Partition Size: %d\n", fixed_partition);
    for (int i = 0; i < num; i++) {
        if (process_sizes[i] <= fixed_partition)
            printf("Process %d allocated in fixed partition.\n", i+1);
        else
            printf("Process %d too large for fixed partition.\n", i+1);
    }
}

// ------------------ Paging ------------------
void paging() {
    printf("\n[PAGING SIMULATION]\n");

    int logical_address = 219;   // Logical address
    int page_size = 100;
    int page_table[] = {5, 2, 8, 1}; // Page -> Frame mapping

    int page_number = logical_address / page_size;
    int offset = logical_address % page_size;
    int frame_number = page_table[page_number];
    int physical_address = frame_number * page_size + offset;

    printf("Logical Address: %d → Page: %d, Offset: %d\n", logical_address, page_number, offset);
    printf("Mapped to Frame: %d → Physical Address: %d\n", frame_number, physical_address);
}

// ------------------ Segmentation ------------------
void segmentation() {
    printf("\n[SEGMENTATION SIMULATION]\n");

    int segment_table[] = {1000, 2000, 3000}; // Base addresses
    int segment = 1;
    int offset = 50;

    int physical_address = segment_table[segment] + offset;
    printf("Segment: %d, Offset: %d → Physical Address: %d\n", segment, offset, physical_address);
}

// ------------------ Virtual Memory (Simplified) ------------------
void virtual_memory_simulation() {
    printf("\n[VIRTUAL MEMORY SIMULATION - Page Fault Example]\n");

    int page_table[4] = {-1, 3, -1, 5}; // -1 indicates page fault
    int logical_page = 0;

    if (page_table[logical_page] == -1) {
        printf("Page %d not in memory → PAGE FAULT!\n", logical_page);
    } else {
        printf("Page %d mapped to Frame %d\n", logical_page, page_table[logical_page]);
    }
}

// ------------------ Static vs Dynamic Memory ------------------
void memory_allocation() {
    printf("\n[STATIC VS DYNAMIC MEMORY ALLOCATION]\n");

    // Static allocation
    int static_array[5] = {1, 2, 3, 4, 5};
    printf("Static Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", static_array[i]);
    }

    // Dynamic allocation
    int* dynamic_array = (int*) malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) dynamic_array[i] = i + 10;
    printf("\nDynamic Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", dynamic_array[i]);
    }
    free(dynamic_array);
}

int main() {
    printf("=== OPERATING SYSTEMS UNIT III DEMO ===\n");

    absolute_vs_relative();
    address_translation();
    partitioning();
    paging();
    segmentation();
    virtual_memory_simulation();
    memory_allocation();

    return 0;
}
