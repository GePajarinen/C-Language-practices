/*
Replique o exercício 3. Porém, agora, declare um ponteiro para a estrutura de dados heterogênea. No momento da leitura dos dados e da impressão na tela, use o ponteiro para buscar o conteúdo dos campos. Imprima na tela também o seu RU na tela.
*/

#include <stdio.h>
#include <stdlib.h>


int main(){
  //Declarando o vetor e a variável:
  char nome[10];
  int RU;

  //Declarando um ponteiro para a estrutura de dados:
  char *pnome;
  int *pRU;

  //Associando os ponteiros às estrutura de dados:
  pnome = nome;
  pRU = &RU;

  //Pedindo as entradas do usuário:
  printf("Digite seu nome e seu RU \n");

  //Lendo as entradas através dos ponteiros:
  scanf("%s %d", pnome, pRU);

  printf("\n");

  //Imprimindo na tela os dados através dos ponteiros:
  printf("Seu nome é: %s \n", pnome);
  printf("e seu RU é: %d \n", *pRU);

  return 0;
}