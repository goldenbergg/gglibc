
// slist.c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

struct slnode * sl_new_node(int key)
{
    struct slnode * new_node = (struct slnode*) malloc(sizeof(struct slnode));
    new_node->key = key;
    new_node->next = NULL;
    return new_node;
}

void sl_assign_fill(struct slnode ** head, int n, int val)
{
    if (*head != NULL)
    {
        fprintf(stderr, "Error. List is not empty. Cannot assign to full list.\n");
        exit(EXIT_FAILURE);
    }
    else 
    {
        int count = 0;
        while (count < n)
        {
            sl_push_front(head, val);
            count++;
        }
        return;
    }
}

int sl_back(struct slnode * head)
{
    if (head == NULL)
    {
        fprintf(stderr, "Error. List is empty. Back can't be checked.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        while (head->next != NULL)
            head = head->next;
        return head->key;
    }
}

struct slnode * sl_begin(struct slnode * head)
{
    return head;
}

void sl_clear(struct slnode ** head)
{
    struct slnode * walker = *head;
    struct slnode * next = NULL;
    while (walker != NULL)
    {
        next = walker->next;
        free(walker);
        walker = next;
    }
    *head = NULL;
}

bool sl_empty(struct slnode * head)
{
    if (sl_size(head) == 0)
        return true;
    else
        return false;
}

struct slnode * sl_end(struct slnode * head)
{
    while (head != NULL)
        head = head->next;
    return head;
}

void sl_erase_position(struct slnode ** head, int position)
{
    if (*head == NULL)
    {
        fprintf(stderr, "Error. List is empty. No elements can be deleted at the given position.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        struct slnode * walker = *head;
        if (position == 0)
        {
            *head = walker->next;
            free(walker);
            return;
        }
        else
        {
            for (int i = 0; walker != NULL && i < (position - 1); i++)
                walker = walker->next;
            if (walker == NULL || walker->next == NULL)
            {
                fprintf(stderr, "Error. Position can't exceed the number of elements.\n");
                exit(EXIT_FAILURE);
            }
            else
            {
                struct slnode * next = walker->next->next;
                free(walker->next);
                walker->next = next;
            }
        }
    }
}

void sl_erase_range(struct slnode ** head, int first, int last)
{
    int size = sl_size(*head);
    if (first > last)
    {
        fprintf(stderr, "Error. The first number in range can't be larger than the last.\n");
        exit(EXIT_FAILURE);
    }
    else if (first > size || last > size)
    {
        fprintf(stderr, "Error. Range can't exceed the number of elements.\n");
        exit(EXIT_FAILURE);
    }
    else if (first == last)
    {
        return;
    }
    else
    {
        int count = 0;
        int diff = (last - first) - 1;
        struct slnode * walker = *head;
        while (count < first - 1)
        {
            count++;
            walker = walker->next;
        }
        count = 0;
        if (first != 0)
        {
            struct slnode * next = NULL;
            while (count <= diff)
            {
                count++;
                next = walker->next->next;
                free(walker->next);
                walker->next = next;
            }
            return;
        }
        else 
        {   
            while (count <= diff)
            {
                count++;
                *head = walker->next;
                free(walker);
                walker = *head;
            }
            return;
        }
    }
}

int sl_front(struct slnode * head)
{
    if (head == NULL)
    {
        fprintf(stderr, "Error. List is empty. Front can't be checked.\n");
        exit(EXIT_FAILURE);
    }
    else 
    {
        return head->key;
    }
}

void sl_insert_single(struct slnode ** head, int position, int val)
{
    if (*head == NULL && position != 0)
    {
        fprintf(stderr, "Error. List is empty and insert position is not 0.\n");
        exit(EXIT_FAILURE);
    }
    else if (position == 0)
    {
        sl_push_front(head, val);
        return;
    }
    else
    {
        struct slnode * walker = *head;
        for (int i = 0; walker != NULL && i < (position - 1); i++)
            walker = walker->next;
        if (walker == NULL)
        {
            fprintf(stderr, "Error. Position can't exceed the number of elements.\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            struct slnode * temp = sl_new_node(val);
            temp->next = walker->next;
            walker->next = temp;
            return;
        }
    }
}

void sl_insert_fill(struct slnode ** head, int position, int n, int val)
{
    if (*head == NULL && position != 0)
    {
        fprintf(stderr, "Error. List is empty and insert position is not 0.\n");
        exit(EXIT_FAILURE);
    }
    else if (position == 0)
    {
        int count = 0;
        while (count < n)
        {
            count++;
            sl_push_front(head, val);
        }
        return;
    }   
}

void sl_push_back(struct slnode ** head, int key)
{
    struct slnode * new_node = sl_new_node(key);
    struct slnode * walker = *head;
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    else
    {
        while (walker->next != NULL)
            walker = walker->next;
        walker->next = new_node;
        return;
    }
}

void sl_push_front(struct slnode ** head, int key)
{
    struct slnode * new_node = sl_new_node(key);
    new_node->next = *head;
    *head = new_node;
    return;
}

int sl_size(struct slnode * head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void sl_sort(struct slnode ** head)
{
    *head = sl_sort_rec(*head, sl_tail(*head));
    return;
}

struct slnode * sl_sort_partition(struct slnode * head, struct slnode * end, struct slnode ** new_head, struct slnode ** new_end)
{
    struct slnode * pivot = end;
    struct slnode * prev = NULL;
    struct slnode * curr = head;
    struct slnode * tail = pivot;
    while (curr != pivot)
    {
        if (curr->key < pivot->key)
        {
            if (*new_head == NULL)
                *new_head = curr;
            prev = curr;
            curr = curr->next;
        }
        else
        {
            if (prev != NULL)
                prev->next = curr->next;
            struct slnode * temp = curr->next;
            curr->next = NULL;
            tail->next = curr;
            tail = curr;
            curr = temp;
        }
    }
    if (*new_head == NULL)
        *new_head = pivot;
    *new_end = tail;
    return pivot;
}

struct slnode * sl_sort_rec(struct slnode * head, struct slnode * end)
{
    if (head == NULL || head == end)
        return head;
    struct slnode * new_head = NULL;
    struct slnode * new_end = NULL;
    struct slnode * pivot = sl_sort_partition(head, end, &new_head, &new_end);
    if (new_head != pivot)
    {
        struct slnode * temp = new_head;
        while (temp->next != pivot)
            temp = temp->next;
        temp->next = NULL;
        new_head = sl_sort_rec(new_head, temp);
        temp = sl_tail(new_head);
        temp->next = pivot;
    }
    pivot->next = sl_sort_rec(pivot->next, new_end);
    return new_head;
}

struct slnode * sl_tail(struct slnode * head)
{
    while (head != NULL && head->next != NULL)
        head = head->next;
    return head;
}
