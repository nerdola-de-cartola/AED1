#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
   int qtd_acertos;
   int matricula;
} Nota;

bool comparaNotas(Nota a, Nota b) {
   if(a.qtd_acertos > b.qtd_acertos) return true;
   if(a.qtd_acertos == b.qtd_acertos) {
      if(a.matricula < b.matricula) return true;
   }

   return false;
}

void swap(Nota *a, Nota *b) {
	Nota tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(Nota arr[], int first, int last) {
	int i, pivot, greater;

	pivot = last;
	greater = first;

	for(i = first; i < last; i++) {
		if(comparaNotas(arr[i], arr[pivot])) {
			swap(&arr[i], &arr[greater]);
			greater++;
		}
	}

	swap(&arr[pivot], &arr[greater]);
	return greater;
}

void quickSort(Nota arr[], int first, int last) {
	if(first >= last) return;

	int pivot = partition(arr, first, last);

	quickSort(arr, first, pivot-1);
	quickSort(arr, pivot+1, last);
}

void erro() {
   printf("erro\n");
   exit(0);
}

int main(void) {
   int qtd_candidatos, qtd_questoes;
   int i, j;
   char input;

   scanf("%d", &qtd_candidatos);
   if(qtd_candidatos < 1 || qtd_candidatos > 1000) erro();

   scanf("%d", &qtd_questoes);
   if(qtd_questoes < 1 || qtd_questoes > 50) erro();

   char gabarito[qtd_questoes];
   char provas[qtd_candidatos][qtd_questoes];
   Nota pontos[qtd_candidatos];


   for(i = 0; i < qtd_questoes;) {
      scanf("%c", &input);

      if(input != ' ' && input != '\n') {
         gabarito[i] = input;
         i++;
      }
   }
   scanf("%*c");
   
   for(i = 0; i < qtd_candidatos; i++) {
      for(j = 0; j < qtd_questoes;) {
         scanf("%c", &input);

         if(input != ' ' && input != '\n') {
            provas[i][j] = input;
            j++;
         }
      }
   }

   for(i = 0; i < qtd_candidatos; i++) {
      pontos[i].qtd_acertos = 0;
      pontos[i].matricula = i+1;
   }

   for(i = 0; i < qtd_candidatos; i++) {
      for(j = 0; j < qtd_questoes; j++) {
         if(provas[i][j] == gabarito[j]) pontos[i].qtd_acertos++;
      }
   }

   quickSort(pontos, 0, qtd_candidatos-1);

   for(i = 0; i < qtd_candidatos; i++) {
      printf("%d %d\n", pontos[i].matricula, pontos[i].qtd_acertos);
   }

   return 0;
}