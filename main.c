#include <stdio.h>
#include "slist.h"

void sl_assign_fill_test(void);
void sl_back_test(void);
void sl_begin_test(void);
void sl_clear_test(void);
void sl_empty_test(void);
void sl_end_test(void);
void sl_erase_position_test(void);
void sl_erase_range_test(void);
void sl_push_back_test(void);
void sl_push_front_test(void);
void sl_size_test(void);
void sl_print(struct slnode * head);

int main()
{
    sl_assign_fill_test();
    sl_back_test();
    sl_begin_test();
    sl_clear_test();
    sl_empty_test();
    sl_end_test();
    sl_erase_position_test();
    sl_erase_range_test();
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
    sl_clear(&head);
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
    sl_clear(&head);
    return;
}

void sl_begin_test(void)
{
    printf("sl_begin_test: ");
    struct slnode * head = NULL;
    sl_push_front(&head, 1);
    sl_push_front(&head, 2);
    sl_push_front(&head, 3);
    printf("%d\n", sl_begin(head)->key);
    sl_clear(&head);
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

void sl_empty_test(void)
{
    printf("sl_empty_test: ");
    struct slnode * head = NULL;
    sl_push_front(&head, 1);
    sl_push_front(&head, 2);
    sl_push_front(&head, 3);
    printf("Is the list empty? %s\n", sl_empty(head) ? "True." : "False.");
    sl_clear(&head);
    printf("Is the list empty? %s\n", sl_empty(head) ? "True." : "False.");
    return;
}

void sl_end_test(void)
{
    printf("sl_end_test: ");
    struct slnode * head = NULL;
    sl_push_front(&head, 1);
    sl_push_front(&head, 2);
    sl_push_front(&head, 3);
    sl_print(sl_end(head));
    sl_clear(&head);
}

void sl_erase_position_test(void)
{
    printf("sl_erase_position_test: ");
    struct slnode * head = NULL;
    sl_push_front(&head, 1);
    sl_push_front(&head, 2);
    sl_push_front(&head, 3);
    sl_erase_position(&head, 1);
    sl_print(head);
    sl_clear(&head);
}

void sl_erase_range_test(void)
{
    printf("sl_erase_range_test: ");
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
}

void sl_push_back_test(void)
{
    printf("sl_push_back_test: ");
    struct slnode * head = NULL;
    sl_push_back(&head, 1);
    sl_push_back(&head, 2);
    sl_push_back(&head, 3);
    sl_print(head);
    sl_clear(&head);
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
    sl_clear(&head);
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
        while (head != NULL)
        {
            printf("%d ", head->key);
            head = head->next;
        }
        printf("\n");
        return;
    }
}
