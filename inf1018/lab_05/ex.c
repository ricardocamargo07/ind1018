#include <stdio.h>

void dump(void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

struct X1 {
  char c1;
  int i;
  char c2;
};

int main() {
  printf("Tamanho da estrutura X: %zu bytes\n", sizeof(struct X));
  dump(&X1, sizeof(struct X1));
  return 0;
}
