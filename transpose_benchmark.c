#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int * generate_random_matrix(int n){
  int * matrix = (int *) malloc(n*n*sizeof(int));
  for(int i = 0; i < n*n; i++){
    matrix[i] = rand() % 100;
  }
  return matrix;
}

void transposeIJ(int *A, int *C, int n){
  int i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      C[i*n+j] = A[j*n+i];
}

void transposeJI(int *A, int *C, int n){
  int i, j;
  for (j = 0; j < n; j++)
    for (i = 0; i < n; i++)
      C[i*n+j] = A[j*n+i];
}

void transposeInplaceIJ(int *A, int n){
  int i, j;
  for (i = 0; i < n; i++)
    for (j = i+1; j < n; j++){
      int temp = A[i*n+j];
      A[i*n+j] = A[j*n+i];
      A[j*n+i] = temp;
    }
}

void transposeInplaceJI(int *A, int n){
  int i, j;
  for (j = 0; j < n; j++)
    for (i = j+1; i < n; i++){
      int temp = A[i*n+j];
      A[i*n+j] = A[j*n+i];
      A[j*n+i] = temp;
    }
}

int main()
{
    int n = 4096;
    int av = 5 ; 
    int den = av ; 

    FILE *file = fopen("/Users/hg/Documents/GitHub/Cache-Simulator-matrix-multiplication/InplaceJI.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    for(int i = 32; i <=n; i+=32)
    {
        av = den; 
        double cpu_time_used = 0 ;
        printf("n = %d\n", i);
        while(av--){
            int *A = generate_random_matrix(i);
            // int *C = generate_random_matrix(i);
            // int i, j;
            clock_t start, end;
            start = clock();
            transposeInplaceJI(A,i);
            end = clock();
            free(A);
            // free(C);
            // free(C);
            cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
        }

        cpu_time_used /= den;
        fprintf(file, "%d , %f \n", i, cpu_time_used);
    }
   fclose(file);
    return 0;
}
