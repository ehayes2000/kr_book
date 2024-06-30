
void strncpy(char* a, char* b, int n){
  for (int i = 0; i < n; i ++)
    *a++ = *b++;
}

void strncat(char* a, char* b, int n){
  while (*a != '\0')  
    a++;
  for (int i = 0; i < n; i ++)
    *a++ = *b++;
}

int strncmp(char *a, char* b, int n){
  for (int i = 0; i < n; i ++){
    if (a[i] != b[i])
      return 0;
  }
  return 1;
}