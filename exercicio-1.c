/*
Exercício 1:
Escreva um algoritmo em linguagem C com as seguintes instruções:
1. Declare três variáveis (inteiro, real e char);
2. Declare três ponteiros;
3. Associe as variáveis aos ponteiros;
4. Modifique os valores de cada variável ! indiretamente  usando os ponteiros associados!. Para armazenar os valores nas variáveis, armazene na variável char a primeira letra do seu nome, na variável inteira os dois últimos dígitos do seu RU e na variável real os 4 últimos dígitos do seu RU, sendo os 2 últimos os valores com virgula;
5. Imprima na tela os valores das variáveis antes e após a modificação.
RU 2466550
*/

// COLOCAR COMENTÁRIO!!!!!!!!!!!!!!!
#include <stdio.h> 
#include <stdlib.h>

int main() {
  int a;
  float b;
  char c[1];

  int *ponta;
  float *pontb; 
  char *pontc; 
  
  /*O valor inicial deste ponteiro deve ser sempre o endereço do primeiro caracter do string */

  ponta = &a;
  pontb = &b;
  pontc = &c[0]; //OU pontc = c

  printf("________________ANTES________________\n");
  printf("valor de a = %d \n", a);
  printf("valor de b = %.2f \n", b);
  printf("valor de c = %s \n", c);

  printf("\n");
  printf("________________DEPOIS________________\n");

  *ponta = 50;
  *pontb = 65.50;
  *pontc = 'G';
  

  printf("valor de a = %d \n", a);
  printf("valor de b = %.2f \n", b);
  printf("valor de c = %s \n", c);

  
  return 0; 
}

//system("read -p 'Press Enter to continue...' var"); 
//http://www.inf.ufpr.br/cursos/ci067/Docs/NotasAula/notas-29_Strings_Ponteiros.html
