#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _BSTNode BSTNode;
typedef BSTNode *BSTree;

struct _BSTNode {
	int key;
	BSTree left;
	BSTree right;
};

struct _SearchResult {
    int success;
    int result;
};
typedef struct _SearchResult SearchResult;

BSTree tree(int key, BSTree left, BSTree right);
void freeTree(BSTree t);

void testCountNodes();
int countNodes(BSTree t);

void testDepth();
int depth(BSTree t);

SearchResult fail();
SearchResult success(int result);

void testNodeDepth();
SearchResult nodeDepth(BSTree t, int key);

void testNthSmallest();
SearchResult nthSmallest(BSTree t, int n);

void testInOrderSuccessor();
SearchResult inOrderSuccessor(BSTree t, int key);

int main() {
    testCountNodes();
    testNodeDepth();
    testDepth();
    testNthSmallest();
    testInOrderSuccessor();
    printf("All tests passed!\n");
    return 0;
}

BSTree tree(int key, BSTree left, BSTree right) {
    BSTree t = malloc(sizeof(BSTNode));
    t->key = key;
    t->left = left;
    t->right = right;
    return t;
}

void freeTree(BSTree t) {
    // TODO
}

void testCountNodes() {
    BSTree t =
        tree(
            5,
            tree(
                3,
                NULL,
                tree(
                    4,
                    NULL,
                    NULL
                )
            ),
            NULL
        );

    assert(countNodes(t) == 3);
    assert(countNodes(NULL) == 0);

    freeTree(t);
}

int countNodes(BSTree t) {
    // TODO
    return 0;
}


void testDepth() {
    BSTree t =
        tree(
            5,
            tree(
                3,
                NULL,
                tree(
                    4,
                    NULL,
                    NULL
                )
            ),
            NULL
        );

    assert(depth(t) == 3);
    assert(depth(t->left) == 2);
    assert(depth(NULL) == 0);

    freeTree(t);
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int depth(BSTree t) {
    // TODO
    return 0;
}


SearchResult fail() {
    return (SearchResult) {0, 0};
}

SearchResult success(int result) {
    return (SearchResult) {1, result};
}

int isFail(SearchResult r) {
    return !r.success;
}

int isSuccess(SearchResult r, int expectedResult) {
    return r.success && r.result == expectedResult;
}

void testNodeDepth() {
    BSTree t =
        tree(
            5,
            tree(
                3,
                NULL,
                tree(
                    4,
                    NULL,
                    NULL
                )
            ),
            NULL
        );

    assert(isSuccess(nodeDepth(t, 3), 2));
    assert(isSuccess(nodeDepth(t, 5), 1));
    assert(isFail(nodeDepth(t, 29)));
    assert(isFail(nodeDepth(t, -2)));

    freeTree(t);
}

// Returns depth of node with key
SearchResult nodeDepth(BSTree t, int key) {
    // TODO
    return fail();
}

void testNthSmallest() {
    BSTree t =
        tree(
            5,
            tree(
                3,
                NULL,
                tree(
                    4,
                    NULL,
                    NULL
                )
            ),
            NULL
        );

    assert(isSuccess(nthSmallest(t, 1), 3));
    assert(isSuccess(nthSmallest(t, 2), 4));
    assert(isSuccess(nthSmallest(t, 3), 5));
    assert(isFail(nthSmallest(t, 5)));

    freeTree(t);
}

// 1 -> smallest
// 2 -> second smallest
// etc.
// assume all keys >= 0
// return NOT_FOUND if n is too big
SearchResult nthSmallest(BSTree t, int n) {
    return fail();
}

void testInOrderSuccessor();

SearchResult inOrderSuccessor(BSTree t, int key) {
    return fail();
}