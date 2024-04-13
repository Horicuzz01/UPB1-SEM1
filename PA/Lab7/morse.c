#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct N
{
	char lit;
	struct N *left, *right;
};
typedef struct N Node;


struct LitMorse
{
	char *morse;
};
typedef struct LitMorse LitMorse;

Node *createNode(char lit)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->lit = lit;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node *createTree(Node *root)
{
	root = createNode('_');
	root->left = createNode('e');
	root->right = createNode('t');
	root->left->left = createNode('i');
	root->left->right = createNode('a');
	root->right->left = createNode('n');
	root->right->right = createNode('m');
	root->left->left->left = createNode('s');
	root->left->left->right = createNode('u');
	root->left->right->left = createNode('r');
	root->left->right->right = createNode('w');
	root->right->left->left = createNode('d');
	root->right->left->right = createNode('k');
	root->right->right->left = createNode('g');
	root->right->right->right = createNode('o');
	root->left->left->left->left = createNode('h');
	root->left->left->left->right = createNode('v');
	root->left->left->right->left = createNode('f');
	root->left->right->left->left = createNode('l');
	root->left->right->right->left = createNode('p');
	root->left->right->right->right = createNode('j');
	root->right->left->left->left = createNode('b');
	root->right->left->left->right = createNode('x');
	root->right->left->right->left = createNode('c');
	root->right->left->right->right = createNode('y');
	root->right->right->left->left = createNode('z');
	root->right->right->left->right = createNode('q');

	return root;
}

int height(Node *root)
{
	int hs, hd;
	if (root == NULL)
		return -1;
	hs = height(root->left);
	hd = height(root->right);
	return 1 + ((hs > hd) ? hs : hd);
}

void printLevel(Node *root, int level)
{
	if (root == NULL)
		return;
	if (level == 0)
		printf("%c ", root->lit);
	else if (level > 0)
	{
		printLevel(root->left, level - 1);
		printLevel(root->right, level - 1);
	}
}



void levelOrderTraversal(Node *root)
{
	int h = height(root);
	int i;
	for (i = 0; i <= h; i++)
	{
		
	}
	return;
}



void addLetter(char word[], char letter)
{
	int len = strlen(word);
	word[len] = letter;
	word[len + 1] = '\0';
}

void dfs(Node *root, char seq[], LitMorse litere[])
{
	if (root == NULL)
		{	
			return;
		}

	strcpy(litere[root->lit - 'A'].morse, seq);

	char c[100];

	strcpy(c, seq);
	addLetter(c, ".");
	dfs(root->left, c, litere);
	
	strcpy(c, seq);
	addLetter(c, "-");
	dfs(root->right, c, litere);
}

void translate(char word[], Node *root)
{
	for (int i = 0; i <= strlen(word); i++)
	{
		char c = word[i];
		char serie[6];
		int i = 0;
		while(1)
		{
			
		}		
		
	}
}

int main()
{
	
	LitMorse Litere[27];

	Node *root = NULL;
	root = createTree(root);

	char word[100];
	printf("Cuvantul: ");

	scanf("%s", &word);
	translate(word, root);

	return 0;
}
