#include <stdio.h>
#define MAXLINE 100

void reverse(char[], int);
int mgetline(char[]);

void main() { 
  char c[MAXLINE];
  int size;
  while ((size = mgetline(c)) > 0){
    reverse(c, size);
    printf("%s", c);
  }
}

int mgetline(char c[]) {  
  int i, n;
  for (i = 0; i < MAXLINE && (n = getchar()) != EOF && n != '\n'; i++){
    c[i] = n;
  }
  if (n == '\n')
    c[i++] = '\n';
  c[i] = '\0';
  return i;
}

void reverse(char s[], int len) {
  int l = 0;
  int r = len - 1;
  char tmp;
  while (l < r) { 
    tmp = s[l];
    s[l] = s[r];
    s[r] = tmp;
    l ++;
    r --;
  }
}