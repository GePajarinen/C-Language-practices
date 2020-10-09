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
#include <string.h> //Biblioteca para usar a função strcpy(), porque o vetor não por ser designado, mas somente copiado. 


struct Aluno{ //Criando a estrutura heterogênea de dados para o cadastro dos alunos.
  char nome[20], email[30]; //vetores que vão armazenar o nome do aluno e outra o email.
  int RU; //Recebe o número RU.
  struct Aluno *proximo;
} *Head; //Variável de escopo Global.

//Declarando as funções que vão ser usadas 
void InserirAluno_Inicio(char n[20], char e[30], int r);
void Imprimir();
void Buscar(); 
void Menu();

int main(){
  int c, numRU; //Declarando as variáveis.

  //Criando o cadastro de cada aluno.
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
  
  Menu(); //Chamando a função Menu.
  
  //system("pause");
  return 0;
}

// A estrutura de dados utilizada para fazer a implementação é a lista encadeada Simples não circular, devido ao pequeno tamanho da lista. Não se vê necessidade de ter ponteiros para o próximo e também para o antecessor uma vez que não há muita correlação entre os dados cadastrais dos alunos. 

void Menu(){ //Função Menu:
  int escolha, c; //Declarando as variáveis.

  printf("------- Escolha sua opção: ------- \n");
  printf("1. Imprimir a lista de alunos cadastrados.\n");
  printf("2. Buscar aluno no cadastro.\n >> ");
  scanf("%d", &escolha); //scanf_s!!! Entrada da informação fornecida pelo usuário.
  while ((c=getchar()) != '\n' && c != EOF) {} // Limpeza do buffer.

  switch(escolha){ 
    case 1: //Imprime a lista dos alunos já cadastrados
      Imprimir();
    break;
    case 2: //Opção de buscar pela informação do aluno através do RU.
      Buscar();
    break;
    default: //Para opção inválida.
      printf("Escolha Inválida.\nTente novamente.\n\n");
      Menu();
  } 
  
  //system("pause");

}

void InserirAluno_Inicio(char n[20], char e[30], int r){ //Função que gera a lista dos alunos já cadastrados.

  struct Aluno *NovoAluno; //Criando um novo elemento do tipo struct. 
  
  NovoAluno = (struct Aluno *)malloc(sizeof(struct Aluno)); //Alocar o elemento na memória do mesmo tamanho que da struct original.

  strcpy(NovoAluno->nome, n); //Usando o strcpy() porque o vetor não por ser designado, mas somente copiado. 
  strcpy(NovoAluno->email, e); //Usando o strcpy() porque o vetor não por ser designado, mas somente copiado. 
  NovoAluno->RU = r; //O campo dado da struct NovoAluno recebe o RU do aluno.

  //Inserindo na lista:
  if (Head == NULL) //Se a lista estiver vazia.
  {
    Head = NovoAluno; //O Head recebe o primeiro cadastro.
    Head->proximo = NULL; //Aponta para nada porque não é circular.
  }
  else //Se a lista não estiver vazia:
  {
    NovoAluno->proximo = Head;  //O Head passa a ser o próximo.
    Head = NovoAluno; //O novo cadastro passa a ser o Head.
  }

  //system("pause");
}

void Imprimir(){ //Função que imprime a lista dos alunos.
  
  struct Aluno *ElementoVarredura;
  ElementoVarredura = (struct Aluno *)malloc(sizeof(struct Aluno)); //Alocar o elemento na memória do mesmo tamanho que da struct original.

  ElementoVarredura = Head;
  if (ElementoVarredura == NULL){ //Quando chegar ao final da lista.
    return;
  }
  while (ElementoVarredura != NULL){ //Enquanto não chega ao final da lista, imprime as informações.
    printf("\nNome: %s", ElementoVarredura->nome);
    printf("\nE-mail: %s", ElementoVarredura->email);
    printf("\nRu: %d\n", ElementoVarredura->RU);
    ElementoVarredura = ElementoVarredura->proximo;
  }
  printf("\n\n");

  //system("pause");
  return;
}


void Buscar (){//Função que busca as informações do aluno pelo RU.

  int c, numRU; //Declarando as variáveis.

  printf("\n****** Procurar aluno ******\n");
  printf("Digite o RU do aluno que deseja buscar:\n>> ");
  scanf("%d", &numRU); //scanf_s!!!! Recebendo a informação do usuário.
  while ((c=getchar()) != '\n' && c != EOF) {} // Limpeza do buffer.

  struct Aluno *ElementoVarredura;
  ElementoVarredura = (struct Aluno *)malloc(sizeof(struct Aluno)); //Alocar o elemento na memória do mesmo tamanho que da struct original.

  ElementoVarredura = Head;
  
  while(ElementoVarredura != NULL){ //Enquando não chega ao final da lista.
    if (ElementoVarredura->RU == numRU) {//Se o RU cadastrado for igual ao RU que o usuário digitou para a busca. 
      printf("\nAluno encontrado:\n");
			printf("\nNome: %s", ElementoVarredura->nome);
      printf("\nE-mail: %s", ElementoVarredura->email);
      return;
		}
		else { //Se o RU cadastrado não for igual ao RU que o usuário digitou para a busca, segue em frente.
			ElementoVarredura = ElementoVarredura->proximo;
		} 
  }

  printf("\nAluno não encontrado.\n"); //Para o caso do RU que o usuário busca não for encontrado na lista dos cadastrados.

  //system("pause");
  return;
}

