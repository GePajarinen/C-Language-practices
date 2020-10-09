/*
Exercício 2:Faça um algoritmo em linguagem C que realiza a busca de um aluno da UNINTER no AVA. A busca deve ser realizada utilizando uma estrutura de dados bastante eficiente para esta tarefa.Defina a estrutura de dados que você irá utilizar para fazer esta implementação e JUSTIFIQUE em texto porque você escolheu ela;1. Deve-se armazenar o nome do aluno, seu e-mail e seu RU. Para o armazenamento utilize uma estrutura heterogênea de dados.2. Não é necessário fazer a leitura dos dados dos dados dos alunos manualmente. Você já pode deixar pré-cadastrado os dados no seu código. Cadastre pelo menos uns 10 contatos de alunos na sua estrutura de dados. Um dos contatos deverá ser o seu próprio nome e o seu RU da UNINTER;3. Em um menu na tela, peça para o usuário digitar um RU. O programa deverá realizar a busca por este RU na estrutura de dados e, caso localize o RU, deverá mostrar o nome correspondente do aluno e o e-mail deste contato. Caso não localize, uma mensagem de erro deve ser apresentada.4. Para testar o programa, teste a busca com o seu RU e coloque a captura de dela.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Para usar a funcao strcpy() cause -> You can't assign to an array, only copy to it.


struct Aluno{
  char nome[20], email[30];
  int RU;
  struct Aluno *proximo;
} *Head; //Global


void display(struct Aluno a) {
   printf("\nDisplaying information\n");
   printf("\nNome: %s", a.nome);
   printf("\nE-mail: %s", a.email);
   printf("\nRu: %d\n", a.RU);
}
void InserirAluno_Inicio(char n[20], char e[30], int r);

int main(){

  InserirAluno_Inicio("Angela", "Angela@dm.com", 2466551);
  /*
  struct Aluno a1 = {"Angela", "Angela@dm.com", 2466551};
  struct Aluno a2 = {"Jim", "Jim@dm.com", 2466552};
  struct Aluno a3 = {"Pamela", "Pamela@dm.com", 2466553};
  struct Aluno a4 = {"Oscar", "Oscar@dm.com", 2466554};
  struct Aluno a5 = {"Dwight", "Dwight@dm.com", 2466555};
  struct Aluno a6 = {"Gesiane", "Gesiane@dm.com", 2466550};
  struct Aluno a7 = {"Toby", "Toby@dm.com", 2466556};
  struct Aluno a8 = {"Philys", "Philys@dm.com", 2466557};
  struct Aluno a9 = {"Stanley", "Stanley@dm.com", 2466558};
  struct Aluno a10 = {"Michael", "Michael@dm.com", 2466559};
  
  display(a1);
  display(a2);
  */
  
  //system("pause");
  return 0;
}

void InserirAluno_Inicio(char n[20], char e[30], int r){
  struct Aluno *NovoAluno; //Criando um novo elemento do tipo struct
  
  NovoAluno = (struct Aluno *)malloc(sizeof(struct Aluno)); //Alocar o elemento na memória do mesmo tamanho que da struct

  strcpy(NovoAluno->nome, n); //can't assign to an array, only copy to it.
  strcpy(NovoAluno->email, e); //can't assign to an array, only copy to it.
  NovoAluno->RU = r; //O campo dado da struct NovoAluno recebe o num

  //Inserindo na lista:
  if (Head == NULL) //Se a lista estiver vazia
  {
    Head = NovoAluno;
    Head->proximo = NULL; //Aponta para nada porque nao é circular
  }
  else //Se a lista nao estiver vazia:
  {
    NovoAluno->proximo = Head;
    Head = NovoAluno;
  }
}