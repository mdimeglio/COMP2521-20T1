```C
char *cpynstr(char *src, char *dest, int n) {
    int i = 0;
    while(i < n-1 && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
    return &dest[i];
}

```