/*
AULA 05
Faça um algoritmo em linguagem C que contenha dois números inteiros digitados na tela pelo usuário:
a. O primeiro número marca um início;
b. O segundo número marca um fim;
O algoritmo vai contar quantos números existem entre o início (primeira entrada) e o fim (segunda entrada). 
A impressão na tela do usuário deve ser realizada de duas formas:
a. Iterativa;
b. Recursiva;
Ao colocar no seu relatório uma imagem do seu código funcionando, coloque ele
  rodando utilizando como valor de inicio os 2 últimos valores do seu RU e valor final
  o número 99.
RU 2466550
*/

#include <stdio.h>
#include <stdlib.h>

int contandoNumeros (); //Anunciando a função que vai ser usada no main.

int main(){
  
  //Declarando as variáveis:
  int inicio, fim, resultado;

  printf("\n\n- - - - - - - - - - - - - - - - - - - - \n\n"); //Para melhorar a aparência na execução do código.

  //Pedindo as entradas do usuário:
  printf("Digite o primeiro número: \n >> ");
  scanf("%d", &inicio); //ADICIONAR _S //Número inicial.

  printf("Digite o segundo número (maior que o primeiro): \n >> ");
  scanf("%d", &fim); //ADICIONAR _S //Número final.
 
  printf("Entre os números %d e %d, temos: \n\n", inicio, fim);

  //Iterativa:
  printf(" - Processando de forma Iterativa: \n");

  for (int i= inicio+1; i<fim; i++){
  printf("%d, ", i);
  };
  
  printf("\n");
  
  //Recursiva:
  printf("\n - Processando de forma Recursiva: \n");

  //Chamando a função com seus argumentos:
  return contandoNumeros (inicio, fim); 

  printf("\n\n- - - - - - - - - - - - - - - - - - - - \n\n"); //Para melhorar a aparência na execução do código.

  //sistem("pause");
  return 0;
}

//Função Recursiva:

/* USANDO FOR:
int contandoNumeros (int num1, int num2){
  
  for (int i= num1+1; i<num2; i++){
    printf("%d, ", i);
    return contandoNumeros((i), num2);
  }
};
*/

//USANDO WHILE:
int contandoNumeros (int num1, int num2) {
  num1++; 
  
  while (num1<num2) {//Enquanto o num1 for menor que num2:
    
    printf("%d, ", num1); //Imprima o valor de num1 já com o acrescrécimo dado no início da função.
    return contandoNumeros(num1, num2);  //e refaça a função com o novo valor de num1.
  };
  printf("\n\n- - - - - - - - - - - - - - - - - - - - \n\n"); //Para melhorar a aparência na execução do código.
  return 0;
}