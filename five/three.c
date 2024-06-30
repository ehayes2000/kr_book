#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void mstrcat(char *, char*);

int main(int argc, char * argv[]) {     
  int s = strlen(argv[1]) + strlen(argv[2]);
  char* buf = malloc(s + 1);
  strcat(buf, argv[1]);
  printf("%s\n", buf);
  strcat(buf, argv[2]);
  printf("%s\n", buf);

}

void mstrcat(char *a, char* b){
  a += strlen(a);
  while (*b != '\0')
    *a++ = *b++;
  *a = '\0';
}
