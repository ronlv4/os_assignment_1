#include <stdio.h>
#include "proc.h"

int main(int argc, char *argv[])
{
    long long max_value = (1ull << 63) - 1ull;
    printf("The maximum value of long long is: %llu\n", max_value);
    return 0;
}