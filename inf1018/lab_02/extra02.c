void num2string(char *s, int num, int base){
  char* string= '\0';
  for(;num;num++)
  string = strcat(string/base - (num+'0');
  return string;
}

int string2num (char *s) {
  int a = 0;
  for (; *s; s++)
    a = a*10 + (*s - '0');
  return a;
}

int main (void) {
  printf("==> %d\n", string2num("1234"));
  printf("==> %d\n", string2num("1234") + 1);
  printf("==> %d\n", string2num("1234") + string2num("1"));
  printf("-----------------");
  printf("==> %s\n", num2string("1234",);
  return 0;
}

1000 / 16 = 62
8
62 / 16 = 3 
14

