/*
Exercício 1:
Escreva um algoritmo em linguagem C com as seguintes instruções:
1. Declare três variáveis (inteiro, real e char);
2. Declare três ponteiros;
3. Associe as variáveis aos ponteiros;
4. Modifique os valores de cada variável ! indiretamente  usando os ponteiros associados!. 
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
  int a;
  float b;
  char c[1];

  //Declarando três ponteiros:
  int *ponta;
  float *pontb; 
  char *pontc; 
  
  //Associando as variáveis aos ponteiros:
  ponta = &a;
  pontb = &b;
  pontc = &c[0]; //OU pontc = c

  printf("________________ANTES________________\n"); 
  //Imprimindo na tela os valores das variáveis antes da modificação:
  
  printf("valor de a = %d \n", a);
  printf("valor de b = %.2f \n", b);
  printf("valor de c = %s \n", c);

  printf("\n");
  
  //Modificando os valores de cada variável indiretamente, usando os ponteiros associados:
  *ponta = 50; // Armazenando na variável inteira os dois últimos dígitos do meu RU.
  *pontb = 65.50; // Armazenando na variável real os 4 últimos dígitos do meu RU, sendo os 2 últimos os valores com virgula.
  *pontc = 'G'; //Armazenando na variável char a primeira letra do meu nome.
  
  printf("________________DEPOIS________________\n"); 
  //Imprimindo na tela os valores das variáveis após a modificação:
  
  printf("valor de a = %d \n", a);
  printf("valor de b = %.2f \n", b);
  printf("valor de c = %s \n", c);

  
  return 0; 
}

//system("pause"); //Não funciona no me shell
//system("read -p 'Press Enter to continue...' var"). <- Posso usar esse. 
//http://www.inf.ufpr.br/cursos/ci067/Docs/NotasAula/notas-29_Strings_Ponteiros.html
