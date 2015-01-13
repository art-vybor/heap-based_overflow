#include <stdio.h>

int main()
{
    long diff;
    static char buf2[16];
    static char *buf1;

    buf1 = buf2;
    diff =  (long)&buf1 -  (long)buf2;
    printf("buf2 = %p & buf1 = %p & diff %d\n",buf2,&buf1,diff);
    printf("BEFORE: buf2 = %p\n",buf2);
    /* An address is 4 long, so we overwrite 4 chars */
    memset(buf1,'A',diff+4);  
    printf("AFTER:  buf2 = %p\n",buf2);

    return 0;
}