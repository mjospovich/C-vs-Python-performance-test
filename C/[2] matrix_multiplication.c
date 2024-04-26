#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 1000

void matrix_multiplication() {
    printf("gotta go\n");
    FILE *fp1, *fp2;
    int matrix1[MATRIX_SIZE][MATRIX_SIZE], matrix2[MATRIX_SIZE][MATRIX_SIZE], result[MATRIX_SIZE][MATRIX_SIZE];
    int i, j, k;
    char ch;

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

    // print value of fp1 and fp2
    //printf("fp1: %c\n", fgetc(fp1));
    

    // Read matrix1 from file
    for (i = 0; i < MATRIX_SIZE; i++) {
        j = 0;
        while ((ch = fgetc(fp1)) != '\n' && ch != EOF) {
            // ungetc(ch, fp1);
            printf("ch: %c\n", ch);
            //fscanf(fp1, "%d,", &matrix1[i][j++]);
        }
    }

    // // Read matrix2 from file
    // for (i = 0; i < MATRIX_SIZE; i++) {
    //     j = 0;
    //     while ((ch = fgetc(fp2)) != '\n' && ch != EOF) {
    //         ungetc(ch, fp2);
    //         fscanf(fp2, "%d,", &matrix2[i][j++]);
    //     }
    // }

    // // Perform matrix multiplication
    // for (i = 0; i < MATRIX_SIZE; i++) {
    //     for (j = 0; j < MATRIX_SIZE; j++) {
    //         result[i][j] = 0;
    //         for (k = 0; k < MATRIX_SIZE; k++) {
    //             result[i][j] += matrix1[i][k] * matrix2[k][j];
    //         }
    //     }
    // }

    // Close the files
    fclose(fp1);
    fclose(fp2);
}

int main() {
    matrix_multiplication();
    return 0;
}