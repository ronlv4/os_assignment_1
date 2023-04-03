#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char **argv)
{
    static char *policy_message[] = 
    {
        [0] "0 - Round Robin Scheduler",
        [1] "1 - Completely Fair Scheduler",
        [2] "2 - Priority Based Scheduler"
    };

    fprintf(1, "Policy: %s\n", policy_message[get_policy()]);
    exit(0, "");
}
