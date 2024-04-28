#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time_mem_measure.c"

#define MATRIX_SIZE 1000
#define MAX_CHAR 5000

void matrix_multiplication() {
    FILE *fp1, *fp2;
    int i, j, k;
    char ch;
    char row[MAX_CHAR];

    int **matrix1 = (int**)malloc(MATRIX_SIZE * sizeof(int*));
    for(i = 0; i < MATRIX_SIZE; i++)
        matrix1[i] = (int*)malloc(MATRIX_SIZE * sizeof(int));

    int **matrix2 = (int**)malloc(MATRIX_SIZE * sizeof(int*));
    for(i = 0; i < MATRIX_SIZE; i++)
        matrix2[i] = (int*)malloc(MATRIX_SIZE * sizeof(int));

    int **result = (int**)malloc(MATRIX_SIZE * sizeof(int*));
    for(i = 0; i < MATRIX_SIZE; i++)
        result[i] = (int*)malloc(MATRIX_SIZE * sizeof(int));

    // Open matrix1 file
    fp1 = fopen("../assets/matrix1.csv", "r");
    if (fp1 == NULL) {
        printf("Error opening matrix1 file.\n");
        return;
    }

    // Open matrix2 file
    fp2 = fopen("../assets/matrix2.csv", "r");
    if (fp2 == NULL) {
        printf("Error opening matrix2 file.\n");
        fclose(fp1);
        return;
    }
    //printf("Files opened.\n");
    // Read matrix1 from file
    for (i = 0; i < MATRIX_SIZE; i++) {
        j = 0;
        
        if (feof(fp1) != 1)
        {
            fgets(row, MAX_CHAR, fp1);

            // split row by comma
            char *token = strtok(row, ",");
            while (token != NULL)
            {
                matrix1[0][0] = 0;
                token = strtok(NULL, ",");
                j++;
            }
        }
        strcpy(row, "");
    }
    //printf("Matrix 1 read.\n");

    // Read matrix2 from file
    for (i = 0; i < MATRIX_SIZE; i++) {
        j = 0;
        
        if (feof(fp2) != 1)
        {
            fgets(row, MAX_CHAR, fp2);

            // split row by comma
            char *token = strtok(row, ",");
            while (token != NULL)
            {
                matrix2[i][j] = atoi(token);
                token = strtok(NULL, ",");
                j++;
            }
        }
        strcpy(row, "");
    }
    //printf("Matrix 2 read.\n");
    

    //Perform matrix multiplication
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            result[i][j] = 0;
            for (k = 0; k < MATRIX_SIZE; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Close the files
    fclose(fp1);
    fclose(fp2);

    // Free the memory
    for(i = 0; i < MATRIX_SIZE; i++)
        free(matrix1[i]);
    free(matrix1);

    for(i = 0; i < MATRIX_SIZE; i++)
        free(matrix2[i]);
    free(matrix2);

    for(i = 0; i < MATRIX_SIZE; i++)
        free(result[i]);
    free(result);

    //printf("Matrix multiplication done.\n");
}

int main() {
    //matrix_multiplication();
    print_time_and_memory(matrix_multiplication, 1);
    return 0;
}