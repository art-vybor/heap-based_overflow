#include <stdio.h>
#include <string.h>
int function(const char *argument);

int main(int argc, char **argv)
{
    static char buf[128];
    static int (*funcptr)(const char *argument);
    if (argc <= 2)
    {
        fprintf(stderr, "Usage: %s [buffer] [function argument]\n", argv[0]);
        exit(1);
    }

    funcptr = (int (*)(const char *argument))function;
    memset(buf, 0, sizeof(buf));
    strncpy(buf, argv, strlen(argv));
    (void)(*funcptr)(argv);
    return 0;
}


int function(const char *argument)
{
    //printf("\nArgument is: %s\n", argument);
    return 0;
}