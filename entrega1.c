#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct sorteio{
  char face[3];   //face da carta
  char naipe[2];  //naipe da carta
  int valor;      //pontuacao correspondente de cada carta
  char nome[20];  //nome da carta
} Tcarta;

int main() {
  Tcarta cartas[52];
  FILE* arq;
  int i, mao, funcao; 

  srand(time(NULL));
  arq = fopen("trabalho/cartas","r");

  for(i=0; i<52; i++)
    fscanf(arq, "%s %s %d %[^\n]s", cartas[i].face, cartas[i].naipe, &cartas[i].valor, cartas[i].nome);
  fclose(arq);

  do{
    mao = rand()%52;
    printf("Mão atual:\t\t1\n");
    printf("\t\t\t |%s - %s|\n\n", cartas[mao].face, cartas[mao].naipe);
    printf("Deseja sortear outra carta? [1-sim] [0-não]:\n ");
    scanf("%d", &funcao);
    system("clear");
  }while(funcao==1);
    printf("Sorteio encerrado com sucesso!!");
  return 0;
}