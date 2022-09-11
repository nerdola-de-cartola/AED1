#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PRIORIDADE 1
#define NORMAL 2

typedef struct {
   int grupo;
   int senha;
} Cliente;

typedef struct Node {
   Cliente p;
   struct Node * next;
} Node;

typedef struct List {
   Node *first;
   Node *last;
   int size;
} List;

List newList() {
   List p;

   p.first = NULL;
   p.last = NULL;
   p.size = 0;

   return p;
}

void freeList(List *l) {
   Node * p = NULL;
   Node * tmp = NULL;

   for(p = l->first; p != NULL; p = tmp) {
      tmp = p->next;
      free(p);
   }

   *l = newList();
}

void error(void) {
   printf("erro\n");
   exit(0);
}

void leCliente(Cliente *p) {
   int grupo, senha;

   scanf("%d%d", &grupo, &senha);

   if(grupo != PRIORIDADE && grupo != NORMAL) error();

   p->grupo = grupo;
   p->senha = senha;
}

bool push(List *l, Cliente p) {
   Node *new = NULL;

   new = (Node *) malloc(sizeof(Node));
   if(new == NULL) error();

   new->p = p;
   new->next = NULL;

   if(l->first == NULL) l->first = new;
   else l->last->next = new;
   l->last = new;
   l->size++;
}

int proximaSenha(List *l) {
   Node *p = NULL;
   int ms_prioritaria = -1, ms_normal = -1;

   for(p = l->first; p != NULL; p = p->next) {
      if(p->p.grupo == PRIORIDADE) {
         if(ms_prioritaria == -1) ms_prioritaria = p->p.senha;
         else if(p->p.senha < ms_prioritaria) ms_prioritaria = p->p.senha; 
      } else {
         if(ms_normal == -1) ms_normal = p->p.senha;
         else if(p->p.senha < ms_normal) ms_normal = p->p.senha;
      }
   }

   if(ms_prioritaria != -1) return ms_prioritaria;
   return ms_normal;
}

Cliente removeList(List *l, int n) {
    Node * p = NULL;
    Node * prev = NULL;
    Cliente output;

    for(p = l->first; p != NULL; prev = p, p = p->next) {
        if(p->p.senha == n) {
            if(l->size == 1) {
                l->first = NULL;
                l->last = NULL;
            } else if(p == l->first) {
                l->first = p->next;
            } else if(p == l->last) {
                l->last = prev;
                l->last->next = NULL;
            } else {
                prev->next = p->next;
            } 

            output = p->p;
            l->size--;
            free(p);
            return output;
        }
    }

    error();
}


Cliente pop(List *l) {
   int senha;

   senha = proximaSenha(l);
   return removeList(l, senha);
}

bool verificaSenha(int nova_senha, int senhas[], int qtd_senhas) {
   int i;

   if(nova_senha < 1) return false;

   for(i = 0; i < qtd_senhas; i++) if(nova_senha == senhas[i]) return false;

   return true;
}

void imprimeCliente(Cliente p) {
   printf("%d %d", p.grupo, p.senha);
}

void imprimeLista(List *l) {
   Node *p = NULL;
   int i;

   for(p = l->first; p != NULL; p = p->next) {
      imprimeCliente(p->p);
      printf("\n");
   }
}


int main(void) {
   List fila;
   Cliente input;
   int qtd_clientes, qtd_senhas;
   int proximo_caixa;
   int i;

   fila = newList();

   scanf("%d", &qtd_clientes);
   if(qtd_clientes < 0) error();
   else if(qtd_clientes == 0) {
      printf("fim\n");
      return 0;
   }

   int senhas[qtd_clientes];
   qtd_senhas = 0;

   //Repete n vezes
   for(i = 0; i < qtd_clientes; i++) {
      leCliente(&input);

      //Verifica as senhas com complexidade O(n)
      if(!verificaSenha(input.senha, senhas, qtd_senhas)) error();
      else {
         senhas[qtd_senhas] = input.senha;
         qtd_senhas++;         
      }

      push(&fila, input); //Insere n elementos com complexidade O(1)
   }

   scanf("%d", &proximo_caixa); 
   if(proximo_caixa < 1 || proximo_caixa > 5) error();

   imprimeCliente(pop(&fila)); //Remove um elemento com complexidade O(2n)
   
   printf(" %d\n", proximo_caixa);
   printf("%d\n", fila.size);

   imprimeLista(&fila); //Imprime a lista com complexidade O(n);

   freeList(&fila); //Libera a lista com complexidade O(n);

   return 0;
}

//Complexidade total O(n^2 + 5n), pois para cada novo input é necessário executar o algoritmo de verificação de senhas
//Executanto um algoritmo O(n) n vezes, acabamos com a complexidade O(n^2)
//O restante do algoritmo tem complexidade O(5n), resultando na complexidade total O(n^2 + 5n)