// TAD MAtriz
// Trabalho de Estrutura de Dados 2023.2
// Feito por Rôberth Kaua
// Programa criado e executado no IDE 'Replit'

#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(void) {

  int la, ca, lb, cb;
  int j = 0;
  int aCriada = 0, bCriada = 0;
  int escolha;

  Matriz *a = NULL, *b = NULL;
  
  do {

 printf("\033[H\033[J");

  // menu
  printf("\nOla! Escolha uma das opcoes abaixo:\n\n");

  printf("1. Criar  a matriz A\n");
  printf("2. Criar  a matriz B\n");
  printf("3. Ler e inserir os dados da matriz A\n");
  printf("4. Ler e inserir os dados da matriz B\n");
  printf("5. Imprimir a matriz A\n");
  printf("6. Imprimir a matriz B\n");
  printf("7. Calcular a multiplicacao de A por B\n");
  printf("8. Calcular a multiplicacao de B por A\n");
  printf("9. Calcular a transposta de A\n");
  printf("10. Calcular a transposta de B\n");
  printf("11. Destruir a matriz A\n");
  printf("12. Destruir a matriz B\n");
  printf("0. Sair\n");

  printf("\nSua escolha: ");
  scanf("%d", &escolha);
  
  // Realiza a ação com base na escolha do usuário
  switch (escolha) {

//-------------------------------------------------------------------------------
    
  case 1:
    if(aCriada != 1) {
    printf("\nCerto! Agora informe o numero de linhas e colunas da Matriz A: ");
    scanf("%d %d", &la, &ca);
    a = criarMatriz(la, ca);
    if (a != NULL) {
      aCriada = 1;
      printf("\nMatriz 'A' (matriz nula) criada!\n");
    }
    else {
      printf("\nErro ao criar a matriz!\n");
    }
    break;
    }
    else {
      printf("\nA Matriz 'A' ja foi criada!\n");
    }
    break;

//-------------------------------------------------------------------------------
    
  case 2:
    if(bCriada != 1) {
      printf("\nCerto! Agora informe o numero de linhas e colunas da Matriz B: ");
      scanf("%d %d", &lb, &cb);
      b = criarMatriz(lb, cb);
      if (b != NULL) {
        bCriada = 1;
        printf("\nMatriz 'B' (matriz nula) criada!\n");
      }
      else {
        printf("\nErro ao criar a matriz!\n");
      }
    }
    else {
      printf("\nA Matriz 'B' ja foi criada!\n");
    }
    break;

//-------------------------------------------------------------------------------
    
  case 3:
    if (a != NULL) {
      printf("\nInforme os valores da Matriz A: \n");
      for(int i = 0; i < la; i++) {
        for(int j = 0; j < ca; j++) {
          float aux = 0;
          printf("\nMatriz A[%d][%d] = ", i, j);
          scanf("%f", &aux);
          if(valoresDaMatriz (a, i, j, aux) == FALSE) {
            printf("Erro em atribuir o valor!\n");
            printf("Programa paralisado!\n");
            break;
          }
          else {
            printf("Valor Atribuido!\n");
          }
        }
      }
    }
    else {
      printf("\nA Matriz 'A' nao existe ainda!\n");
    }
    break;

//-------------------------------------------------------------------------------
    
  case 4:
    if (b != NULL) {
      printf("\nInforme os valores da Matriz B: \n");
      for(int i = 0; i < lb; i++) {
        for(int j = 0; j < cb; j++) {
          float aux = 0;
          printf("\nMatriz B[%d][%d] = ", i, j);
          scanf("%f", &aux);
          if(valoresDaMatriz (b, i, j, aux) == FALSE) {
            printf("Erro em atribuir o valor!\n");
            printf("Programa paralisado!\n");
            break;
          }
          else {
            printf("Valor Atribuido!\n");
          }
        }
      }
    }
    else {
      printf("\nA Matriz 'B' nao existe ainda!\n");
    }
    break;

//-------------------------------------------------------------------------------
    
  case 5:
    if (a != NULL) {
      printf("\nMatriz A:\n\n");
      for(int i = 0; i < (la * ca); i++) {
        printf("%.1f ", imprimeMatriz (a, i));
        j++;
        if(j == ca) {
          printf("\n");
          j = 0;
        }
      }
    }
    else {
      printf("\nA Matriz 'A' nao existe ainda!\n");
    }
    break;

//-------------------------------------------------------------------------------
    
  case 6:
    if (b != NULL) {
      printf("\nMatriz B:\n\n");
      for(int i = 0; i < (lb * cb); i++) {
        printf("%.1f ", imprimeMatriz (b, i));
        j++;
        if(j == cb) {
          printf("\n");
          j = 0;
        }
      }
    }
    else {
      printf("\nA Matriz 'B' nao existe ainda!\n");
    }
    break;

//-------------------------------------------------------------------------------
    
  case 7:
    if(a != NULL && b != NULL) {
      if(ca == lb) {
        if(multiAB(a, b) != NULL) {
          printf("\nMatrizes A e B Multiplicadas!\n\n");
          for(int i = 0; i < (la * cb); i++) {
            printf("%.1f ", imprimeMatriz (multiAB(a, b), i));
            j++;
            if(j == cb) {
              printf("\n");
              j = 0;
            }
          }
        }
        else {
          printf("\nErro na multiplicação das matrizes!\n");
        }
      }
      else {
        printf("\nAs matrizes nao podem ser multiplicadas!\n");
      }
    }
    else {
      printf("\nErro... Ambas as matrizes precisam existir!\n");
    }
    break;
    
//-------------------------------------------------------------------------------

  case 8:
    if(a != NULL && b != NULL) {
      if(cb == la) {
        if(multiAB(b, a) != NULL) {
          printf("\nMatrizes B e A Multiplicadas!\n\n");
          for(int i = 0; i < (lb * ca); i++) {
            printf("%.1f ", imprimeMatriz (multiAB(b, a), i));
            j++;
            if(j == ca) {
              printf("\n");
              j = 0;
            }
          }
        }
        else {
          printf("\nErro na multiplicação das matrizes!\n");
        }
      }
      else {
        printf("\nAs matrizes nao podem ser multiplicadas!\n");
      }
    }
    else {
      printf("\nErro... Ambas as matrizes precisam existir!\n");
    }
    break;

//-------------------------------------------------------------------------------
    
  case 9:
    if (a != NULL) {
      printf("\nRelembre a Matriz A:\n\n");
      for(int i = 0; i < (la * ca); i++) {
        printf("%.1f ", imprimeMatriz (a, i));
        j++;
        if(j == ca) {
          printf("\n");
          j = 0;
        }
      }
      
      printf("\nTransposta da Matriz A:\n\n");
      for(int i = 0; i < (la * ca); i++) {
        printf("%.1f ", imprimeMatriz (matrizTransposta(a), i));
        j++;
        if(j == la) {
          printf("\n");
          j = 0;
        }
      }
    }
    else {
      printf("\nA Matriz 'A' nao existe ainda!\n");
    }
    break;

//-------------------------------------------------------------------------------
    
  case 10:
    if (b != NULL) {
      printf("\nRelembre a Matriz B:\n\n");
      for(int i = 0; i < (lb * cb); i++) {
        printf("%.1f ", imprimeMatriz (b, i));
        j++;
        if(j == cb) {
          printf("\n");
          j = 0;
        }
      }
      
      printf("\nTransposta da Matriz B:\n\n");
      for(int i = 0; i < (lb * cb); i++) {
        printf("%.1f ", imprimeMatriz (matrizTransposta(b), i));
        j++;
        if(j == lb) {
          printf("\n");
          j = 0;
        }
      }
    }
    else {
      printf("\nA Matriz 'B' nao existe ainda!\n");
    }
    break;
    
//-------------------------------------------------------------------------------
    
  case 11:
    if(destroiMatriz(a) == TRUE) {
      printf("\nMatriz 'A' destruida!\n");
      aCriada = 0;
      a = NULL;
    }
    else {
      printf("\nMatriz 'A' nem existe... nao pode nao destruida!\n");
    }
    break;

//-------------------------------------------------------------------------------
    
  case 12:
    if(destroiMatriz(b) == TRUE) {
      printf("\nMatriz 'B' destruida!\n");
      bCriada = 0;
      b = NULL;
    }
    else {
      printf("\nMatriz 'B' nem existe... nao pode nao destruida!\n");
    }
    break;

//-------------------------------------------------------------------------------    
    
  case 0:
    printf("\nSaindo do programa... Adeus!\n");
    destroiMatriz(a);
    destroiMatriz(b);
    destroiMatriz(multiAB(a, b));
    destroiMatriz(multiAB(b, a));
    destroiMatriz(matrizTransposta(a));
    destroiMatriz(matrizTransposta(b));
    break;

//-------------------------------------------------------------------------------
    
  default:
    printf("\nOpcao invalida... Tente novamente!\n");
    break;
  }

//-------------------------------------------------------------------------------

    printf("\nPressione Enter para continuar...");
    getchar(); // Captura o Enter anterior
    getchar(); // Aguarda o Enter do usuário

  } while (escolha != 0); // Repete até a opcao 'sair' ser escolhida

  return 0;
}