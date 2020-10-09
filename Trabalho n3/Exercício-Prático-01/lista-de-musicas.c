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

int menu(); //Anunciando a função Menu.
void InserirInicio(); //Anunciando a função que vai criar a lista.
void Imprimir(); //Anunciando a função que vai imprimir a lista na tela.


struct Lista_de_Musicas{
  char titulo[30], artista[30]; //vetores que vão armazenar o título da musica e outra o artista ou banda.
  float duracao; //duração da faixa musical.
  struct Lista_de_Musicas *proximo;
} *Head; //elemento de escopo Global.


int main() {
  int c, opcao; //Criação das variáveis.

  while (1){
    opcao= menu(); //Chamndo a função do Menu.

    switch(opcao){
      case 1: //Inserir música no início da lista.
        InserirInicio();//Chamdno a função de inserir.
        break;
      
      case 2: //Imprimir a lista de músicas
        Imprimir();
        break;
      
      case 3: //Sair do programa.
        return 0;
      
      default: //Para opção inválida
	printf("\nOpção inválida. Tente novamente.\n\n");

    }
  }

  return 0;
  //system("pause");
}

int menu(){ //Função MENU:
  int escolha, c;

  printf("-------------- MENU --------------\n");
  printf("1. Inserir nova música.\n");
  printf("2. Mostrar lista de músicas.\n");
  printf("3. Sair do progrma.\n");
  printf("----------------------------------\n");
  printf("Digite sua opção:\n>> ");

  scanf("%d", &escolha); //scanf_s Entrada da opção do usuário.
  while ((c=getchar()) != '\n' && c != EOF) {} // Limpeza do buffer.

  return escolha;
}

void InserirInicio(){ //Função que insere a música na lista.
  int c; //Variável para a limpeza do buffer.

  struct Lista_de_Musicas *NovaMusica; //Criando um novo elemento do tipo struct.
  
  NovaMusica = (struct Lista_de_Musicas *)malloc(sizeof(struct Lista_de_Musicas)); //Alocar o elemento na memória do mesmo tamanho que da struct original.
  
  printf("Digite o nome da música: \n>> ");
  scanf("%s", NovaMusica->titulo); //scanf_s!!!! Recebendo o dado do usuário.
  while ((c=getchar()) != '\n' && c != EOF) {} // Limpeza do buffer.
  
  printf("Nome do artista ou da banda: \n>> ");
  scanf("%s", NovaMusica->artista); //scanf_s!!! //Recebendo a informação do usuário.
  while ((c=getchar()) != '\n' && c != EOF) {} // Limpeza do buffer.
  
  printf("Tempo da faixa musical:  \n>> ");
  scanf("%f", &NovaMusica->duracao); //scanf_s Recebendo a informação do usuário.
  while ((c=getchar()) != '\n' && c != EOF) {} // Limpeza do buffer.

  //Inserindo na lista:
  if (Head == NULL) //Se a lista estiver vazia, a música fica no início.
  {
    Head = NovaMusica;
    Head->proximo = NULL; //Aponta para nada porque não é circular.
  }
  else //Se a lista não estiver vazia, o Head passa como próximo e a nova música passa a ser o Head.
  {
    NovaMusica->proximo = Head;
    Head = NovaMusica;
  }
  
  //system("pause");
}

void Imprimir(){ //Função de imprimir a lista de músicas.

  struct Lista_de_Musicas *ElementoVarredura;
  ElementoVarredura = (struct Lista_de_Musicas *)malloc(sizeof(struct Lista_de_Musicas)); //Alocar o elemento na memória do mesmo tamanho que da struct original.

  ElementoVarredura = Head; 

  printf("\n---------- Lista de Músicas ----------\n\n");

  if (ElementoVarredura == NULL){ //Se a lsita de música estiver vazia:
    printf("Você ainda não inseriu nenhuma música :(\n\n");
    return;
  }
  while (ElementoVarredura != NULL){ //Se a lista de música não estiver vazia:
    printf("Título: %s \n", ElementoVarredura->titulo);
    printf("Artista/Banda: %s \n", ElementoVarredura->artista);
    printf("Duração: %.2f \n\n", ElementoVarredura->duracao);
    
    ElementoVarredura = ElementoVarredura->proximo;

  }
  printf("\n");

  //system("pause");
  return;
}

/*
Queria ter um file pra abrir e registrar e ja ter alguma coisa registrada pra acessar.
*/
