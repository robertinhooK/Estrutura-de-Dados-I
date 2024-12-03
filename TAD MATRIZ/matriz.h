// TAD MAtriz
// Trabalho de Estrutura de Dados 2023.2
// Feito por Rôberth Kaua
// Programa criado e executado no IDE 'Replit'

#ifndef MATRIZ_H
#define MATRIZ_H
#define TRUE 1
#define FALSE 0

typedef struct matriz Matriz;

// aloca e retorna uma matriz
Matriz *criarMatriz(int l, int c);

// insere valores na matriz
int valoresDaMatriz(Matriz *matriz, int i, int j, float num);

// imprime a matriz
float imprimeMatriz(Matriz *matriz, int i);

// multiplica duas matrizes
Matriz *multiAB(Matriz *vma, Matriz *vmb);

// cria a transposta da matriz
Matriz *matrizTransposta(Matriz *matriz);

// destroi a matriz
int destroiMatriz (Matriz *matriz);

#endif