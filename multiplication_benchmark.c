#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void matmultIJK(int *A, int *B, int *C, int n) {
  int i, j, k;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      for (k = 0; k < n; k++)
        C[i*n+j] += A[i*n+k] * B[k*n+j];
    }
}

void matmultJIK(int *A, int *B, int *C, int n) {
  int i, j, k;
  for (j = 0; j < n; j++)
    for (i = 0; i < n; i++){
      for (k = 0; k < n; k++)
      C[i*n+j] += A[i*n+k] * B[k*n+j];
    }
}

void matmultIKJ(int *A, int *B, int *C, int n) {
  int i, j, k;
  for (i = 0; i < n; i++)
    for (k = 0; k < n; k++){
      for (j = 0; j < n; j++)
       C[i*n+j] += A[i*n+k] * B[k*n+j];
    }
}

void matmultKIJ(int *A, int *B, int *C, int n) {
  int i, j, k;
  for (k = 0; k < n; k++)
    for (i = 0; i < n; i++){
      for (j = 0; j < n; j++)
      C[i*n+j] += A[i*n+k] * B[k*n+j];
    }
}

void matmultKJI(int *A, int *B, int *C, int n) {
  int i, j, k;
  for (k = 0; k < n; k++)
    for (j = 0; j < n; j++){
      for (i = 0; i < n; i++)
      C[i*n+j] += A[i*n+k] * B[k*n+j];
    }
}

void matmultJKI(int *A, int *B, int *C, int n) {
  int i, j, k;
  for (j = 0; j < n; j++)
    for (k = 0; k < n; k++){
      for (i = 0; i < n; i++)
      C[i*n+j] += A[i*n+k] * B[k*n+j];
    }
}


void print_matrix(int * matrix, int n){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      printf("%d ", matrix[i*n+j]);
    }
    printf("\n");
  }
}


int * generate_random_matrix(int n){
  int * matrix = (int *) malloc(n*n*sizeof(int));
  for(int i = 0; i < n*n; i++){
    matrix[i] = rand() % 100;
  }
  return matrix;
}

int * generate_zero_matrix(int n){
  int * matrix = (int *) malloc(n*n*sizeof(int));
  for(int i = 0; i < n*n; i++){
    matrix[i] = 0;
  }
  return matrix;
} 



int main()
{
    int av = 5; 
    int den = av ; 
    int n = 2048; 
    FILE *file = fopen("/Users/hg/Documents/GitHub/Cache-Simulator-matrix-multiplication/JKI.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    for(int i = 32 ; i <= n ; i+=32)
    {
        printf("n = %d\n", i);
        av = den;
        double cpu_time_used = 0;
        while(av--)
        {
            int * A = generate_random_matrix(i);
            int * B = generate_random_matrix(i);
            int * C = generate_zero_matrix(i); 

            clock_t start, end;    
            start = clock();
            matmultJKI(A, B, C, i);
            end = clock();
            cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
            free(A);
            free(B);
            free(C);
        }
        cpu_time_used /= den;
        fprintf(file, "%d , %f \n", i, cpu_time_used);
    }
    
    fclose(file);
    return 0;
}



