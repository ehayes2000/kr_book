#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

void hex_inspect(char *, int);
int mgetline(char **line);
void ncopy(char *into, char *from, int n);

void main(){
  char *current;
  int csize;
  int i = 0;
  while ((csize = mgetline(&current)) > 0) { 
    i ++;
    printf("line %d, %d characters\n", i, csize);
    printf("%s", current);
    free(current);
  }
}

int mgetline(char **line){
  int bufsize = 5;
  char *buf = malloc(bufsize);
  int i, c;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; i ++){
    if (i >= bufsize){
      bufsize *= 2; 
      char *new_buf = malloc(bufsize);
      ncopy(new_buf, buf, i);
      free(buf);
      buf = new_buf;  
    }
    buf[i] = c;
  }
  int is_newline = c == '\n';
  if (i <= 0)
    return 0;
  for (int j = i - 1; isspace(buf[j]); j --)
    i --;
  if (is_newline)
    buf[i++] = '\n';
  buf[i] = '\0';
  *line = buf;
  return i;
}

void hex_inspect(char *c, int n) { 
  for (int i = 0; i < n; i ++)
    printf("%x ", c[i]);
  printf("\n");
}

void ncopy(char *into, char *from , int n){
  for (int i = 0; i < n; i ++) 
    into[i] = from[i]; 
}


