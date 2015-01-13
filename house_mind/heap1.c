/*
 * K-sPecial's vulnerable program
 */

#include <stdio.h>
#include <stdlib.h>

void print(char *label, char *p, int from, int to) {
    int i;
    printf("%s(%p): ", label, p);
    for (i = from; i<to; i++) {
        printf("%02X", (unsigned char)p[i]);
        if ((i-from)%8 == 7)
          printf("|");
        else
          printf(" ");
    }
    printf("\n");
}

int main (void) {
    char *ptr  = malloc(1024);        /* First allocated chunk */
    char *ptr2;                       /* Second chunk          */
    /* ptr & ~(HEAP_MAX_SIZE-1) = 0x08000000 */
    
    int heap = (int)ptr & 0xFFF00000;
    _Bool found = 0;

    printf("ptr found at %p\n", ptr);  /* Print address of first chunk */

    // i == 2 because this is my second chunk to allocate
    for (int i = 2; i < 1024; i++) {
        /* Allocate chunks up to 0x08100000 */
        if (!found && (((int)(ptr2 = malloc(1024)) & 0xFFF00000) == (heap + 0x100000))) {
          printf("good heap allignment found on malloc() %i (%p)\n", i, ptr2);
          found = 1; /* Go out */
          break;
        }

    }

    malloc(1024); /* Request another chunk: (ptr2 != av->top) */
    /* Incorrect input: 1048576 bytes */
    print("ptr before fread", ptr-16, 0, 100);
    fread (ptr, 1024 * 1024, 1, stdin); 
    print("ptr readed", ptr-16, 0, 100);
    free(ptr);   /* Free first chunk  */
    print("ptr cleared", ptr-16, 0, 100);
    free(ptr2);  /* The House of Mind */
    return(0);   /* Bye */
}
