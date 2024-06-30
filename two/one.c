#include <math.h>
#include <stdio.h>

int main() { 
  printf("signed char size %lu\n", 8 * sizeof(char)); 
  printf("  range -2^7, 2^7-1, [%d, %d]\n", (char)(-pow(2, 7)), (char)(pow(2, 7)-1));
  printf("  overflows -2^7 - 1, 2^7, [%d, %d]\n", (char)(-pow(2, 7)-1), (char)(pow(2, 7)));
  printf("signed int size %lu\n", 8 * sizeof(int));
  printf("signed short size %lu\n", 8 * sizeof(short));
  printf("signed long size %lu\n", 8 * sizeof(long));
  printf("unsigned char size %lu\n", 8 *sizeof(unsigned char)); 
  printf("unsigned int size %lu\n", 8* sizeof(unsigned int));
  printf("unsigned short size %lu\n", 8*sizeof(unsigned short));
  printf("unsigned long size %lu\n", 8*sizeof(unsigned long));
}