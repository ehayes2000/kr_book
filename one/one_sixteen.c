#include <stdlib.h>
#include <stdio.h>

void hex_inspect(char *, int);
int mgetline(char **line);
void ncopy(char *into, char *from, int n);

void main(){
  char *max_line = malloc(1);
  char *current;
  int csize;
  int msize = 0;
  while ((csize = mgetline(&current)) > 0) { 
    if (csize > msize) {
      msize = csize;
      free(max_line);
      max_line = current;
    } else { 
      free(current);
    }
  }
  printf("Max line size: %d\n", msize);
  printf("%s", max_line);
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
  if (i == 0)
    return 0;
  if (c == "\n")
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


