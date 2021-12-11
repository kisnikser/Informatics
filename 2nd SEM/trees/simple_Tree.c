#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Data int

typedef struct TN{
	Data data;
	struct TN * left;
	struct TN * right;
	int level;
}TreeNode;

TreeNode * downTree(TreeNode * root, Data dat){
	
	if(!root){
		TreeNode *newNode = malloc (sizeof(TreeNode));
		newNode->data = dat;
		newNode->left = newNode->right = 0;
		return newNode;
	}
	if( dat < root->data)
	{
	  root->left = downTree(root->left, dat);
	}
	if( dat > root->data)
	{
	  root->right = downTree(root->right, dat);
	}
	return root;
}

void prTree(TreeNode * root){
	if (!root)
		return;
	prTree(root->left);
	printf("%d ", root->data);
	prTree(root->right);
}

TreeNode *  destroy(TreeNode * root){
	if (! root)
		return 0;
	TreeNode *r = 0 , * l = 0;
	r = destroy(root->left);
	l = destroy(root->right);
	if ( ! l && ! r)
	{	
		printf("free: %d\n", root->data);
		free(root);
	}
	return 0;
};

int main(){
	TreeNode * root = 0;
	int i, a;
	while(scanf("%d", &a) != EOF)
	{
		root = downTree(root, a);
		
	}
	prTree(root);
	root = destroy(root);
	return 0;
}


