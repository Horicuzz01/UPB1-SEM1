#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stive.h>


int main()
{
    Node *top = (Node *)malloc(sizeof(Node));
    Node *top = NULL;
    VAL v;
    v.x = 3;
    v.y = 2;
    v.z = 1;
    push(&top, v);


    int v1 = -1, v2 = -1, v3 = -1;

    while (!isEmpty(top))
    {
        

        if (top->val.y < top->val.x)
        {
            if (top->next == NULL)
            {
                printf(top->val.y);
                break;
            }
            else
            {
                if (v3 == -1)
                    v3 = pop(&top).y;
                else if (v2 == -1)
                    v2 = pop(&top).y;
                else if (v1 == -1)
                    v1 = pop(&top).y;
            }

           
        }

        else
        {
            v = pop(&top);

            VAL aux;

            aux.x = v.x - 1;
            aux.y = v.y;
            aux.z = v.z;
            push(&top, aux);

            aux.x = v.x;
            aux.y = v.y - 1;
            aux.z = v.z;
            push(&top, aux);

            aux.x = v.x;
            aux.y = v.y;
            aux.z = v.z - 1;
            push(&top, aux);
        }
    }
}