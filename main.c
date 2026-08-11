#include <stdio.h>

int main() {
  int x = 128;
  char *ptr = (char *)&x;
  printf("%d\n", ptr);
  printf("%d\n", *ptr);
}
