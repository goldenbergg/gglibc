#include <stdio.h>
#include "bstree.h"
#include "slist.h"

void bst_assign_test(void);
void bst_insert_test(void);

void sl_assign_fill_test(void);
void sl_back_test(void);
void sl_begin_test(void);
void sl_clear_test(void);
void sl_empty_test(void);
void sl_end_test(void);
void sl_erase_position_test(void);
void sl_erase_range_test(void);
void sl_front_test(void);
void sl_insert_single_test(void);
void sl_insert_fill_test(void);
void sl_push_back_test(void);
void sl_push_front_test(void);
void sl_size_test(void);
void sl_print(struct slnode * head);
void sl_sort_test(void);

int main()
{
    // Binary search tree tests
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("Binary Search Tree Tests\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    bst_assign_test();
    bst_insert_test();
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");

    // Singly-linked list tests
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("Singly-Linked List Tests\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    sl_assign_fill_test();
    sl_back_test();
    sl_begin_test();
    sl_clear_test();
    sl_empty_test();
    sl_end_test();
    sl_erase_position_test();
    sl_erase_range_test();
    sl_front_test();
    sl_insert_single_test();
    sl_insert_fill_test();
    sl_push_back_test();
    sl_push_front_test();
    sl_size_test();
    sl_sort_test();
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    return 0;
}

void bst_assign_test(void)
{
    printf("bst_assign_test:\n");
    int keys[6] = {41, 20, 11, 29, 32, 50};
    struct bstnode * root = NULL;
    bst_assign(&root, keys, 6);
    bst_inorder(root);
    bst_clear(&root);
    printf("\n");
    return;
}

void bst_insert_test(void)
{
    printf("bst_insert_test:\n");
    struct bstnode * root = NULL;
    root = bst_insert(root, 44);
    bst_insert(root, 41);
    bst_insert(root, 91);
    bst_insert(root, 34);
    bst_insert(root, 72);
    bst_insert(root, 67);
    bst_inorder(root);
    bst_postorder(root);
    bst_preorder(root);
    bst_clear(&root);
    return;
}

void sl_assign_fill_test(void)
{
    printf("sl_assign_fill_test:\n");
    struct slnode * head = NULL;
    sl_assign_fill(&head, 7, 0);
    sl_print(head);
    sl_clear(&head);
    printf("\n");
    return;
}

void sl_back_test(void)
{
    printf("sl_back_test:\n");
    struct slnode * head = NULL;
    sl_push_front(&head, 1);
    sl_push_front(&head, 2);
    sl_push_front(&head, 3);
    printf("Back: %d\n", sl_back(head));
    sl_clear(&head);
    printf("\n");
    return;
}

void sl_begin_test(void)
{
    printf("sl_begin_test:\n");
    struct slnode * head = NULL;
    sl_push_front(&head, 1);
    sl_push_front(&head, 2);
    sl_push_front(&head, 3);
    printf("Begin: %d\n", sl_begin(head)->key);
    sl_clear(&head);
    printf("\n");
    return;
}

void sl_clear_test(void)
{
    printf("sl_clear_test:\n");
    struct slnode * head = NULL;
    sl_push_front(&head, 1);
    sl_push_front(&head, 2);
    sl_push_front(&head, 3);
    sl_print(head);
    sl_clear(&head);
    sl_print(head);
    printf("\n");
    return;
}

void sl_empty_test(void)
{
    printf("sl_empty_test:\n");
    struct slnode * head = NULL;
    sl_push_front(&head, 1);
    sl_push_front(&head, 2);
    sl_push_front(&head, 3);
    printf("Is the list empty? %s\n", sl_empty(head) ? "True." : "False.");
    sl_clear(&head);
    printf("Is the list empty? %s\n", sl_empty(head) ? "True." : "False.");
    printf("\n");
    return;
}

void sl_end_test(void)
{
    printf("sl_end_test:\n");
    struct slnode * head = NULL;
    sl_push_front(&head, 1);
    sl_push_front(&head, 2);
    sl_push_front(&head, 3);
    sl_print(sl_end(head));
    sl_clear(&head);
    printf("\n");
    return;
}

void sl_erase_position_test(void)
{
    printf("sl_erase_position_test:\n");
    struct slnode * head = NULL;
    sl_push_front(&head, 1);
    sl_push_front(&head, 2);
    sl_push_front(&head, 3);
    sl_erase_position(&head, 1);
    sl_print(head);
    sl_clear(&head);
    printf("\n");
    return;
}

void sl_erase_range_test(void)
{
    printf("sl_erase_range_test:\n");
    struct slnode * head = NULL;
    sl_push_front(&head, 7);
    sl_push_front(&head, 6);
    sl_push_front(&head, 5);
    sl_push_front(&head, 4);
    sl_push_front(&head, 3);
    sl_push_front(&head, 2);
    sl_push_front(&head, 1);
    sl_erase_range(&head, 1, 6);
    sl_print(head);
    sl_clear(&head);
    printf("\n");
    return;
}

void sl_front_test(void)
{
    printf("sl_front_test:\n");
    struct slnode * head = NULL;
    sl_push_front(&head, 1);
    sl_push_front(&head, 2);
    sl_push_front(&head, 3);
    printf("Front: %d\n", sl_front(head));
    sl_clear(&head);
    printf("\n");
    return;
}

void sl_insert_single_test(void)
{
    printf("sl_insert_single_test:\n");
    struct slnode * head = NULL;
    sl_push_front(&head, 1);
    sl_push_front(&head, 2);
    sl_push_front(&head, 3);
    sl_insert_single(&head, 1, 1);
    sl_print(head);
    sl_clear(&head);
    printf("\n");
    return;
}

void sl_insert_fill_test(void)
{
    printf("sl_insert_fill_test:\n");
    struct slnode * head= NULL;
    sl_insert_fill(&head, 0, 4, 21);
    sl_print(head);
    sl_clear(&head);
    printf("\n");
    return;
}

void sl_push_back_test(void)
{
    printf("sl_push_back_test:\n");
    struct slnode * head = NULL;
    sl_push_back(&head, 1);
    sl_push_back(&head, 2);
    sl_push_back(&head, 3);
    sl_print(head);
    sl_clear(&head);
    printf("\n");
    return;
}

void sl_push_front_test(void)
{
    printf("sl_push_front_test:\n");
    struct slnode * head = NULL;
    sl_push_front(&head, 1);
    sl_push_front(&head, 2);
    sl_push_front(&head, 3);
    sl_print(head);
    sl_clear(&head);
    printf("\n");
    return;
}

void sl_size_test(void)
{
    printf("sl_size_test:\n");
    struct slnode * head = NULL;
    sl_push_front(&head, 1);
    sl_push_front(&head, 2);
    sl_push_front(&head, 3);
    printf("Size: %d\n", sl_size(head));
    sl_clear(&head);
    printf("\n");
    return;
}

void sl_sort_test(void)
{
    printf("sl_sort_test:\n");
    struct slnode * head = NULL;
    sl_push_front(&head, 74);
    sl_push_front(&head, 44);
    sl_push_front(&head, 64);
    sl_push_front(&head, 97);
    sl_push_front(&head, 52);
    sl_print(head);
    sl_sort(&head);
    sl_print(head);
    sl_clear(&head);
    return;
}

void sl_print(struct slnode * head)
{
    if (head == NULL)
    {
        printf("The given list is empty.\n");
        return;
    }
    else
    {
        printf("List: ");
        while (head != NULL)
        {
            printf("%d ", head->key);
            head = head->next;
        }
        printf("\n");
        return;
    }
}
