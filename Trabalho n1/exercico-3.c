/*
Faça um algoritmo em linguagem C com as seguintes funcionalidades:
- Receba um registro, com dois campos, como dados de entrada.
- O primeiro campo é um vetor que vai armazenar o nome do aluno.
- O segundo campo é uma variável do tipo inteiro que vai armazenar o RU do aluno.
- Imprime na tela os dados armazenados na estrutura.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
  //Registro, com dois campos, como dados de entrada:
  struct registro_aluno{
    char nome[10]; //vetor que vai armazenar o nome do aluno.
    int RU; //variável do tipo inteiro que vai armazenar o   RU do aluno.
  };

  struct registro_aluno aluno;
  
  printf("\n\n- - - - - - - - - - - - - - - - - - - - \n\n");
  
  //Pedindo as entradas do usuário:
  printf("Digite seu NOME: \n >> ");
  scanf("%s", aluno.nome); // COLOCAR _S //Salvando o nome na estrutura.

  printf("Digite seu RU: \n >> ");
  scanf("%d", &aluno.RU); // COLOCAR _S  //Salvando o RU na estrutura.

  printf("\n");

  //Imprimindo na tela os dados armazenados na estrutura:
  printf("Seu nome é: %s \n", aluno.nome);
  printf("e seu RU é: %d \n", aluno.RU);

  printf("\n\n- - - - - - - - - - - - - - - - - - - - \n\n");
  
  //system("pause");
  return 0;
}