#include <stive.h>

int isEmpty(Node *top)
{
	return top == NULL;
}

void deleteStack(Node **top)
{
	Node *temp;
	while ((*top) != NULL)
	{ // !isEmpty(*top)
		temp = *top;
		*top = (*top)->next;
		free(temp);
	}
}

VAL pop(Node **top)
{
	VAL valori;
	valori.x = INT_MIN;
	valori.y = INT_MIN;
	valori.z = INT_MIN;

	if (isEmpty(*top))
		return valori;
	Node *temp = (*top);
	VAL aux = temp->val;
	*top = (*top)->next;
	free(temp);
	return aux;
}
	
void push(Node **top, VAL v)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->val = v;
	newNode->next = *top;
	*top = newNode;
}

VAL top(Node *top)
{
	VAL valori;
	valori.x = INT_MIN;
	valori.y = INT_MIN;
	valori.z = INT_MIN;

	if (isEmpty(top))
		return valori;
	return top->val;
}

void printStack(Node *stack)
{
	while (!isEmpty(stack))
		printf("%d ", pop(&stack));
}
