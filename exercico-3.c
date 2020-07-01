/*
Faça um algoritmo em linguagem C com as seguintes funcionalidades:
- Receba um registro, com dois campos, como dados de entrada.
- O primeiro campo é um vetor que vai armazenar o nome do aluno.
- O segundo campo é uma variável do tipo inteiro que vai armazenar o   
    RU do aluno.
- Imprime na tela os dados armazenados na estrutura.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
  //Declarando o vetor e a variável:
  char nome[10];
  int RU;

  //Pedindo as entradas do usuário:
  printf("Digite seu nome e seu RU \n");
  
  //Armazenando as entradas:
  scanf("%s %d", &nome[0], &RU);

  printf("\n");

  //Imprimindo na tela os dados armazenados na estrutura:
  printf("Seu nome é: %s \n", nome);
  printf("e seu RU é: %d \n", RU);

  return 0;
}