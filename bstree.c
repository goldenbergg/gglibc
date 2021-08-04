// bstree.c
#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

void bst_clear(struct bstnode ** root)
{
	bst_clear_util(*root);
	*root = NULL;
	return;
}

void bst_clear_util(struct bstnode * root)
{
	if (root == NULL)
		return;
	else
	{
		bst_clear_util(root->left);
		bst_clear_util(root->right);
		free(root);
		return;
	}
}

void bst_inorder(struct bstnode * root)
{
	printf("Inorder: ");
	bst_inorder_util(root);
	printf("\n");
	return;
}

void bst_inorder_util(struct bstnode * root)
{
	if (root == NULL)
		return;
	else
	{
		bst_inorder_util(root->left);
		printf("%d ", root->key);
		bst_inorder_util(root->right);
		return;
	}
}

struct bstnode * bst_insert(struct bstnode * root, int key)
{
	if (root == NULL)
	{
		struct bstnode * new_node = bst_new_node(key);
		return new_node;
	}
	else if (key < root->key)
	{
		root->left = bst_insert(root->left, key);
		return root;
	}
	else
	{
		root->right = bst_insert(root->right, key);
		return root;
	}
}

struct bstnode * bst_new_node(int key)
{
    struct bstnode * new_node = (struct bstnode*) malloc(sizeof(struct bstnode));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void bst_postorder(struct bstnode * root)
{
	printf("Postorder: ");
	bst_postorder_util(root);
	printf("\n");
	return;
}

void bst_postorder_util(struct bstnode * root)
{
	if (root == NULL)
		return;
	else
	{
		bst_postorder_util(root->left);
		bst_postorder_util(root->right);
		printf("%d ", root->key);
		return;
	}
}

void bst_preorder(struct bstnode * root)
{
	printf("Preorder: ");
	bst_preorder_util(root);
	printf("\n");
	return;
}

void bst_preorder_util(struct bstnode * root)
{
	if (root == NULL)
		return;
	else
	{
		printf("%d ", root->key);
		bst_preorder_util(root->left);
		bst_preorder_util(root->right);
		return;
	}
}

