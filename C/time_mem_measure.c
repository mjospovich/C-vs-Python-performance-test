#pragma once

#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <psapi.h>

#define MILLISEC 1000

// Function to get current memory usage in bytes
SIZE_T get_memory_usage() {
    PROCESS_MEMORY_COUNTERS pmc;
    if (!GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc))) {
        printf("Error getting memory usage\n");
        return -1; // Handle error appropriately
    }
    return pmc.WorkingSetSize;
}

// Function to measure time and memory usage
void measure_time_and_memory(void (function)(), int repetitions, double* time_taken, long* memory_used) {
    LARGE_INTEGER start_time, end_time, freq;

    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start_time);

    long start_memory = get_memory_usage();

    for (int i = 0; i < repetitions; i++) {
        printf("REPETITION %d/%d ", i + 1, repetitions);
        function();
        printf("DONE\n");
    }

    QueryPerformanceCounter(&end_time);
    long end_memory = get_memory_usage();

    *time_taken = ((double)(end_time.QuadPart - start_time.QuadPart)) / freq.QuadPart * MILLISEC / repetitions;
    *memory_used = (end_memory - start_memory) / 1000 / repetitions;
}

// Function to print time and memory usage
void print_time_and_memory(void (function)(), int repetitions) {
    double time;
    long memory_used;
    measure_time_and_memory(function, repetitions, &time, &memory_used);
    printf("Time taken: %.2f ms\n", time);
    printf("Memory used: %ld KB\n", memory_used);
}

