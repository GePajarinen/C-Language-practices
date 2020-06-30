/*
Exercício 1:
Escreva um algoritmo em linguagem C com as seguintes instruções:
1. Declare três variáveis (inteiro, real e char);
2. Declare três ponteiros;
3. Associe as variáveis aos ponteiros;
4. Modifique os valores de cada variável indiretamente usando os ponteiros
associados. Para armazenar os valores nas variáveis, armazene na variável
char a primeira letra do seu nome, na variável inteira os dois últimos dígitos
do seu RU e na variável real os 4 últimos dígitos do seu RU, sendo os 2
últimos os valores com virgula;
5. Imprima na tela os valores das variáveis antes e após a modificação.
*/

#include <stdio.h> 
#include <stdlib.h>

int main() {
  int a;
  float b;
  char c[4];

  int* pa = &a; 
  float* pb = &b; 
  char *pc = &c; 
  //pc = (const char*)&c;

  printf("________________ANTES________________\n");
  printf("Endereco a = %p - valor de a = %d\n", &a, a);
  printf("Endereco b = %p - valor de b = %.2f\n", &b, b);
  printf("Endereco c = %p - valor de c = %s\n", &c, c);

  printf("\n");

  printf("Endereco pa = %p - valor de pa = %d\n", &pa, *pa);
  printf("Endereco pb = %p - valor de pb = %.2f\n", &pb, *pb);
  printf("Endereco pc = %p - valor de pc = %c\n", &pc, *pc);

  printf("\n");
  printf("________________DEPOIS________________\n");
  
  *pa = 50;
  *pb = 65.50;
  pc = "G";


  printf("Endereco a = %p - valor de a = %d\n", &a, a);
  printf("Endereco b = %p - valor de b = %.2f\n", &b, b);
  printf("Endereco c = %p - valor de c = %s\n", &c, c);

  printf("\n");

  printf("Endereco pa = %p - valor de pa = %d\n", &pa, *pa);
  printf("Endereco pb = %p - valor de pb = %.2f\n", &pb, *pb);
  printf("Endereco pc = %p - valor de pc = %c\n", &pc, *pc);

  system("pause"); 
  return 0; 
}