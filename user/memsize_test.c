#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    printf("current process has %d bytes of memory\n", memsize());
    printf("allocating 20k bytes\n");
    void* space = malloc(20000l);
    printf("process is now using %d bytes of memory\n", memsize());
    printf("freeing allocated space\n");
    free(space);
    printf("space was freed\n");
    printf("process is rnow using %d bytes of memory\n", memsize());
    return 0;
}