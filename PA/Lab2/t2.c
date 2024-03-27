#include <stdio.h>
#include <stdlib.h>

struct nr_complex {
    double re;
    double im;
};

typedef struct nr_complex nr_complex;

int main()
{
    nr_complex* nr;
    nr = (nr_complex*)malloc(sizeof(nr_complex));

    nr_complex* nr2;
    nr2 = (nr_complex*)malloc(100*sizeof(nr_complex));

    nr_complex** mat;
    mat = (nr_complex**)malloc(100*sizeof(nr_complex*));
    for(int i=0; i<100; i++)
        mat[i] = (nr_complex*)malloc(100*sizeof(nr_complex));

    free(nr);
    free(nr2);
    for(int i=0; i<100; i++)
        free(mat[i]);
    free(mat);
    return 0;
   
}