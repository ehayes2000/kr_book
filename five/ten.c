#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXARGS 100

double main(int argc, char* argv[]){
  double eval[MAXARGS];
  double a, b;
  int top = 0;
  char* endpt; for (int i = 1; i < argc; i ++){
    printf("eval %s\n", argv[i]);
    switch (*argv[i]){
      case '+':
        a = eval[--top];
        b = eval[--top];
        eval[top++] = a + b;
        break;
      case '-':
        a = eval[--top];
        b = eval[--top];
        eval[top++] = b - a;
        break;
      case '*':
        a = eval[--top];
        b = eval[--top];
        eval[top++] = b * a;
        break;
      case '/':
        a = eval[--top];
        b = eval[--top];
        eval[top++] = b / a;
        break;
      default:
        eval[top++] = strtod(argv[i], &endpt);
        break;
    }
  }
  printf("%d items in stack\n", top);
  printf("result = %f\n", eval[top - 1]);
  return eval[top - 1];
}