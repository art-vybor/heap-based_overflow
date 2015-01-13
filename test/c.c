#include <stdio.h>
#define BUFSIZE 56
int main(int argc, char **argv){
    char *buf1, *buf2;

    if(argc == 1) {
        printf("\nUsage: %s [string].\n",argv[0]);
        return(0);
    }

    buf1 = (char *) malloc(BUFSIZE);
    buf2 = (char *) malloc(BUFSIZE);

    strcpy(buf2,"AAAAAAAAAAAAAAAA");
    strcpy(buf1, argv);

    printf("\n%s\n", buf1);

    free(buf2);
    free(buf1);

    return(0);

}
