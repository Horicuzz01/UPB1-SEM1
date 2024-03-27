#include <stdio.h>
#include <stdlib.h>

int main()
{

    //dynamic allocation of memory for a matrix of l*c
    int l, c;
    printf("Enter the number of lines and columns: ");
    scanf("%d %d", &l, &c);
    int **matrix = (int **)malloc(l * sizeof(int *));
    for (int i = 0; i < l; i++)
    {
        matrix[i] = (int *)malloc(c * sizeof(int));

        for (int j = 0; j < c; j++)
        {
            printf("Enter the element at position %d %d: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }   

    int **matrix = (int **)realloc(matrix, (l+1)*sizeof(int *));
    for(int i = 0; i < l+1; i++)
    {
        matrix[i] = (int *)realloc(matrix[i], (c)*sizeof(int));
        for(int j = 0; j < c; j++)
        {
            printf("Enter the element at position %d %d: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    //free the matrix
    for (int i = 0; i < l; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
   

    return 0;
