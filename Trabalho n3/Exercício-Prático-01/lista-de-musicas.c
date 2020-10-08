/**
Exercício 1:
Faça um algoritmo em linguagem C que emule as características de um player de músicas sendo executado em modo texto, via prompt de comando.
1. Deve-se criar uma playlist das músicas utilizando uma lista encadeada. A lista encadeada poderá ser simples ou dupla, circular ou não circular. Fica a critério do aluno decidir.
2. Deve-se armazenar o nome de cada música, do artista/banda e a duração da faixa. Para o armazenamento utilize uma estrutura heterogênea de dados.
3. Para inserção dos dados, você pode criar uma leitura dos dados através de um menu na tela ou já deixá-los armazenados em um arquivo texto no seu computador e só carregar este arquivo ao executar o programa. Ou ambas soluções. Decida também como você irá implementar a inserção (no início, no fim ou no meio da lista encadeada);
4. Deve existir um menu na tela. Este menu deve permitir a inserção de novas músicas (caso optado pela inserção manual de dados), deve ter a opção de listar todas as músicas da playlist (listagem de uma lista encadeada) na tela e encerrar o programa;
Utilize como base o código de listas da AULA PRÁTICA 2 da disciplina. Código está disponível no Github do professor. O link está na aula prática 2;
*/


#include <stdio.h>
#include<stdlib.h>

int menu();
void InserirInicio();
void Listar();

struct Lista_de_Musicas{
  char titulo[30], artista[30]; //vetor que vai armazenar o titulo da musica.
  float duracao;
  struct Lista_de_Musicas *proximo;
} *Head; //Global


int main() {
  int c, opcao;
  while (1){
    opcao= menu();

    switch(opcao){
      case 1: //Inserir no início da lista
        InserirInicio();
        break;
      
      case 2: //Mostrar a lista
        Listar();
        break;
      
      case 3: //Sair do programa
        return 0;
      
      default: //Para opção inválida
			  printf("\nOpção inválida. Tente novamente.\n\n");

    }
  }
  return 0;
}

int menu(){
  int escolha, c;
  //system("Cls"); //sh: 1: Cls: not found

  printf("----------------------------------\n");
  printf("1. Inserir nova música.\n");
  printf("2. Mostrar lista de músicas.\n");
  printf("3. Sair do progrma.\n");
  printf("----------------------------------\n");
  printf("Digite sua opção:\n>> ");

  scanf("%d", &escolha); //scanf_s
  while ((c=getchar()) != '\n' && c != EOF) {} // Limpeza do buffer

  //system("Cls"); //sh: 1: Cls: not found
  return escolha;
}

void InserirInicio(){
  int c;

  struct Lista_de_Musicas *NovaMusica; //Criando um novo elemento do tipo struct
  
  NovaMusica = (struct Lista_de_Musicas *)malloc(sizeof(struct Lista_de_Musicas)); //Alocar o elemento na memória do mesmo tamanho que da struct
  
  printf("Digite o nome da música: \n>> ");
  scanf("%s", NovaMusica->titulo);
  while ((c=getchar()) != '\n' && c != EOF) {} // Limpeza do buffer
  //Adicionar o limpador!!!!
  
  printf("Nome do artista ou da banda: \n>> ");
  scanf("%s", NovaMusica->artista); //scanf_s
  while ((c=getchar()) != '\n' && c != EOF) {} // Limpeza do buffer
  //Adicionar o limpador!!!!
  
  printf("Tempo da faixa musical:  \n>> ");
  scanf("%f", &NovaMusica->duracao); //scanf_s
  while ((c=getchar()) != '\n' && c != EOF) {} // Limpeza do buffer
  //Adicionar o limpador!!!!

  //Inserindo na lista:
  if (Head == NULL) //Se a lista estiver vazia
  {
    Head = NovaMusica;
    Head->proximo = NULL; //Aponta para nada porque nao é circular
  }
  else //Se a lista nao estiver vazia:
  {
    NovaMusica->proximo = Head;
    Head = NovaMusica;
  }
}

void Listar(){
  struct Lista_de_Musicas *ElementoVarredura;
  ElementoVarredura = (struct Lista_de_Musicas *)malloc(sizeof(struct Lista_de_Musicas)); //Alocar o elemento na memória do mesmo tamanho que da struct

  ElementoVarredura = Head;

  if (ElementoVarredura == NULL){
    printf("\nNão há nenhuma música salva.\n\n");
    return;
  }
  while (ElementoVarredura != NULL){
    printf("Título: %s \n", ElementoVarredura->titulo);
    printf("Artista/Banda: %s \n", ElementoVarredura->artista);
    printf("Duração: %.2f \n\n", ElementoVarredura->duracao);
    
    ElementoVarredura = ElementoVarredura->proximo;

  }
  printf("\n");

  //system("pause");
  return;
}
