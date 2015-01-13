#include <stdio.h>
#include <string.h>
#include <malloc.h>

main()
{
    unsigned long difference;
    char *buffer1,*buffer2;

    buffer1 = (char *)malloc(1);

    buffer2 = (char *)malloc(1);
    difference = (unsigned long)buffer2 - (unsigned long)buffer1;
    memset(buffer2, 'A', 1);
    memset(buffer1, 'B', 1);

    for (int i=-16; i<40; i++) {
      printf("%d: %d(%c)\n", i, buffer1[i], buffer1[i]);
      if (i%8==7 || i%8==-1) {
          printf("--\n");
      }
    }

    printf("%d",sizeof(size_t));
}


