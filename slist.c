// slist.c
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

struct slnode * sl_begin(struct slnode ** head)
{
    return *head;
}

struct slnode * sl_cbegin(struct slnode * head)
{
    return head;
}

struct slnode * sl_cend(struct slnode * head)
{
    while (head->next != NULL)
        head = head->next;
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
