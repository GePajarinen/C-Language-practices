/*
"A magic square is a square grid (where n is the number of cells on each side) filled with distinct positive integers in the range, 
such that each cell contains a different integer and the sum of the integers in each row, column and diagonal is equal." (wikipedia)
Given a matrix with the dimension DxD, check if the square is magic or not using an algorithm. 
*/

#include <stdio.h>
#include<stdlib.h>

int main() {

  int tam, i, j, lincol, somadiago, x;
  int linha[i], coluna[i], dia1, dia2;

//Pedido para o usuário criar a matriz

  printf("Qual o tamanho da sua matriz?\n>> ");//Definindo o tamanho da matriz.
  scanf("%d", &tam);

  int matriz[tam][tam];

  for (i=0; i<tam; i++){ //Looping para montar a matriz
    for (j=0; j<tam; j++){
      printf("Digite um número para a posição [%d][%d]: \n>> ", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }

//Imprimindo a matriz

  printf("\nA sua matriz ficou assim: \n"); //Looping para imprimir a matriz
  for (i=0; i<tam; i++){
    for (j=0; j<tam; j++){
      printf("%d ",matriz[i][j]);
    }
    printf("\n");
  }

//Somando as Linhas (e as Colunas)

    for (j=0; j<tam; j++){ 
  for (i=0; i<tam; i++){ 
      linha[i] += matriz[i][j]; //Looping para somar os valores das linhas 
      coluna[i] += matriz[j][i]; //e colunas. //Achei que desse para somar as colunas ao mesmo tempo. FUNCIONA!
    }
  }

//Somando as colunas

  // for (i=0; i<tam; i++){
  //   for (j=0; j<tam; j++){
  //     coluna[i] += matriz[j][i];
  //   }
  // } 
  
//Comparando a soma das linhas e colunas

  for (i=0; i<tam; i++){
     //Nao consegui usar boolean

    if (linha[i] == coluna[i]){ //Se a soma da linha for igual a soma da coluna
      lincol = 1;   //A variavel lincol recebe 1 caso contrário, recebe 0. 
    } else{
      lincol = 0;
    }
  }

//Somando os valores da diagonal Principal
//Adicionei no mesmo cálculo da diagonal secundária
  // for (i=0; i<tam; i++){
  //     dia1 += matriz[i][i]; 
  // }

//Teste:
  //printf("diagonal1  = %d \n", dia1);

// Esse Não funciona por nada no mundo: 
//Tentei um lopping pra somar os valores da diagonal secundária.
  // for (i=(tam-1); i<0; i--){
  //   for (j=0; j<tam; j++){
  //     int x = i + j;
  //     if (x == (tam-1)){
  //       dia2 += matriz[i][j];
  //     } 
  //   }
  // } 


//Esse funcionou mas dá sempre uma unidade à mais que a soma correta:

  for (i=0; i<tam; i++){
    dia1 += matriz[i][i]; //Soma da diagonal principal 
    for (j=0; j<tam;j++){
      if (j==(tam-1)-i){
        dia2 += matriz[i][j]; //Soma da diagonal secundária
      } 
    }
  }

//Como resulta sempre em uma unidade à mais na soma, por isso: 

  dia2 = dia2-1;

//Teste:
//printf("\n diagona2 = %d \n", dia2);
  
//Comparando as somas das diagonais principal e secundária:
 
  if (dia1 == dia2){ //Se a soma de cada diagonal for igual, somadiago recebe 1, caso contrário, recebe 0.
    somadiago = 1;
  } else{
    somadiago = 0;
  }

//É mágico ou nao:

  if (lincol == 1 && somadiago == 1){ //Se na comparacao de linhas e colunas o lincol recebeu valor igual a 1, elas são de mesmo valor. E se somadiago também recebeu 1, o quadro é mágico porque todas as somas, de linhas, colunas e diagonais são iguais.
    printf("\n    *********\n");
    printf("O seu Quadrado É MÁGICO!!\n");
    printf("    *********\n");
  } else{ //Se não, se lincol e/ou somadiago recebeu valor 0, é porque as somas não são iguais e o quadro não é mágico.
    printf("\n    *******************\n");
    printf("O seu Quadrado NÃO é Mágico. :( \n");
    printf("    *******************\n");
  }


  system("pause");
  return 0;
}
