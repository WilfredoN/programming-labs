#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// replace with a struct from the lab#11
typedef struct data_t
{
    int data;
} data_t;

typedef struct node_t
{
    data_t data;
    struct node_t *next;
} node_t;

typedef struct forward_list_t
{
    node_t *head;
} forward_list_t;

void push_front(forward_list_t *list, data_t data);
void pop_front(forward_list_t *list);
// implement this function
void dispaly_node(node_t *node);
void display_list(forward_list_t *list);
void free_list(forward_list_t **list);
void create_list(forward_list_t **list);
node_t *create_node(data_t data);
node_t *find(forward_list_t *list, data_t data); // find current node
node_t *find_prev_node(forward_list_t *list, data_t data);
void insert_after(forward_list_t *list, data_t target, data_t data);
void insert_before(forward_list_t *list, data_t target, data_t data);
// add yourself
void erase_after(forward_list_t *list, data_t target);
bool is_empty(forward_list_t *list);
bool is_equal(data_t first, data_t second);

void display_list_2(node_t *head);

int main(int argc, char const *argv[])
{
    forward_list_t *list = NULL;
    //
    create_list(&list);

    // 1 Add elements
    data_t data = {.data = 10};
    push_front(list, data);
    data.data = 20;
    push_front(list, data);
    data.data = 30;
    push_front(list, data);
    data_t target = {.data = 10};
    data.data = 50;
    insert_after(list, target, data);
    insert_after(list, target, data);
    // 2 display
    node_t *prev = find_prev_node(list, target);
    display_list_2(prev->next);
    dispaly_node(prev);
    data.data = 75;
    insert_before(list, target, data);
    display_list(list);

    free_list(&list);
    return 0;
}

node_t *create_node(data_t data)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data.data = data.data;
}

void push_front(forward_list_t *list, data_t data)
{
    node_t *node = create_node(data);
    node->next = list->head->next; // 1)
    list->head->next = node;
}

void pop_front(forward_list_t *list)
{
    if (list->head->next == NULL)
    {
        return;
    }
    // the 1st elem in a list
    node_t *for_deletion = list->head->next;
    list->head->next = list->head->next->next;
    free(for_deletion);
}

void display_list(forward_list_t *list)
{
    node_t *current = list->head->next; // 1st
    while (current != NULL)
    {
        printf("%d -> ", current->data.data);
        current = current->next;
    }
    printf("NULL\n");
}

void display_list_2(node_t *head)
{
    node_t *current = head; // 1st
    while (current != NULL)
    {
        printf("%d -> ", current->data.data);
        current = current->next;
    }
    printf("NULL\n");
}

void free_list(forward_list_t **list)
{
    node_t *current = (*list)->head->next; // 1st
    while (current)
    {
        node_t *for_deletion = current;
        current = current->next;
        free(for_deletion);
    }
    free((*list)->head);
    free(*list);
    *list = NULL;
}

void create_list(forward_list_t **list)
{
    *list = (forward_list_t *)malloc(sizeof(forward_list_t));
    (*list)->head = (node_t *)malloc(sizeof(node_t));
    (*list)->head->next = NULL;
    // (*list)->head->data.data = -1; //it is not required
}

node_t *find(forward_list_t *list, data_t data)
{

    node_t *current = list->head->next; // 1st
    while (current)
    {
        if (current->data.data == data.data)
        // if (is_equal(current->data, data))
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

node_t *find_prev_node(forward_list_t *list, data_t data)
{
    node_t *current = list->head->next; // 1st
    while (current)
    {
        if (current->next && current->next->data.data == data.data)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
void insert_after(forward_list_t *list, data_t target, data_t data)
{
    node_t *current = find(list, target); // 1st
    if (current)                          // current != NULL it is not equal to NULL
    {
        node_t *for_insert = (node_t *)malloc(sizeof(node_t));
        for_insert->data.data = data.data;
        for_insert->next = current->next;
        current->next = for_insert;
    }
}

void insert_before(forward_list_t *list, data_t target, data_t data)
{
    node_t *current = find_prev_node(list, target); // 1st
    if (current)                                    // current != NULL it is not equal to NULL
    {
        node_t *for_insert = (node_t *)malloc(sizeof(node_t));
        for_insert->data.data = data.data;
        for_insert->next = current->next;
        current->next = for_insert;
    }
}

void dispaly_node(node_t *node)
{
    if (node)
    {
        printf("%p : %d\n", node, node->data.data);
    }
    else
    {
        puts("NULL");
    }
}

//
// HEAD -> NULL

// HEAD -> NODE1 -> NODE2 ...

// NODEX before NODE1

// NODEX -> NODE1  (prev HEAD->next)

// HEAD -> next -> NODE1 -> NODE2 -> ...
// NODEX -> next

// HEAD -> next -> NODEX -> next > NODE1 -> NODE2 -> ...

// 2
// HEAD -> next -> NODEX -> next -> NODE1 -> NODE2 -> ...

// TMP -> next -> NODEX

// HEAD -> next -> HEAD -> next -> next (NODE1)
