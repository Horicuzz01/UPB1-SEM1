#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>


void f1(int *a)
{
    (*a)++;
    printf("valoarea lui a in f1: %d\n", (*a));
    printf("adresa lui a in f1: %p\n", a);

    f2(*a);

}

void f2(int a)
{
    a++;
    printf("valoarea lui a in f2: %d\n", a);
    printf("adresa lui a in f2: %p\n", &a);

    f3(a);
}

void f3(int a)
{
    a++;
    printf("valoarea lui a in f3: %d\n", a);
    printf("adresa lui a in f3: %p\n", &a);
    
    f4(&a);
}

void f4(int *a)
{
    (*a)++;
    printf("valoarea lui a in f4: %d\n", (*a));
    printf("adresa lui a in f4: %p\n", a);
}

int *elem_median(int *v, int l)
{
   return(&(v[l/2]));
}


void r(int *v, int *med, int *l)
{
    for(int i = 0; i < (*l); i++)
    {

        if(&v[i] == med)
        {   
            
            for(int j = i; j < (*l) - 1; j++)
            {
                v[j] = v[j + 1];
            }
            (*l)--;
            break;
        }
    }


    v = (int*)realloc(v, (*l) * sizeof(int));
    // Check if realloc was successful
    
    if (v == NULL && (*l) > 0)
    {
        printf("Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }
}

int main(void)
{   
    srand(time(NULL));
    int a = 0;
    a++;    
    printf("valoarea lui a in main: %d\n", a);
    printf("adresa lui a in main: %p\n", &a);

    f1(&a);
    
    printf("valoarea lui a in main: %d\n", a);
    printf("adresa lui a in main: %p\n", &a);


    float mat[5][5];

    for(int i = 0; i < 5; i++)
    {   
        for(int j = 0; j < 5; j++)
        {
            mat[i][j] = rand() % 100;
        }
    }
    printf("\nBEFORE\n");

    for(int i = 0; i < 5; i++)
    {   
        for(int j = 0; j < 5; j++)
        {
            printf("%.3f ", mat[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < 5; i++)
    {   
        float min = mat[0][i];
        float max = mat[0][i];

        for(int j = 0; j < 5; j++)
        {
            if(mat[j][i] < min)
            {
                min = mat[j][i];
            }
            if(mat[j][i] > max)
            {
                max = mat[j][i];
            }
        }

        for(int j = 0; j < 5; j++)
        {
            mat[j][i] = (mat[j][i] - min) / (max - min);
        }
        
    }
    printf("\nAFTER\n");

    for(int i = 0; i < 5; i++)
    {   
        for(int j = 0; j < 5; j++)
        {
            printf("%.3f ", mat[i][j]);
        }
        printf("\n");
    }

    int lungime = 0;
    int *p = NULL;
    
    while(1) {
        int val;
        scanf("%d", &val);
        
        if (val == 0) {
            break;
        }
        
        lungime++;
        p = (int*)realloc(p, lungime*sizeof(int));
        p[lungime-1] = val;
    }
    //afisam vectorul
    for (int i = 0; i < lungime; i++) {
        printf("%d ", p[i]);
    }

    printf("\n");
    //afisam adresa de memorie a medianului
    printf("%p si %d\n", elem_median(p, lungime), *elem_median(p, lungime));
    //stergem elementul de la adresa de memorie a medianului
    r(p, elem_median(p, lungime), &lungime);
    //afisam vectorul
    for(int i = 0; i < lungime-1; i++) {
        printf("%d ", p[i]);
    }

    return 0;
}