#include "lista.h"

int main(void) {
    List l;

    l = newList();
    insertList(&l, 2);
    insertList(&l, 55);
    insertList(&l, 1);
    insertList(&l, 1);
    insertList(&l, 21);
    insertList(&l, 12);
    insertList(&l, -52);
    printList(&l);
    insertList(&l, 0);
    printList(&l);
    insertList(&l, 312);
    insertList(&l, 312);
    insertList(&l, 31251);
    insertList(&l, -131);
    insertList(&l, 0);
    printList(&l);

    return 0;
}