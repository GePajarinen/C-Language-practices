/*
Exercício 2:
Faça um algoritmo em linguagem C que realiza a busca de um aluno da UNINTER no AVA. A busca deve ser realizada utilizando uma estrutura de dados bastante eficiente para esta tarefa.
Defina a estrutura de dados que você irá utilizar para fazer esta implementação e JUSTIFIQUE em texto porque você escolheu ela;
1. Deve-se armazenar o nome do aluno, seu e-mail e seu RU. Para o armazenamento utilize uma estrutura heterogênea de dados.
2. Não é necessário fazer a leitura dos dados dos dados dos alunos manualmente. Você já pode deixar pré-cadastrado os dados no seu código. Cadastre pelo menos uns 10 contatos de alunos na sua estrutura de dados. Um dos contatos deverá ser o seu próprio nome e o seu RU da UNINTER;
3. Em um menu na tela, peça para o usuário digitar um RU. O programa deverá realizar a busca por este RU na estrutura de dados e, caso localize o RU, deverá mostrar o nome correspondente do aluno e o e-mail deste contato. Caso não localize, uma mensagem de erro deve ser apresentada.
4. Para testar o programa, teste a busca com o seu RU e coloque a captura de dela.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Para usar a funcao strcpy() cause -> You can't assign to an array, only copy to it.


struct Aluno{
  char nome[20], email[30];
  int RU;
  struct Aluno *proximo;
} *Head; //Global


void InserirAluno_Inicio(char n[20], char e[30], int r);
void Imprimir();
void Buscar();
void Menu();

int main(){
  int c, numRU;

  InserirAluno_Inicio("Angela", "Angela@dm.com", 2466551);
  InserirAluno_Inicio("Jim", "Jim@dm.com", 2466552);
  InserirAluno_Inicio("Pamela", "Pamela@dm.com", 2466553);
  InserirAluno_Inicio("Oscar", "Oscar@dm.com", 2466554);
  InserirAluno_Inicio("Dwight", "Dwight@dm.com", 2466555);
  InserirAluno_Inicio("Gesiane", "Gesiane@dm.com", 2466550);
  InserirAluno_Inicio("Toby", "Toby@dm.com", 2466556);
  InserirAluno_Inicio("Philys", "Philys@dm.com", 2466557);
  InserirAluno_Inicio("Stanley", "Stanley@dm.com", 2466558);
  InserirAluno_Inicio("Michael", "Michael@dm.com", 2466559);
  
  Menu();
  
  //system("pause");
  return 0;
}

// A estrutura de dados utilizada para fazer a implementação é a Linear Simples, devido ao pequeno tamanho da lista. Não se vê necessidade de ter ponteiros para o próximo e também para o antecessor uma vez que não há muita correlação entre os dados cadastrais dos alunos. 

void Menu(){
  int escolha, c; 

  printf("------- Escolha sua opção: ------- \n");
  printf("1. Imprimir a lista de alunos cadastrados.\n");
  printf("2. Buscar aluno no cadastro.\n >> ");
  scanf("%d", &escolha);
  while ((c=getchar()) != '\n' && c != EOF) {} // Limpeza do buffer

  switch(escolha){
    case 1:
      Imprimir();
    break;
    case 2:
      Buscar();
    break;
    default:
      printf("Escolha Inválida.\nTente novamente.\n\n");
      Menu();
  } 
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

void Imprimir(){
  struct Aluno *ElementoVarredura;
  ElementoVarredura = (struct Aluno *)malloc(sizeof(struct Aluno)); //Alocar o elemento na memória do mesmo tamanho que da struct

  ElementoVarredura = Head;
  if (ElementoVarredura == NULL){
    return;
  }
  while (ElementoVarredura != NULL){
    printf("\nNome: %s", ElementoVarredura->nome);
    printf("\nE-mail: %s", ElementoVarredura->email);
    printf("\nRu: %d\n", ElementoVarredura->RU);
    ElementoVarredura = ElementoVarredura->proximo;
  }
  printf("\n\n");

  //system("pause");
  return;
}


void Buscar (){

  int c, numRU;

  printf("\n****** Procurar aluno ******\n");
  printf("Digite o RU do aluno que deseja buscar:\n>> ");
  scanf("%d", &numRU);
  while ((c=getchar()) != '\n' && c != EOF) {} // Limpeza do buffer

  struct Aluno *ElementoVarredura;
  ElementoVarredura = (struct Aluno *)malloc(sizeof(struct Aluno)); //Alocar o elemento na memória do mesmo tamanho que da struct

  ElementoVarredura = Head;
  
  while(ElementoVarredura != NULL){
    if (ElementoVarredura->RU == numRU) {
      printf("\nAluno encontrado:\n");
			printf("\nNome: %s", ElementoVarredura->nome);
      printf("\nE-mail: %s", ElementoVarredura->email);
      return;
		}
		else {
			ElementoVarredura = ElementoVarredura->proximo;
		} 
  }

  printf("\nAluno não encontrado.\n");

  //system("pause");
  return;
}

