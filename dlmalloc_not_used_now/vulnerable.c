#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void print(char *label, char *p, int from, int to) {
    int i;
    printf("%s(%p): ", label, p);
    for (i = from; i<to; i++) {
        printf("%02X ", (unsigned char)p[i]);
    }
    printf("\n");
}

int main( int argc, char * argv[] )
{
        char * first, * second;

/*[1]*/ first = malloc( 666 );
/*[2]*/ second = malloc( 12 );
        print("first", first-16, 0, 100);
        print("second", second-16, 0, 32);
        print("argv[1]: ", argv[1], 0, strlen(argv[1]));
/*[3]*/ strcpy( first, argv[1] );
        //first[-8]=first[-8] & ~0x1;
        //printf("nextchunk_size: %d\n", (size_t)second[-8]);
        second[-8]=second[-8] | 0x1;
        print("first", first-16, 0, 100);
        print("second", second-16, 0, 32);
/*[4]*/ free( first );
        puts("first cleared");
/*[5]*/ free( second );
        puts("second cleared");
/*[6]*/ return( 0 );
}