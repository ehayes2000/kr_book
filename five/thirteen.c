#include <stdio.h>
#include <stdlib.h>

void tail(int);

int main(int argc, char* argv[]){
  if (argc > 1)
    tail(atoi(argv[1]+1));
  else 
    tail(10);
}

void tail(int n ){ 
  n += 1;
  char **lines = calloc(n, sizeof(char *));
  size_t bs = 0;
  int ri = 0;
  for(;;){
    if (lines[ri % n] != NULL){
      free(lines[ri % n]);
      lines[ri % n] = NULL;
    }
    if (getline(&lines[ri++ % n], &bs, stdin) == EOF)
      break;
  }
  ri = abs(ri - n);
  for (int i = 0; i < n; i ++)
    printf("%s", lines[ri++ % n]);
}