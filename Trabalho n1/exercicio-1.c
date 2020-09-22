/*
Exercício 1:
Escreva um algoritmo em linguagem C com as seguintes instruções:
1. Declare três variáveis (inteiro, real e char);
2. Declare três ponteiros;
3. Associe as variáveis aos ponteiros;
4. Modifique os valores de cada variável indiretamente  usando os ponteiros associados. 
   Para armazenar os valores nas variáveis, armazene na variável char a primeira letra do seu nome, 
   na variável inteira os dois últimos dígitos do seu RU e na variável real os 4 últimos dígitos do seu RU, 
   sendo os 2 últimos os valores com virgula;
5. Imprima na tela os valores das variáveis antes e após a modificação.
   RU 2466550
*/

#include <stdio.h> 
#include <stdlib.h>

int main() {
  // Declarando três variáveis (inteiro, real e char):
  int RUint;
  float RUfloat;
  char letra;

  //Declarando três ponteiros:
  int *pRUint;
  float *pRUfloat; 
  char *pletra; 
  
  //Associando as variáveis aos ponteiros:
  pRUint = &RUint;
  pRUfloat = &RUfloat;
  pletra = &letra; //OU pontc = c

  printf("________________ANTES________________\n"); 
  //Imprimindo na tela os valores das variáveis antes da modificação:
  // Vou atriburi diretamente às variáveis os valores:

  RUint = 24; //Os dois primeiros dígitos do meu RU.
  RUfloat = 24.66; //Os 4 priemeiros dígitos do meu RU com 2 casa decimais.
  letra = 'E'; // A última letra do meu nome.

  printf("valor de RUint = %d \n", RUint);
  printf("valor de RUfloat = %.2f \n", RUfloat);
  printf("valor da letra = %c \n", letra);

  printf("\n");
  
  /**************************************************************
  * Modificando os valores de cada variável indiretamente, usando os * ponteiros associados: 
  ***************************************************************/

  *pRUint = 50; // Armazenando na variável inteira os dois últimos dígitos do meu RU.
  *pRUfloat = 65.50; // Armazenando na variável real os 4 últimos dígitos do meu RU, sendo os 2 últimos os valores com virgula.
  *pletra = 'G'; //Armazenando na variável char a primeira letra do meu nome.
  
  printf("________________DEPOIS________________\n"); 
  //Imprimindo na tela os valores das variáveis após a modificação:
  
  printf("valor de RUint = %d \n", RUint);
  printf("valor de RUfloat = %.2f \n", RUfloat);
  printf("valor da letra = %c \n", letra);

  system("pause");
  return 0; 
}

//system("pause"); //Não funciona no me shell
//system("read -p 'Press Enter to continue...' var"). <- Posso usar esse. 
//http://www.inf.ufpr.br/cursos/ci067/Docs/NotasAula/notas-29_Strings_Ponteiros.html
