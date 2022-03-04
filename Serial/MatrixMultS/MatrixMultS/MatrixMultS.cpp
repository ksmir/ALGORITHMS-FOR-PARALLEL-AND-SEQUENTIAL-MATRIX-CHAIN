#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>


void RandomDataInitialization (double* pAMatrix, double* pBMatrix, 
  int Size) {
  int i, j;
  srand(unsigned(clock()));
  for (i=0; i<Size; i++) 
    for (j=0; j<Size; j++) {
      pAMatrix[i*Size+j] = rand()/double(1000);
      pBMatrix[i*Size+j] = rand()/double(1000);
  }
}

void ProcessInitialization (double* &pAMatrix, double* &pBMatrix, 
  double* &pCMatrix, int &Size) {
  
    printf("\nEnter size: ");
    scanf("%d", &Size);
    
  pAMatrix = new double [Size*Size];
  pBMatrix = new double [Size*Size];
  pCMatrix = new double [Size*Size];

  RandomDataInitialization(pAMatrix, pBMatrix, Size);
  for (int i=0; i<Size*Size; i++) {
    pCMatrix[i] = 0;
  }
}

void PrintMatrix (double* pMatrix, int RowCount, int ColCount) {
  int i, j; 
  for (i=0; i<RowCount; i++) {
    for (j=0; j<ColCount; j++)
      printf("%7.4f ", pMatrix[i*RowCount+j]);
      printf("\n");
  }
}

void SerialResultCalculation(double* pAMatrix, double* pBMatrix, 
  double* pCMatrix, int Size) {
  int i, j, k;  
  for (i=0; i<Size; i++) { 
    for (j=0; j<Size; j++)
      for (k=0; k<Size; k++)
        pCMatrix[i*Size+j] += pAMatrix[i*Size+k]*pBMatrix[k*Size+j];
  }
}

void ProcessTermination (double* pAMatrix, double* pBMatrix, 
  double* pCMatrix) {
  delete [] pAMatrix;
  delete [] pBMatrix;
  delete [] pCMatrix;
}

void main() {
  double* pAMatrix;  
  double* pBMatrix;  
  double* pCMatrix; 
  int Size;		   
  double start, finish, duration;

  printf("Serial matrix multiplication program\n");
  ProcessInitialization(pAMatrix, pBMatrix, pCMatrix, Size);

  printf ("\n Matrix A: \n"); 
  PrintMatrix(pAMatrix, Size, Size);
  printf("\n Matrix B: \n");
  PrintMatrix(pBMatrix, Size, Size);

  start = GetTickCount();
  SerialResultCalculation(pAMatrix, pBMatrix, pCMatrix, Size);
  finish = GetTickCount();
  duration = (finish-start)*1000;
  printf ("\n Result Matrix: \n");
  PrintMatrix(pCMatrix, Size, Size);
  printf("\n Time: %10.5f\n", duration);

  ProcessTermination(pAMatrix, pBMatrix, pCMatrix);
  getch();
}

