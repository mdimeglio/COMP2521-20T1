#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void drawH(unsigned int size);

int main(int argc, char *argv[]) {
    unsigned int n;
    scanf("%d", &n);
    printf("\n");
    drawH(n);
    return EXIT_SUCCESS;
}

void drawH (unsigned int size) {
    assert (size>=3 && (size%2) != 0);  // size must be odd and >= 3
    int row = 0;
    int col = 0;
    while (col < size) {
        while (row < size) {
            char draw;
            if (row = row/2) {
               draw = '*';
            } else if ((col == 0) && (col == size)) {
               draw = '*';
            } else {
               draw = ' ';
            }
            printf("%c", draw);
            row++;
        }
        col++;
    }
    printf("\n");

}