#include <stdio.h>
#include <string.h>

int mstrend(char *, char *);

int main(int argc, char* argv[]){
  char *a = "onetwothree";
  char *b = "three";
  char *c = "zhree";
  if (mstrend(a, b)){
    printf("%s, ends with %s\n", a, b);
  }
  if (mstrend(a, c)){
    printf("%s, ends with %s\n", a, c);
  }
}

int mstrend(char* s, char*t){
  int ssize, tsize;
  ssize = strlen(s);
  tsize = strlen(t);
  if (ssize < tsize)
    return 0;
  t += tsize - 1;
  s += ssize - 1;
  for (int i = 0; i < tsize; i ++){
    if (*t != *s)
      return 0;
    t--;
    s--;
  }
  return 1;
}