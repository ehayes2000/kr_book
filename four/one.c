#include <string.h>
#include <stdio.h>

int strindex(char *, char);

int main(int argc, char* argv[]) {   
  printf("Input [%s]\n", argv[1]);
  int i = strindex(argv[1], argv[2][0]);
  printf("Rightmost %c at %d\n", argv[2][0], i);
}

int strindex(char* s, char t){
  int s_size = strlen(s);
  for (int i = s_size - 1; i >= 0; i --){
    if (s[i] == t)
      return i;
  }
  return -1;
}
