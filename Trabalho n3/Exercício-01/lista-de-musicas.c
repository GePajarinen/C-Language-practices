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
void InserirInicio(int num);
void Listar();

struct ElementoDaLista_Simples{
  int dado; //muda aqui pras musicas
  struct ElementoDaLista_Simples *proximo;
} *Head; //Global


int main() {
  int opcao, num;
  while (1){
    opcao= menu();
    switch(opcao){
      case 1: //Inserir no início da lsita
        printf("Digite o numero desejado: ");
        scanf("%d", &num);
        InserirInicio(num);
        break;
      case 2: //Inserir no fim da lsita
        break;
      case 3: //Inserir no meio da lsita
        break;
      case 4: //Remover da lista
        break; 
      case 5: //Mostrar a lita
        Listar();
        break;
      case 6:
        return 0;

    }
  }
  return 0;
}

int menu(){
  int escolha, c;
  system("Cls");

  printf("1. Inserir no início da lista encadeada simples.\n");
  printf("2. Inserir no fim da lista encadeada simples.\n");
  printf("3. Inserir no meio da lista encadeada simples.\n");
  printf("4. Remover da lista encadeada simples.\n");
  printf("5. Mostrar a lista encadeada simples.\n");
  printf("6. Sair do progrma.\n");
  printf("Digite sua opção:\n>> ");

  scanf("%d", &escolha);
  while ((c=getchar()) != '\n' && c != EOF) {} // Limpeza de buffer

  //system("Cls"); //sh: 1: Cls: not found
  return escolha;
}

void InserirInicio(int num){
  struct ElementoDaLista_Simples *NovoElemento; //Criando um novo elemento do tipo struct
  NovoElemento = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples)); //Alocar o elemento na memória do mesmo tamanho que da struct
  NovoElemento->dado = num; //O campo dado da struct NovoElemento recebe o num

  //Inserindo na lista:
  if (Head == NULL) //Se a lista estiver vazia
  {
    Head = NovoElemento;
    Head->proximo = NULL; //Aponta para nada porque nao é circular
  }
  else //Se a lista nao estiver vazia:
  {
    NovoElemento->proximo = Head;
    Head = NovoElemento;
  }
}

void Listar(){
  struct ElementoDaLista_Simples *ElementoVarredura;
  ElementoVarredura = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples)); //Alocar o elemento na memória do mesmo tamanho que da struct

  ElementoVarredura = Head;
  if (ElementoVarredura == NULL){
    return;
  }
  while (ElementoVarredura != NULL){
    printf("%d ", ElementoVarredura->dado);
    ElementoVarredura = ElementoVarredura->proximo;

  }
  printf("\n");

  //system("pause");
  return;
}