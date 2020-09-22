/*
Write a function that takes two strings as parameters, as well as an integer value that represents a position. 
The function must insert the second string at the indicated position of the first one and it should display the user's result.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //<--Library to work with strings

/*
For this project will be used the following:

- strncpy -: copies a specified bytes of characters from source to destination.

- strcat -: The function strcat() concatenates two strings. It takes two arguments, i.e, two strings or character arrays, and stores the resultant concatenated string in the first string specified in the argument. 

- strcpy -: The strcpy() function copies the string to the another character array.

Text Source:
<https://www.programiz.com/cpp-programming/library-function/cstring>
*/


void juntando(char primeira[], char segunda[], int num){
  char resultado[50];

  strncpy(resultado, primeira, num);
  // Corta a primeira palavra até o número que foi indicado e guarda em ´resultado´:
  // Exe.: primeira = Gesiane, num= 4
  // resultado = Gesi
 
  /*----------TESTE------------*/
  //printf("strncpy= %s \n", resultado);

  strcat(resultado, segunda);
  //Contaterna o resultado anterior com a segunda palavra:
  //Ex.: segunda = Pajarinen
  //resultado = GesiPajarinen
  
  /*----------TESTE------------*/
  //printf("strcat - segunda = %s \n", resultado);

  strcat(resultado,&primeira[num]);
  //Concaterna o resultado aterior com o resto da primeira palavra:
  //&primeira[num] = ane
  //resultado = GesiPajarinenane
  
  /*----------TESTE------------*/
  //printf("&primeira[num] = %s \n", &primeira[num]);
  /*----------TESTE------------*/
  //printf("strcat - &primeira[num] = %s \n", resultado);

  strcpy(primeira, resultado);
  //Copia o valor de 'resultado' para o valor de 'primeira', que será impresso como resultado final no MAIN. (Tentei colocar primeira = resultado mas nao dá certo.)
  
  /*----------TESTE------------*/
  //printf("strcpy - primeira + resultado = %s \n", resultado);

}

int main( ) {

  char primeira[50], segunda[50];
  int num;

//Pedindo a entrada dos dados:
  printf("Digite uma palavra: \n>> "); //Priemira palavra
  scanf("%s", primeira);
  printf("Digite outra palavra: \n>> "); //Segunda palavra
  scanf("%s", segunda);
  printf("Digite um número: \n>> "); //Número
  scanf("%d", &num);
  
//Mostrando os dados:
  printf("\nColocando a segunda palavra '%s'", segunda);
  printf(" no lugar '%d'", num);
  printf(" da primeira palavra '%s', teremos: \n", primeira);

//Chamando a funcao:

  juntando( primeira,  segunda,  num); 

//Imprimir o resultado:

  printf("------------------------\n");
  printf(" %s \n", primeira);
  printf("------------------------\n");


  system ("pause");
  return 0;
}
