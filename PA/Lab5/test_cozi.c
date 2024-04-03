#include "cozi.h"
#include <time.h>

#include <stdio.h>
#include <stdlib.h>



int main()
{  //----------- 
    srand(time(NULL));
    int n1,n2;

    n1=rand()%21;
    n2=rand()%21;
    n1 += 70;
    n2 += 70;

    Queue *q1=createQueue();
    Queue *q2=createQueue();
    
    for(int i=1;i<=n1;i++)
        enQueue(q1,i);
    for(int i=1;i<=n2;i++)
        enQueue(q2,i);
    

    if(n1<=n2)
        {
            enQueue(q1,0);
        }
    else
        {
            enQueue(q2,0);
        }

    while(!isEmpty(q1) && !isEmpty(q2))
    {
        int t1 = rand() % 7 + 1;
        int t2 = rand() % 7 + 1;
    }



    //----------
    int *p;
    p = (int*)malloc(10*sizeof(int));

    for(int i = 0; i < 10; i++)
    {
        scanf("%d", p + i);
    }

    Queue *queue = createQueue();

    for(int i = 0; i < 10; i++)
    {
        enQueue(queue, p[i]);
    }

    //deque one time
    int a = deQueue(queue);
    int b = deQueueRear(queue);
    
    enQueueFront(queue, b);


    //print the queue
    Node* aux = queue->front;
    while(aux != NULL)
    {
        printf("%d ", aux->val);
        aux = aux->next;
    }


    // while (!isEmpty(queue))
    // {
    //     printf("%d ", deQueue(queue));
    // }


    return 0;

}