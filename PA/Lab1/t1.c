//Considerat, i trei vectori de întregi: x,y,z cu n1, n2 respectiv n3 elemente. Pentru
//fiecare vector trebuie citite valorile elementelor s, i apoi afis,ate. Creat, i funct, ii pentru citirea elementelor unui vector de lungime n > 0 s, i afis,area elementelor unui
//vector de lungime n. Apelat, i-le pentru x, y, z.

#include <stdio.h>
#include <stdlib.h>

void citire(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("v[%d]=", i);
        scanf("%d", &v[i]);
    }
}

void afisare(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main()
{
    int n1, n2, n3;
    printf("n1=");
    scanf("%d", &n1);
    printf("n2=");
    scanf("%d", &n2);
    printf("n3=");
    scanf("%d", &n3);
    int *x = (int *)malloc(n1 * sizeof(int));
    int *y = (int *)malloc(n2 * sizeof(int));
    int *z = (int *)malloc(n3 * sizeof(int));
    citire(x, n1);
    citire(y, n2);
    citire(z, n3);
    afisare(x, n1);
    afisare(y, n2);
    afisare(z, n3);
    free(x);
    free(y);
    free(z);
    return 0;
}
