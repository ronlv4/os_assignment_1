#include <stdio.h>
#include "proc.h"

int main(int argc, char *argv[])
{
    static int priority_to_decay_factor[] = {
    [1] 75,
    [2] 100,
    [3] 125
  };
  
    long long max_value = (1ull << 63) - 1ull;
    int max_int = (1u << 31) - 1u;
    printf("The maximum value of long long is: %llu\n", max_value);
    printf("The maximum value of int is: %d\n", max_int);
    printf("test map: 1- %d, 2 - %d, 3 - %d\n", priority_to_decay_factor[1], priority_to_decay_factor[2], priority_to_decay_factor[3]);
    return 0;
}