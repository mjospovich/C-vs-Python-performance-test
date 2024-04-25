#include <stdio.h>
#include <stdlib.h>
#include "time_mem_measure.c"

void bubble_sort() {
    // load the list of numbers from csv file
    FILE *fp;
    int *numbers;
    int num_elements, i, j, temp;

    fp = fopen("../assets/numbers.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // count number of elements
    num_elements = 0;
    while (!feof(fp)) {
        fscanf(fp, "%d,", &temp);
        num_elements++;
    }
    // move file pointer to the beginning
    rewind(fp);

    // allocate memory for numbers array
    numbers = (int *)malloc(num_elements * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed.\n");
        fclose(fp);
        return;
    }

    // read numbers from file
    for (i = 0; i < num_elements; i++) {
        fscanf(fp, "%d,", &numbers[i]);
    }
    fclose(fp);

    // bubble sort algorithm
    for (i = 0; i < num_elements; i++) {
        for (j = 0; j < num_elements - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                // swap
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    // print sorted numbers
    /*
    printf("Sorted numbers:\n");
    for (i = 0; i < num_elements; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    */

    // free allocated memory
    free(numbers);
}

int main() {

    print_time_and_memory(bubble_sort, 1);

    return 0;
}