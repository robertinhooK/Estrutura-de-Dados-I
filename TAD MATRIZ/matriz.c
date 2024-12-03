// TAD MAtriz
// Trabalho de Estrutura de Dados 2023.2
// Feito por Rôberth Kaua
// Programa criado e executado no IDE 'Replit'

#ifndef MATRIZ_C
#define MATRIZ_C

#include "matriz.h"
#include <stdlib.h>

//--------------------------------------------------------------------------------

struct matriz {
  int lin;
  int col;
  float *v;
};

//--------------------------------------------------------------------------------

// aloca e retorna uma matriz

Matriz *criarMatriz(int l, int c) {

  if (l > 0 && c > 0) {
    Matriz *matrizCriada = (Matriz *)malloc(sizeof(Matriz));
    if (matrizCriada != NULL) {
      matrizCriada->lin = l;
      matrizCriada->col = c;
      matrizCriada->v = (float *)malloc(sizeof(float) * l * c);
      if (matrizCriada->v != NULL) {
        return matrizCriada;
      }
      free(matrizCriada);
    }
  }
  return NULL;
}

//--------------------------------------------------------------------------------

// insere valores na matriz

int valoresDaMatriz(Matriz *matriz, int i, int j, float num) {
  int k;
  if (matriz != NULL) {
    if (i >= 0 && i < matriz->lin && j >= 0 && j < matriz->col) {
      k = i * matriz->col + j;
      matriz->v[k] = num;
      return TRUE;
    }
  }
  return FALSE;
}

//--------------------------------------------------------------------------------

// imprime a matriz

float imprimeMatriz(Matriz *matriz, int i) {

  if (matriz != NULL) {
    if (i >= 0) {
      return matriz->v[i];
    }
  }
  return FALSE;
}

//--------------------------------------------------------------------------------

// multiplica duas matrizes

Matriz *multiAB(Matriz *vma, Matriz *vmb) {

  if (vma != NULL && vmb != NULL) {
    if (vma->lin > 0 && vma->col > 0 && vmb->lin > 0 && vmb->col) {
      if (vma->col == vmb->lin) {
        Matriz *vmc = criarMatriz(vma->lin, vmb->col);
        if (vmc != NULL) {
          for (int i = 0; i < vma->lin; i++) {
            for (int j = 0; j < vmb->col; j++) {
              int aux = i * vmb->col + j;
              vmc->v[aux] = 0.0;
              for (int k = 0; k < vma->col; k++) {
                vmc->v[aux] += vma->v[i * vma->col + k] * vmb->v[k * vmb->col + j];
              }
            }
          }
          return vmc;
        }
      }
    }
  }
  return NULL;
}

//--------------------------------------------------------------------------------

// cria a transposta da matriz

Matriz *matrizTransposta(Matriz *matriz) {
  if (matriz != NULL) {
    Matriz *trans = criarMatriz(matriz->col, matriz->lin);
    if (trans != NULL) {
      for (int i = 0; i < trans->lin; i++) {
        for (int j = 0; j < trans->col; j++) {
          trans->v[i * trans->col + j] = matriz->v[j * trans->lin + i];
        }
      }
      return trans;
    }
  }
  return NULL;
}

//--------------------------------------------------------------------------------

// destroi a matriz

int destroiMatriz(Matriz *matriz) {

  if (matriz != NULL) {
    free(matriz->v);
    free(matriz);
    return TRUE;
  }
  return FALSE;
}

//--------------------------------------------------------------------------------

#endif