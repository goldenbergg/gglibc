#include <stdio.h>
#include "slist.h"

void sl_assign_fill_test(void);
void sl_back_test(void);
void sl_begin_test(void);
void sl_cbegin_test(void);
void sl_cend_test(void);
void sl_clear_test(void);
void sl_push_back_test(void);
void sl_push_front_test(void);
void sl_size_test(void);
void sl_print(struct slnode * head);

int main()
{
    sl_assign_fill_test();
    sl_back_test();
    sl_begin_test();
    sl_cbegin_test();
    sl_cend_test();
    sl_clear_test();
    sl_push_back_test();
    sl_push_front_test();
    sl_size_test();
    return 0;
}

void sl_assign_fill_test(void)
{
    printf("sl_assign_fill_test: ");
    struct slnode * head = NULL;
    sl_assign_fill(&head, 7, 0);
    sl_print(head);
    return;
}

void sl_back_test(void)
{
    printf("sl_back_test: ");
    struct slnode * head = NULL;
    sl_push_front(&head, 1);
    sl_push_front(&head, 2);
    sl_push_front(&head, 3);
    printf("%d\n", sl_back(head));
    return;
}

void sl_begin_test(void)
{
    printf("sl_begin_test: ");
    struct slnode * head = NULL;
    sl_push_front(&head, 1);
    sl_push_front(&head, 2);
    sl_push_front(&head, 3);
    printf("%d\n", sl_begin(&head)->key);
    return;
}

void sl_cbegin_test(void)
{
    printf("sl_cbegin_test: ");
    struct slnode * head = NULL;
    sl_push_front(&head, 1);
    sl_push_front(&head, 2);
    sl_push_front(&head, 3);
    printf("%d\n", sl_cbegin(head)->key);
    return;
}

void sl_cend_test(void)
{
    printf("sl_cend_test: ");
    struct slnode * head = NULL;
    sl_push_front(&head, 1);
    sl_push_front(&head, 2);
    sl_push_front(&head, 3);
    printf("%d\n", sl_cend(head)->key);
    return;
}

void sl_clear_test(void)
{
    printf("sl_clear_test: ");
    struct slnode * head = NULL;
    sl_push_front(&head, 1);
    sl_push_front(&head, 2);
    sl_push_front(&head, 3);
    sl_print(head);
    sl_clear(&head);
    sl_print(head);
    return;
}

void sl_push_back_test(void)
{
    printf("sl_push_back_test: ");
    struct slnode * head = NULL;
    sl_push_back(&head, 1);
    sl_push_back(&head, 2);
    sl_push_back(&head, 3);
    sl_print(head);
    return;
}

void sl_push_front_test(void)
{
    printf("sl_push_front_test: ");
    struct slnode * head = NULL;
    sl_push_front(&head, 1);
    sl_push_front(&head, 2);
    sl_push_front(&head, 3);
    sl_print(head);
    return;
}

void sl_size_test(void)
{
    printf("sl_size_test: ");
    struct slnode * head = NULL;
    sl_push_front(&head, 1);
    sl_push_front(&head, 2);
    sl_push_front(&head, 3);
    printf("%d\n", sl_size(head));
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
        while (head != NULL)
        {
            printf("%d ", head->key);
            head = head->next;
        }
        printf("\n");
        return;
    }
}
