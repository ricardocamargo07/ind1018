#include <stdio.h>

int main() {
    signed char sc = -1;
    unsigned int ui = sc;

    printf("Valor de ui: %u\n", ui);

    // Representação binária de ui
    printf("Representação binária de ui: ");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (ui >> i) & 1);
    }
    printf("\n");

    return 0;
}
