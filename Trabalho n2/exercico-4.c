/*
Replique o exercício 3. Porém, agora, declare um ponteiro para a estrutura de dados heterogênea. 
No momento da leitura dos dados e da impressão na tela, use o ponteiro para buscar o conteúdo dos campos. 
Imprima na tela também o seu RU na tela.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

  //Registro, com dois campos, como dados de entrada:
  struct registro_aluno{
    char nome[20]; //vetor que vai armazenar o nome do aluno.
    int RU; //variável do tipo inteiro que vai armazenar o RU do aluno.
  };

  struct registro_aluno aluno, *p_aluno; //Declarando um ponteiro para a estrutura de dados.

  p_aluno = &aluno; //Dando ao ponteiro o endereço da estrutura.
  
  printf("\n\n- - - - - - - - - - - - - - - - - - - - \n\n"); //Para melhorar a apresentação na execução do código.
  
  //Pedindo as entradas do usuário e colocando na estrutura através dos ponteiros:
  printf("Digite seu NOME: \n >> ");
  scanf_s("%s", p_aluno -> nome);  //Salvando o nome na estrutura.

  printf("Digite seu RU: \n >> ");
  scanf_s("%d", &p_aluno -> RU);  //Salvando o RU na estrutura.

  printf("\n");

  //Imprimindo na tela os dados armazenados na estrutura através dos ponteiros:
  printf("\n Imprimindo os dados armazenados na estrutura através dos ponteiros:\n");
  printf(" Seu nome é: %s \n", p_aluno -> nome);
  printf(" e seu RU é: %d \n", p_aluno -> RU);

  printf("\n\n- - - - - - - - - - - - - - - - - - - - \n\n"); //Para melhorar a apresentação na execução do código.
  
  system("pause");
  return 0;
}