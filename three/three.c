#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void expand(char *, char **);
int match_expansion(char *, int, int);
void make_expansion(char*, char *, int, int);
void inspect_hex(char *, int);

int main() {
  char *in = NULL;
  char *out;
  size_t len;
  getline(&in, &len, stdin);
  expand(in, &out);
  printf("%s", out);
  free(in);
  return 0;
}

void make_expansion(char* s, char *b, int i, int j){
  char l = s[i];
  char r = s[i + 2];
  while (l < r)
    b[j++] = l++;
  while (l > r)
    b[j++] = l--;
  b[j] = r;
}

int match_expansion(char *s, int i, int limit){
  if (i + 2 >= limit)
    return 0;
  if (s[i+1] == '-' && s[i] != '-' && s[i+2] != '-')
    return abs(s[i + 2] - s[i]);
  return 0;
}

void expand(char *s1, char **s2) { 
  int i = 0;
  int buf_size = 0;
  int buf_cap = 16;
  char *buf =  malloc(buf_cap);
  int s1_size = strlen(s1);
  while (i <= s1_size) {
    int e_size = match_expansion(s1, i, s1_size);
    // if buffer does not have capacity for the expansion or next char 
    // expand to guarantee capacity
    if (buf_cap < buf_size + e_size + 1){ 
      int nbuf_cap = buf_cap * 2 + e_size + 1;
      char *nbuf = malloc(nbuf_cap);
      strncpy(nbuf, buf, buf_size);
      free(buf);
      buf = nbuf;
      buf_cap = nbuf_cap;
    }
    if (e_size > 0){
      make_expansion(s1, buf, i, buf_size);
      buf_size += e_size + 1;
      if (match_expansion(s1, i+2, s1_size) > 0)
        i += 2;
      else
        i += 3;
    } else { 
      buf[buf_size++] = s1[i++];
    }
  }
  *s2 = buf;
}

void inspect_hex(char *b, int s){
  for (int i = 0; i < s; i ++){
    printf("%x ", b[i]);
  }
  printf("\n");
}