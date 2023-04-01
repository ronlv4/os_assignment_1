#include "kernel/types.h"
// #include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        return exit(0, "Goodbye World xv6");
    }

    int exit_code = atoi(argv[1]);

    return exit(exit_code, "Goodbye World xv6");
}