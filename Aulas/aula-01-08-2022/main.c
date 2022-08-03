#include "lista.h"

int main(void) {
    List l, t, s;

    l = newList();
    insertList(&l, 2);
    insertList(&l, 1);
    insertList(&l, 1);
    insertList(&l, 21);
    insertList(&l, -52);
    
    t = newList();
    insertList(&t, 51);
    insertList(&t, 1632);
    insertList(&t, -1);
    insertList(&t, 2);
    insertList(&t, 52);

    s = sumList(&l, &t);
    printList(&l, CRESCENTE);
    printList(&t, CRESCENTE);
    printList(&s, CRESCENTE);

    // if(searchList(&l, 1)) printf("Encontrei o valor 1\n");
    // if(!searchList(&l, 15)) printf("Não encontrei o valor 15\n");
    
    freeList(&l);
    freeList(&t);
    freeList(&s);


    return 0;
}
