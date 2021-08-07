// bstree.h

struct bstnode
{
	int key;
	struct bstnode * left;
	struct bstnode * right;
};

void bst_assign(struct bstnode ** root, int * keys, int size);
void bst_clear(struct bstnode ** root);
void bst_clear_util(struct bstnode * root);
struct bstnode * bst_new_node(int key);
void bst_inorder(struct bstnode * root);
void bst_inorder_util(struct bstnode * root);
struct bstnode * bst_insert(struct bstnode * root, int key);
void bst_postorder(struct bstnode * root);
void bst_postorder_util(struct bstnode * root);
void bst_preorder(struct bstnode * root);
void bst_preorder_util(struct bstnode * root);
