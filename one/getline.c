#include <stdio.h>

const int MAXLINE = 1000;
int mgetline(char line[], int max);
void copy(char into[], char from[]);

void main(){
  char max_line[MAXLINE];
  char current[MAXLINE];
  int csize;
  int msize = 0;
  while ((csize = mgetline(current, MAXLINE)) > 0) { 
    if (csize > msize) {
      msize = csize;
      copy(max_line, current);
    }
  }
  printf("%s", max_line);
}

int mgetline(char line[], int limit) {
  int i, c;
  for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i ++){
    line[i] = c;
  }

  if (c == '\n') { 
    line[i] = c;
    i ++;
  }
  line[i] = '\0';
  return i;
}

void copy(char into[], char from[]) { 
  int i;
  for (i = 0; from[i] != '\0'; i ++)
    into[i] = from[i];
  into[i] = '\0';
}
