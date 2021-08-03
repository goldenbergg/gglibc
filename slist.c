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
    else //if (first < last)
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
