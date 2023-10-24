#include <stdio.h>

int is_little() {
    int p = 1;
    unsigned char *p1 = (unsigned char *)&p;
    if (*p1 == 1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    if (is_little() == 1) {
        printf("little-endian.\n");
    } else {
        printf("big-endian.\n");
    }
    return 0;
}

