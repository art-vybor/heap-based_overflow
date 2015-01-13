#include <linux/mutex.h>
#include <stdio.h>
int main() {
    printf("mutex_t%d\n", sizeof(mutex_t));
}