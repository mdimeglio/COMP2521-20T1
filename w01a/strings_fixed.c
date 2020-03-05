#include <stdio.h>
#include <stdlib.h>

char *cpynstr(char *src, char *dest, int n);

int main(int argc, char*argv[]) {
  int secondSize;
  char str1[100];
  char str2[20];

  int i = 0;
  while(i < 19) {
    str2[i] = 'a';
    i++;
  }
  str2[19] = '\0';

  printf("Initial value of dest (str2): \"%s\"\n", str2);

  printf("Enter size of dest:");
  scanf("%d", &secondSize);


  printf("Enter intial value of src (str1):");
  scanf(" ");
  fgets(str1, 100, stdin);

  char *nullT = cpynstr(str1, str2, secondSize);

  printf("Returned pointer to char: '%c', ASCII: %x\n", *nullT, *nullT);
  printf("Final value of dest (str2): \"%s\"\n", str2);

  return EXIT_SUCCESS;
}


// cpynstr
// Copies at most n-1 characters from src to dest
// (or if src is shorter, all characters in src)
// and adds null terminator
// and returns a pointer to the null terminator of the string
char *cpynstr(char *src, char *dest, int n) {
  int i = 0;
  while(i < n && src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return dest + i; //&dest[i];
}




