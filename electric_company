//******************************************************************
// For each of the electricity consumers in a city, the account number and the total KW consumed in the month are informed. Knowing that the cost of the each KW is R $ 1.75, make an algorithm to:
// • Store and list the account number, the total KW consumed and the how much to pay for each registered consumer;
// • List the account number, the total KW consumed and the amount to be paied by the consumer who spent the most and least spent;
// • Show the average consumption of the city;
// • Show the number of consumers that exceeded 170 KW;
// Store information in vector and / or matrix structures. On the screen should be a MENU for the user to register a new account or to view the above informations
//******************************************************************

#include <stdio.h>
#include <stdlib.h>

#define kw 1.75 //Queria colocar como constante
#define clientes 5 //Variável global

int c; //Cleaning the buffer

//FUNÇÂO: Calcular o total a pagar: //Calculates the total to pay:

float calculo(gasto){
  float total;

  total = kw * gasto; 
  return total;
}

//FUNÇÂO: Imprimir a tabela dos consumidores e suas respectivas informações:
//Prints the table with the information of all the registered consumers.

void imprimir(float matrix[clientes][3]){
  
  printf("\n    CLIENTES CADASTRADOS\n"); 

  printf("\n------------------------------\n");
  printf("Cadastro |   Kw   | A pagar"); 
  printf("\n------------------------------\n");
  
  for (int i= 0; i<clientes; i++){ 
    for(int j=0; j<3; j++){
      printf("%7.2f | ", matrix[i][j]);
    }
    printf("\n");
  }
} 

//FUNÇÂO: Quem gastou MAIS: 
//The account with the max consumption

void mais_gastou(float matrix[clientes][3]){

  float maior;

  for (int i=1; i<clientes; i++){ //Looping de comparacao entre os valores da matriz.

    if (matrix[0][1] < matrix[i][1]){ 
      matrix[0][1] = matrix[i][1]; //Se o valor do índice[0] for menor que o valor do índie[1], índice[0] recebe o valor de índie[1]. Caso contrário, índie[0] continua com seu valor.
      matrix[0][0] = matrix[i][0]; //De acordo com a comparação dos valores, o sistema busca o número do cadastro que é correspondente
    } 
    //O índice [0] se compara com o primeiro e fica estável, só recebendo os outros valores para comparacao. No final, ele recebe o maior valor.

    maior = matrix[0][0]; //Substituindo o valor do kw pela sua referência "Cadastro".
  }
  printf("\n* MAIOR consumo de Kw.\n Cliente número:\n %.0f com %.0fKW\n", maior, matrix[0][1]);
}
  
//FUNÇÂO: Quem gastou MENOS:
//The account with the minimum consumption

void menos_gastou(float matrix[clientes][3]){
  
  float menor; 

  for (int i=1; i<clientes; i++){

    if (matrix[0][1] > matrix[i][1]){
      matrix[0][1] = matrix[i][1]; //Se o valor do índice[0] for maior que o valor do índie[1], índice[0] recebe o valor de índie[1]. Caso contrário, índie[0] continua com seu valor.
      matrix[0][0] = matrix[i][0]; //De acordo com a comparação dos valores, o sistema busca o número do cadastro que é correspondente
    } 
    //O índice [0] se compara com o primeiro e fica estável, só recebendo os outros valores para comparacao. No final, ele recebe o maior valor.

    menor = matrix[0][0]; //Substituindo o valor do kw pela sua referência "Cadastro".
  }
 
  printf("\n* MENOR consumo de Kw.\n Cliente número:\n %.0f com %.0fKW\n", menor, matrix[0][1]); 

}

//FUNÇÂO: Consumo MEDIO:
//Average consumption of the city

int consumo_medio(float matrix[clientes][3]){
  //se colocar VOID o resultado dá errado.
  int media;

  for (int i=0; i<clientes; i++){
    media += matrix[i][1]; //Soma todos os valores da coluna da matriz.
  }

  printf("\n* MÉDIA de consumo da cidade é:\n %.0d Kw \n", media/clientes); //O resultado da soma é dividido pelo número de clientes no cadastro.
}

//FUNÇÂO: Quantos ACIMA de 170KW:

void acima_170(float matrix[clientes][3]){
  
  int amais=0; //Tava dando errado porque nao tinha dado valor de 0 para esta variavel

  for (int i=0; i<clientes; i++){
    if (matrix[i][1] > 170){ 
      amais++; //O looping vai ver quantos valores estão acima de 170 e caso verdadeiro, adiciona 1 para a variavel contadora.
    } else{
      amais = amais; //Caso falso, o valor da contadora permanece.
    }
  }
  printf("\n* Número de clientes ACIMA de 170Kw:\n %d\n", amais);  
}

