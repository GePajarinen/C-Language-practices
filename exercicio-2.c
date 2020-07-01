/*
Escreva um algoritmo em LINGUAGEM C que armazene na memória o seu RU e o
valor 1234567, ambos digitados pelo usuário na tela.
Em seguida, imprima na tela ambos RU usando ponteiros. 
O algoritmo também vai ter que comparar os dois RU usando ponteiros e imprimir na tela qual é o maior.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

  int RU, valor, *pRU, *pvalor;

  printf("Digite o seu RU: ");
  scanf("%d", &RU);

  printf("Digite a sequência '1234567': ");
  scanf("%d", &valor);

  pRU = &RU;
  pvalor = &valor;

  printf("\n");

  printf("Seu RU é: %d \n", *pRU);
  printf("A sequência digitada foi: %d \n", *pvalor);

  printf("\n");

  if (*pRU > *pvalor){
    printf("O seu RU é maio que a sequência.\n");
  } 
  else {
    printf("A sequência é maio que seu RU. \n");
  }

  printf("\n");


  return 0;

}

//system("read -p 'Press Enter to continue...' var"); 
//system("pause"); //Não funciona no me shell