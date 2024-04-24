#include <stdio.h>
#include <ctype.h>
#include "time_mem_measure.c"

#define MAX_CHARS 256
#define FILE_PATH "C:/GitHub/C-vs-Python-performance-test/assets/sample_text.txt"


int count_letters(void) {
    FILE *fp;
    char text[2048];  // Adjust buffer size as needed
    int char_counts[MAX_CHARS] = {0};

    // Open .txt for reading
    fp = fopen(FILE_PATH, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read text into buffer (handle potential errors)
    while (fgets(text, sizeof(text), fp) != NULL) {
        for (char *c = text; *c != '\0'; c++) {
            if (isalnum(*c)) { 
                char_counts[*c]++;  
            }
        }
    }


    fclose(fp);
    return 0;
}


int main() {
    
    print_time_and_memory(count_letters, 1);

  return 0;
}