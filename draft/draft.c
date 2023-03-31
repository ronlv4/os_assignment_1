#include <stdio.h>
#include "proc.h"

int main(int argc, char *argv[])
{
    struct proc * p = malloc(sizeof(struct proc));
    int s;
    printf("hello: %d\n", p->accumulator);
    return 0;
}