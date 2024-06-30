#include <stdio.h>
#define swap(T, A, B) {T TMP=A; A=B; B=TMP;}

int main() { 
  int a = 1;
  int b = 9;
  printf("a = %d, b = %d\n", a, b);
  swap(int, a, b);
  printf("a = %d, b = %d\n", a, b);
}