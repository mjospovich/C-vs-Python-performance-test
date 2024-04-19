#include <stdio.h>
#include "time_mem_measure.c"

void function() {
    int i = 0;
    int j = 0;

    for (i = 0; i < 10000000; i++) {
        j = i;
    }

}


int main() {
    
    print_time_and_memory(function, 1);

  return 0;
}