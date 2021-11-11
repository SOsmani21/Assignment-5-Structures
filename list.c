#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*
This program implements a simple 'List' structure and some related functions
which can be used to manipulate it.  The List represents a variable sized array
that you can add elements to, or remove elements from.

First fill in the 'List' structure

You should implement the functions in this order:
1. makeList
2. resizeList
3. pushList
4. popList
5. getList
6. setList
7. sumList
8. freeList

Roughly, each comment can be converted to one or two lines of code that you
need.

Note that the test is not exhaustive and only tests basic functionality.
*/

typedef struct List {
    int *start; // (start) int*: The pointer to an integer array
    int len; // (len) int: Length of the list, i.e. the number of valid elements
    int maxlen; // (maxlen) int: The maximum number of elements that can currently be stored
} List;

List* makeList(int *start, int len, int maxlen) {
    struct List *np = (struct List *) malloc(sizeof(struct List)); // Create a pointer to a new List structure using malloc
    np->next = NULL;// Check for out of memory error
    np.len = 0; // Initialize length and maxlength
    // Set the len
    np.maxlen = 2; // Set the maxlen (start at 2)
    int array[maxlen] *ap = (int array *) malloc(sizeof(int array[maxlen])); // Create a pointer to a new integer array of size maxlen (using malloc)
    np.start = ap// Set the start equal to that pointer
    ap->next = NULL;// Check for out of memory error
    return np;// Return the list pointer
}

/* Resize the list to a new maximum length */
void resizeList(List *list, int size) {
    assert(size > list->len);// Assert that the size is greater than the current length
    list->maxlen = relloc(list, sizeof(list->len)); // Reallocate the array with more space
    //list->maxlen = list->len; // Change the maxlen to the new maximum length
}

/* Add 'value' to the end of the list */
void pushList(List *list, int value) {
    if (list->len == list->maxlen) {
        resizeList(list, list->maxlen*2);
    } // If not enough space, resize the list to two times its current size
    *(list->start + list->len) = value; // Add the value to the end of the list
    list->len++; // Increment the len by 1
}

/* Remove and return the last element of the list */
int popList(List *list) {
    assert(list->len > 0);// Assert the list has len greater than 0
    list->len--;// Decrement the length by 1
    int lastval = list->len; // Get the last value in the list
    if (size <= list->maxlen/2) {// If the list size is now less than half its current maximum length,
        resizeList(list, list->maxlen/2);
    } // resize the list to half its current maximum length
    return lastval;// Return the last value
}

int getList(List *list, int index) {
    assert(index > 0 && index < list->len);// Assert index is greater than 0 and less than the list len
    int indelm = list[index]; // Get the element at position 'index' in the list
}

void setList(List *list, int index, int value) {
    // Assert index is greater than 0 and less than the list len
    if (index > 0 && index < list->len) {
        *(list->start + index) = value; // Set the element at position 'index' to 'value'
    }
}

int sumList(List *list) {
    int sum = 0;
    for (int n = 0, n < list->len, n++) {
        sum += list[n];
    }
    return sum; // Return the sum of all valid elements
}

void freeList(List *list) {
    free area;// Free the array space
    free list;// Free the list space
}

int main() {
    List *list = makeList();
    pushList(list, 1);
    pushList(list, 2);
    pushList(list, 3);
    assert(sumList(list) == 6);
    popList(list);
    popList(list);
    popList(list);
    for (int n = 0; n < 100; n++) {
        pushList(list, n);
        assert(getList(list, n) == n);
    }
    for (int n = 99; n >= 0; n--) {
        int m = popList(list);
        assert(m == n);
    }
    freeList(list);
}
