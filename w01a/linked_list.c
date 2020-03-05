#include <stdio.h>
#include <stdlib.h>

struct _Node {
	int value;
	struct _Node *next;
};


typedef struct _Node Node;
 
typedef Node *List; 


int sumList(List l);

int main(int argc, char *argv[]) {
    Node n1 = {1, NULL};
    Node n2 = {4, &n1};
    Node n3; //= {2, &n2};
    // n3.value = 2;
    // n3.next = &n2;

    List l = &n3;
    // (*l).value = 2;
    // (*l).next = &n2;


    l->value = 2;
    l->next = &n2;
    printf("Sum of 2->4->1->X is %d\n", sumList(l));

    return 0;
}


int sumList(List l) {
    int sum = 0;
    Node* cur = l;
    while (cur != NULL) { //cur->next != NULL;
        sum = sum + cur->value;
        cur = cur->next;
    }
    return sum;
}