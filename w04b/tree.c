#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

typedef struct _BSTNode BSTNode;
typedef BSTNode *BSTree;

struct _BSTNode {
	int key;
	BSTree left;
	BSTree right;
};

struct _Successor {
    int type;
    int successorKey;
};
typedef struct _Successor Successor;

#define KEY_NOT_FOUND 0
#define SUCCESSOR_NOT_FOUND 1
#define SUCCESSOR_FOUND 2

Successor keyNotFound();
Successor successorNotFound();
Successor successorFound(int successorKey);

BSTree tree(int key, BSTree left, BSTree right);
void freeTree(BSTree t);

void testIsHeightBalanced();
int isHeightBalanced(BSTree t);

void testIsSymmetric();
int isSymmetric(BSTree t);

void testIsSearchTree();
int isSearchTree(BSTree t);

void testInOrderSuccessor();
Successor inOrderSuccessor(BSTree t, int key);

int main() {
    testInOrderSuccessor();
    testIsHeightBalanced();
    testIsSymmetric();
    testIsSearchTree();
    printf("All tests passed!\n");
    return 0;
}

/////////////////////
// HEIGHT BALANCED //
/////////////////////

void testIsHeightBalanced() {
    assert(isHeightBalanced(NULL));

    BSTree t =
        tree(
            2,
            tree(
                1,
                NULL,
                NULL
            ),
            tree(
                3,
                NULL,
                NULL
            )
        );
    assert(isHeightBalanced(t));
    freeTree(t);

    t =
        tree(
            2,
            tree(
                1,
                NULL,
                NULL
            ),
            NULL
        );
    assert(isHeightBalanced(t));
    freeTree(t);

    t =
        tree(
            2,
            NULL,
            tree(
                3,
                NULL,
                NULL
            )
        );
    assert(isHeightBalanced(t));
    freeTree(t);

    t = 
        tree(
            3,
            tree(
                2,
                tree(
                    1,
                    NULL,
                    NULL
                ),
                NULL
            ),
            NULL
        );
    assert(!isHeightBalanced(t));
    freeTree(t);

    t = 
        tree(
            20,
            tree(
                10,
                NULL,
                tree(
                    15,
                    tree(
                        12,
                        NULL,
                        NULL
                    ),
                    NULL
                )
            ),
            tree(
                30,
                tree(
                    25,
                    NULL,
                    tree(
                        27,
                        NULL,
                        NULL
                    )
                ),
                NULL
            )
        );

    assert(!isHeightBalanced(t));
    freeTree(t);
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int abs(int a) {
    return max(a, -a);
}

int height(BSTree t) {
    if (t == NULL) {
        return 0;
    } else {
        return 1 + max(height(t->left), height(t->right));
    }
}

int isHeightBalanced(BSTree t) {
    // TODO
    return 0;
}


/////////////////////
// SYMMETRIC       //
/////////////////////

void testIsSymmetric() {
    assert(isSymmetric(NULL));

    BSTree t =
        tree(1,
            tree(
                2,
                NULL,
                NULL
            ),
            tree(
                2,
                NULL,
                NULL
            )
        );
    assert(isSymmetric(t));
    freeTree(t);

    t =
        tree(1,
            tree(2,
                NULL,
                NULL),
            NULL);
    assert(!isSymmetric(t));
    freeTree(t);

    t =
        tree(
            1,
            tree(
                2,
                tree(
                    3,
                    NULL,
                    NULL
                ),
                tree(
                    4,
                    NULL,
                    NULL
                )
            ),
            tree (
                2,
                tree(
                    4,
                    NULL,
                    NULL
                ),
                tree(
                    3,
                    NULL,
                    NULL
                )
            )
        );
    assert(isSymmetric(t));
    freeTree(t);

        t =
        tree(
            1,
            tree(
                2,
                tree(
                    3,
                    NULL,
                    NULL
                ),
                tree(
                    4,
                    NULL,
                    NULL
                )
            ),
            tree (
                2,
                tree(
                    3,
                    NULL,
                    NULL
                ),
                tree(
                    4,
                    NULL,
                    NULL
                )
            )
        );
    assert(!isSymmetric(t));
    freeTree(t);
}

int isMirror(BSTree s, BSTree t) {
    // TODO
    return 0;
}

int isSymmetric(BSTree t) {
    // TODO
    return 0;
}


/////////////////////
// SEARCH TREE     //
/////////////////////

void testIsSearchTree() {
    assert(isSearchTree(NULL));

    BSTree t;

    t =
        tree(
            20,
            tree(
                10,
                tree(
                    5,
                    NULL,
                    NULL
                ),
                NULL
            ),
            tree(
                30,
                tree(
                    25,
                    NULL,
                    tree(
                        27,
                        NULL,
                        NULL
                    )
                ),
                NULL
            )
        );
    assert(isSearchTree(t));
    freeTree(t);

    t =
        tree(
            5,
            tree(
                10,
                NULL,
                NULL
            ),
            NULL
        );
    assert(!isSearchTree(t));
    freeTree(t);

    t =
        tree(
            5,
            NULL,
            tree(
                2,
                NULL,
                NULL
            )
        );
    assert(!isSearchTree(t));
    freeTree(t);

    t =
        tree(
            5,
            tree(
                5,
                NULL,
                NULL
            ),
            NULL
        );
    assert(!isSearchTree(t));
    freeTree(t);

    t =
        tree(
            20,
            tree(
                10,
                NULL,
                tree(
                    25
                )
            ),
            NULL
        );
    assert(!isSearchTree(t));
    freeTree(t);

    t = 
        tree(
            30,
            tree(
                10,
                NULL,
                tree(
                    20,
                    tree(
                        5,
                        NULL,
                        NULL
                    )
                )
            ),
            NULL
        );
    assert(!isSearchTree(t));
    freeTree(t);
}

int isSearchTree(BSTree t) {
    return 0;
}


///////////////////////
// INORDER SUCCESSOR //
///////////////////////

void testInOrderSuccessor() {
    BSTree t;
    Successor s;

    s = inOrderSuccessor(NULL, 3);
    assert(s.type == KEY_NOT_FOUND);

    t = tree(3, NULL, NULL);
    s = inOrderSuccessor(t, 3);
    assert(s.type == SUCCESSOR_NOT_FOUND);
    freeTree(t);

    t = tree(3, NULL, tree(5, NULL, NULL));
    s = inOrderSuccessor(t, 3);
    assert(s.type == SUCCESSOR_FOUND);
    assert(s.successorKey == 5);
    freeTree(t);

    t = tree(3, NULL, tree(5, tree(4, NULL, NULL), NULL));

    s = inOrderSuccessor(t, 3);
    assert(s.type == SUCCESSOR_FOUND);
    assert(s.successorKey == 4);

    s = inOrderSuccessor(t, 4);
    assert(s.type == SUCCESSOR_FOUND);
    assert(s.successorKey == 5);

    freeTree(t);

    t = tree(20, tree(10, tree(5, NULL, NULL), tree(15, NULL, NULL)), tree(30, NULL, NULL));
    s = inOrderSuccessor(t, 15);
    assert(s.type == SUCCESSOR_FOUND);
    assert(s.successorKey == 20);

    s = inOrderSuccessor(t, 10);
    assert(s.type == SUCCESSOR_FOUND);
    assert(s.successorKey == 15);

    s = inOrderSuccessor(t, 13);
    assert(s.type == KEY_NOT_FOUND);
    
    s = inOrderSuccessor(t, 30);
    assert(s.type == SUCCESSOR_NOT_FOUND);

    freeTree(t);
}

Successor inOrderSuccessor(BSTree t, int key) {
    return keyNotFound();
}


// Extra functions

BSTree tree(int key, BSTree left, BSTree right) {
    BSTree t = malloc(sizeof(BSTNode));
    t->key = key;
    t->left = left;
    t->right = right;
    return t;
}

void freeTree(BSTree t) {
    if (t != NULL) {
        freeTree(t->left);
        freeTree(t->right);
        free(t);
    }
}

Successor keyNotFound() {
    return (Successor) {KEY_NOT_FOUND, 0};
}
Successor successorNotFound() {
    return (Successor) {SUCCESSOR_NOT_FOUND, 0};
}
Successor successorFound(int successorKey) {
    return (Successor) {SUCCESSOR_FOUND, successorKey};
}