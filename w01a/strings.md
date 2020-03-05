Consider the following C function.

```C
#include <stdio.h>
#include <stdlib.h>

// Copies at most n-1 characters from src to dest,
// or if src is shorter, all characters in src. Always
// adds a null terminating character after the last
// copied character. Returns a pointer to the null terminator
// of the string now in dest.
char *cpynstr(char *src, char *dest, int n) {
  int i = 0;
  while(i < n) {
    dest[i] = src[i];
    i++;
  }
  return &dest[i];
}

```

There are several issues with the code.

(a) List all of the issues
(b) Implement `cpynstr` correctly
