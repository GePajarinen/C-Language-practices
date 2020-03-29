//***************************************************
// A company did a market research to find out if the consumers liked their latest product or not. They collected the interviewee's gender and his answer (yes or no). Knowing that 150 people were interviewed, make an algorithm that calculates and shows:
// • The number of people who answered yes;
// • The number of people who answered no;
// • The percentage of women who answered yes;
// • The percentage of male who answered no;
//***************************************************

#include <stdio.h>
#include <stdlib.h>

int main(){

  int i, sim = 0, nao= 0, mulher= 0, homem = 0;
  char sexo, gostou, c; 

  float porcentH, porcentM;

  printf("\n ADD YOUR INFORMATIONS:\n\n");

  for (i=1; i <= 5; i++){ //i vai repetir o looping por 150 vezes.
  
    printf("Sexo do cliente: F ou M\n");
    scanf("%c", &sexo); 
    while ((c= getchar())!= '\n' && c!=EOF){} //Cleaning the buffer.
    
    printf("Cliente gostou: S OU N\n");
    scanf("%c", &gostou); 
    while ((c= getchar())!= '\n' && c!=EOF){} //Cleaning the buffer.

    if (gostou == 'S'){ //Counting all the YES = 's'
      sim++; 
      if (sexo == 'F'){ //Counting all the WOMEN who said YES
        mulher++;}
    }
    else { //Counting all the MEN who said NO = 'n'
      nao++;
      if (sexo == 'M'){ //Counting all the MEN who said NO
        homem++;}
      }
    }
    
    //The total of people who answered the research:
    
    porcentM = (float)(mulher*100)/ (sim+nao); 
    porcentH = (float)(homem*100)/(sim+nao);
    

    printf("\n *** RESULTS ***\n");

    printf("\n - Número de pessoas que responderam SIM:\n %5d\n", sim); //Number of people who said YES.
    
    printf("\n - Número de pessoas que responderam NÃO:\n %5d\n", nao); //Number of people who said NO.
    
    printf("\n - Porcentagem de MULHERES que responderam SIM:\n %5.1f%%\n", porcentM); //Percentage of women that said YES
    //total de MULHERES que responderam SIM dentre todas as pessoas.
    //total of WOMEN who answered YES out of all people.
    
    printf("\n - Porcentagem de HOMENS que responderam NÃO:\n %5.1f%%\n ", porcentH); //Percentage of men that said NO
    //total de HOMENS que responderam NÃO dentre todas as pessoas.
    //total of MEN who answered NO out of all people.


    system("pause");
    return 0;
}
