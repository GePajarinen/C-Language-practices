/**
Exercício 1:
Aula prática 02
**/

#include <stdio.h>
#include<stdlib.h>

int menu();
void InserirInicio(int num);
void InserirFinal(int num);
void InserirMeio(int num, int posicao);
void Listar();
int Remover(int num);

struct ElementoDaLista_Simples{
  int dado; //muda aqui pras musicas
  struct ElementoDaLista_Simples *proximo;
} *Head; //Global


int main() {
  int c, opcao, num, posicao, remocao;
  while (1){
    opcao= menu();
    switch(opcao){
      case 1: //Inserir no início da lsita
        printf("Digite o numero desejado: ");
        scanf("%d", &num);
        while ((c=getchar()) != '\n' && c != EOF) {} // Limpeza do buffer
        InserirInicio(num);
        break;
      
      case 2: //Inserir no fim da lsita
        printf("Digite o numero desejado: ");
        scanf("%d", &num);
        while ((c=getchar()) != '\n' && c != EOF) {} // Limpeza do buffer
        InserirFinal(num);
        break;
      
      case 3: //Inserir no meio da lsita
        printf("Digite o numero desejado: ");
        scanf("%d", &num);
        while ((c=getchar()) != '\n' && c != EOF) {} // Limpeza do buffer
        printf("Digite a posicao: ");
        scanf("%d", &posicao);
        while ((c=getchar()) != '\n' && c != EOF) {} // Limpeza do buffer
        InserirMeio(num, posicao);
        break;
      
      case 4: //Remover da lista
        printf("Digite o numero a ser removido: ");
        scanf("%d", &num);
        while ((c = getchar()) != '\n' && c != EOF) {} // Limpeza do buffer

        remocao = Remover(num);
        if (remocao == 1)
          printf("Numero removido.\n");
        else
          printf("Numero nao encontrado.\n");
        
        break;
      
      case 5: //Mostrar a lita
        Listar();
        break;
      
      case 6:
        return 0;
      
      default:
			  printf("Invalido\n");

    }
  }
  return 0;
}

int menu(){
  int escolha, c;
  //system("Cls"); //sh: 1: Cls: not found

  printf("1. Inserir no início da lista encadeada simples.\n");
  printf("2. Inserir no fim da lista encadeada simples.\n");
  printf("3. Inserir no meio da lista encadeada simples.\n");
  printf("4. Remover da lista encadeada simples.\n");
  printf("5. Mostrar a lista encadeada simples.\n");
  printf("6. Sair do progrma.\n");
  printf("Digite sua opção:\n>> ");

  scanf("%d", &escolha);
  while ((c=getchar()) != '\n' && c != EOF) {} // Limpeza do buffer

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

void InserirFinal(int num){
  
  struct ElementoDaLista_Simples *NovoElemento; //Criando um novo elemento do tipo struct
  NovoElemento = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples)); //Alocar o elemento na memória do mesmo tamanho que da struct

  struct ElementoDaLista_Simples *ElementoVarredura;
  ElementoVarredura = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples)); //Alocar o elemento na memória do mesmo tamanho que da struct

  NovoElemento->dado = num;
  if(Head == NULL){
    Head = NovoElemento;
    Head->proximo = NULL;
  }
  else{
    ElementoVarredura = Head;
    
    while(ElementoVarredura->proximo != NULL){
      ElementoVarredura = ElementoVarredura->proximo;
    }
    ElementoVarredura->proximo = NovoElemento;
    NovoElemento->proximo = NULL;
  }
}

void InserirMeio(int num, int position){
  int posicao = position -1; //Para a posicao do usuário conincidir com a posicao correta na lista.

  struct ElementoDaLista_Simples *NovoElemento; //Criando um novo elemento do tipo struct
  NovoElemento = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples)); //Alocar o elemento na memória do mesmo tamanho que da struct

  struct ElementoDaLista_Simples *ElementoVarredura;
  ElementoVarredura = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples)); //Alocar o elemento na memória do mesmo tamanho que da struct

  struct ElementoDaLista_Simples *ElementoAuxiliar;
  ElementoAuxiliar = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples)); //Alocar o elemento na memória do mesmo tamanho que da struct

  NovoElemento->dado = num;
  if (posicao == 0){
    Head = NovoElemento;
    Head->proximo = NULL;
  }
  else{
    ElementoVarredura = Head;
    for(int i=0; i<posicao-1; i++){
      ElementoVarredura = ElementoVarredura->proximo;
    }
    ElementoAuxiliar = ElementoVarredura->proximo;
    ElementoVarredura->proximo = NovoElemento;
    NovoElemento->proximo = ElementoAuxiliar;
  }

}

int Remover(int num){

  struct ElementoDaLista_Simples *ElementoVarredura;
	ElementoVarredura = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples)); //Alocar o elemento na memória do mesmo tamanho que da struct
	
  struct ElementoDaLista_Simples * Auxiliar;
	Auxiliar = (struct ElementoDaLista_Simples *)malloc(sizeof(struct ElementoDaLista_Simples)); //Alocar o elemento na memória do mesmo tamanho que da struct

	ElementoVarredura = Head;
  
	while (ElementoVarredura != NULL) {
		if (ElementoVarredura->dado == num) {
			if (ElementoVarredura == Head) {
				Head = ElementoVarredura->proximo;
				free(ElementoVarredura);
        return 1;
			}
			else {
				Auxiliar->proximo = ElementoVarredura->proximo ;
				free(ElementoVarredura);
				return 1;
			}
		}
		else {
			Auxiliar = ElementoVarredura;
			ElementoVarredura = ElementoVarredura->proximo;
		}
    
	}

  return 0;

}