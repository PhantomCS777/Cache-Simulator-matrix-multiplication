#include<stdio.h>
#include<stdlib.h>
#include<time.h>



int main()
{
    int i, j, k;
    int n = 10; 
    int r = 0 ; 
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      for (k = 0; k < n; k++)
        r+=1; 
    }
    printf("%d\n", r);
}