//FUNÇÂO: Cadastrar NOVO CLIENTE:

void cadastro(float matrix[clientes][3]){
  int add= clientes +1; //Almentar o índice de linhas da matrix

  
  printf("Número de cadastro: \n"); //O usuário coloca o número do cadastro
  printf(">> "); //Indicar ao usuário uma espera da resposta.
  scanf("%f", &matrix[add][0]);
  while ((c= getchar())!= '\n' && c!=EOF){};//Cleaning the buffer

  printf("Quantidade de Kw consumidos: \n"); //O usuário coloca a quantidade de KW.
  printf(">> "); //Indicar ao usuário uma espera da resposta.
  scanf("%f", &matrix[add][1]);
  while ((c= getchar())!= '\n' && c!=EOF){};//Cleaning the buffer
  
  matrix[add][2] = calculo(matrix[add][1]); //A função calculo calcula o valor a ser pago.
  
  
  printf("\n- NOVO CLIENTE CADASTRADO COM SUCESSO! \n");
  
  printf(" *Cadastro no.: %.0f \n *Kw: %.0f \n *Total a pagar: %.2f\n\n", matrix[add][0], matrix[add][1], matrix[add][2]); //Impressão das informações dadas: Cadastro, Kw e valor a pagar.

}

//FUNÇÂO: MENU.

void menu(float matrix[clientes][3]){
  int opcao;

 printf("\n******************************************\n");
 printf("****              MENU                ****\n");
 printf("******************************************\n");
 printf("Escolha uma das opções: \n\n");
 printf("1 - Consumidor com MAIOR gasto \n");
 printf("2 - Consumidor com MENOR gasto \n");
 printf("3 - Quantidade de consumidores ACIMA de 170Kw \n");
 printf("4 - Consumo MÉDIO da cidade (em Kw) \n");
 printf("5 - Cadastro de NOVO CLIENTE \n");

 printf(">> "); //Indicar ao usuário uma espera da resposta.
 scanf("%d", &opcao);
 while ((c= getchar())!= '\n' && c!=EOF){};//Limpeza de buffer

 if ((opcao >=1)&&(opcao <=5)){
  switch (opcao){
    case 1:
      mais_gastou(matrix); //Chama a função de quem gastou mais.
    break;

    case 2:
      menos_gastou(matrix); //Chama a função de quem gastou menos.
    break;

    case 3:
      acima_170(matrix); //Chama a função de quantos gastaram acima de 170.
    break;

    case 4:
      consumo_medio(matrix); //Chama a função do consumo médio da cidade.
    break;

    case 5:
      cadastro(matrix); //Chama a função para cadastro de cliente.
    break;

    default:
    break;
    } 
  } else {
    printf("Por favor, escolha uma opção válida."); //Se escolher opcao inválida
    }

    char voltar; 
    
    printf("\nDeseja voltar ao Menu? s/n\n"); //Opcao de voltar ao MENU
    printf(">> ");//Indicar ao usuário uma espera da resposta.
    scanf("%c", &voltar);
    while ((c= getchar())!= '\n' && c!=EOF){};//Limpeza de buffer
    
    if (voltar== 's'){ //Opcao de voltar ao MENU é SIM chama a função menu().
        menu(matrix);
    }
    else{
      printf("\n---Agradecemos seu contato.---\n\n"); //Opcao de voltar ao MENU é NAO imprime um agradecimento na tela.
    }
}


// ******************************************
// ****              MAIN                ****
// ******************************************

int main() {

  int numConta, totalKm, valPagar; //Variáveis da função
    
  // Clientes já cadastrados:

  float regis[clientes][3] = {
  {1234, 110, calculo(regis[0][1])}, 
  {2345, 200, calculo(regis[1][1])}, 
  {3456, 34, calculo(regis[2][1])}, 
  {4567, 77, calculo(regis[3][1])}, 
  {5678, 89, calculo(regis[4][1])}
  };

  imprimir(regis); //Chama a função de imprimir a tabela dos clientes já cadastrados.
  
  printf("\n");
  
  menu(regis); //Chama a função MENU para dar início ao atendimento.

  system ("pause");
  return 0;
}

//** REFERÊNCIAS
// sobre funcoes com matrizes: <https://www.programiz.com/c-programming/c-arrays-functions>

// sobre looping de comparações: <https://www.programiz.com/c-programming/examples/array-largest-element>
