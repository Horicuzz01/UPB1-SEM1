#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{

    char data;
    struct node *next;
};

typedef struct node NOTA;


NOTA* create1(char date)
{
    NOTA *new = (NOTA*)malloc(sizeof(NOTA));
    new->data = date;
    new->next = NULL;
    return new;
}


void adaugare_nod(NOTA **p, char data)
{
    NOTA *q = create1(data);
    q->next = (*p)->next;
    (*p)->next = q;

}

void adaugare_refren(NOTA *rez, char *refren)
{
    NOTA *p = NULL;
    NOTA *q = NULL;
    printf("Am ajuns aici, %c", rez->data);
    p = rez;
    while((p->next)->data != refren[2])
    {
        p = p->next;
    }
    p = p->next;
    q = rez;
    printf("Am pozitionat p la finalul secventei, %c, %c", p->data, q->data);
    
    while(q->next != NULL && q->data != refren[2])
    {   
        
        adaugare_nod(&p, q->data);
        q = q->next;
        p = p->next;
    }
    adaugare_nod(&p, q->data);
    printf("Am adaugat refrenul"); 
}


NOTA* find_refren(char *refren, NOTA *partitura)
{   
    printf("Secventa este: ");
    NOTA *p = NULL;
    NOTA *q = NULL;
    p = partitura;

    while(p != NULL)
    {
        if(p->data == refren[0] && (p->next)->data == refren[1])
        {
            q = (p->next)->next;
            while(q != NULL)
            {
                if(q->data == refren[2])
                {
                    return p;
                }
                else{
                    q = q->next;
                }
            }
        }
        else{
            p = p->next;
        }
    }

    return p;

}

int main()
{
    char v[10] = "DDGGAFCDFC";
    char refren[3] = "GAD";

    NOTA *partitura = NULL;
    NOTA *q = NULL;

    partitura = create1(v[0]);
    q = partitura;

    for(int i = 1;i<strlen(v);i++)
    {
        q->next = create1(v[i]);
        q = q->next;
    }

    //arata partitura

    q = partitura;
    
    while(q != NULL)
    {
        printf("%c",q->data);
        q = q->next;
    }
    printf("\n");

    // printf("Introduceti secventa de note (3 caractere):");
    // fgets(refren,3,stdin); //primele doua si ultima
    
    // printf("Secventa este: ");
    // for(int i = 0;i<3;i++)
    // {
    //     printf("%c",refren[i]);
    // }
    //sa returnam secventa

    NOTA *ref = find_refren(refren,partitura);
    NOTA *ref1 = ref;

    if(ref != NULL)
    {   printf("Secventa este: ");
        while(1)
        {

            if(ref->data == refren[2])
                {
                    printf("%c",ref->data);
                    break;
                }
            else{
                printf("%c",ref->data);
                ref = ref->next;
            }
        }
    }
    else{
        printf("Nu exista secventa");
    }
    printf("\n");

    //adaugare refren
   
    adaugare_refren(ref1,refren);
    //show partitura
    q = partitura;
    printf("\n");
    while(q != NULL)
    {
        printf("%c ",q->data);
        q = q->next;
    }
    return 0;
}
