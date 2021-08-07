// slist.h
#include <stdbool.h>

struct slnode
{
    int key;
    struct slnode * next;
};

struct slnode * sl_new_node(int key);
void sl_assign_fill(struct slnode ** head, int n, int val);
int sl_back(struct slnode * head);
struct slnode * sl_begin(struct slnode * head);
void sl_clear(struct slnode ** head);
bool sl_empty(struct slnode * head);
struct slnode * sl_end(struct slnode * head);
void sl_erase_position(struct slnode ** head, int position);
void sl_erase_range(struct slnode ** head, int first, int last);
int sl_front(struct slnode * head);
void sl_insert_single(struct slnode ** head, int position, int val);
void sl_insert_fill(struct slnode ** head, int position, int n, int val);
void sl_push_back(struct slnode ** head, int key);
void sl_push_front(struct slnode ** head, int key);
int sl_size(struct slnode * head);
void sl_sort(struct slnode ** head);
struct slnode * sl_sort_partition(struct slnode * head, struct slnode * end, struct slnode ** new_head, struct slnode ** new_end);
struct slnode * sl_sort_rec(struct slnode * head, struct slnode * end);
struct slnode * sl_tail(struct slnode * head);
