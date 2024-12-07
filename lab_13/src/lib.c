
#include "lib.h"

node_t *create_node(vehicle_t data)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    return node;
}

void push_front(forward_list_t *list, vehicle_t data)
{
    node_t *node = create_node(data);
    node->next = list->head->next;
    list->head->next = node;
}

void pop_front(forward_list_t *list)
{
    if (list->head->next == NULL)
    {
        return;
    }
    node_t *for_deletion = list->head->next;
    list->head->next = list->head->next->next;
    free(for_deletion);
}

void display_list(forward_list_t *list)
{
    node_t *current = list->head->next;
    while (current != NULL)
    {
        printf("Brand: %s, Model: %s, Year: %d, Owner: %s, ID: %s\n",
               current->data.brand,
               current->data.model,
               current->data.year,
               current->data.owner.name,
               current->data.owner.id);
        current = current->next;
    }
    printf("NULL\n");
}

void display_list_2(node_t *head)
{
    node_t *current = head;
    while (current != NULL)
    {
        printf("Brand: %s, Model: %s, Year: %d, Owner: %s, ID: %s\n",
               current->data.brand,
               current->data.model,
               current->data.year,
               current->data.owner.name,
               current->data.owner.id);
        current = current->next;
    }
    printf("NULL\n");
}

void display_list_id(forward_list_t *list)
{
    node_t *current = list->head->next;
    while (current != NULL)
    {
        printf("%s->", current->data.owner.id);
        current = current->next;
    }
    printf("NULL\n");
}
void display_list_owner(forward_list_t *list)
{
    node_t *current = list->head->next;
    while (current != NULL)
    {
        printf("%s->", current->data.owner.name);
        current = current->next;
    }
    printf("NULL\n");
}

void free_list(forward_list_t **list)
{
    node_t *current = (*list)->head->next;
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
}

node_t *find(forward_list_t *list, vehicle_t data)
{
    node_t *current = list->head->next;
    while (current)
    {
        if (is_equal(current->data, data))
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

node_t *find_prev_node(forward_list_t *list, vehicle_t data)
{
    node_t *current = list->head;
    while (current->next)
    {
        if (is_equal(current->next->data, data))
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void insert_after(forward_list_t *list, vehicle_t target, vehicle_t data)
{
    node_t *current = find(list, target);
    if (current)
    {
        node_t *for_insert = create_node(data);
        for_insert->next = current->next;
        current->next = for_insert;
    }
}

void insert_before(forward_list_t *list, vehicle_t target, vehicle_t data)
{
    node_t *current = find_prev_node(list, target);
    if (current)
        if (current)
        {
            node_t *for_insert = create_node(data);
            for_insert->next = current->next;
            current->next = for_insert;
        }
}

void display_node(node_t *node)
{
    if (node)
    {
        printf("Node Address: %p\n", (void *)node);
        printf("Brand: %s, Model: %s, Year: %d, Owner: %s, ID: %s\n",
               node->data.brand,
               node->data.model,
               node->data.year,
               node->data.owner.name,
               node->data.owner.id);
    }
    else
    {
        puts("NULL");
    }
}

void erase_after(forward_list_t *list, vehicle_t target)
{
    node_t *current = find(list, target);
    if (current)
    {
        node_t *for_deletion = current->next;
        current->next = current->next->next;
        free(for_deletion);
    }
}

bool is_empty(forward_list_t *list)
{
    return list->head->next == NULL;
}

bool is_equal(vehicle_t first, vehicle_t second)
{
    return strcmp(first.brand, second.brand) == 0 &&
           strcmp(first.model, second.model) == 0 &&
           first.year == second.year &&
           strcmp(first.owner.name, second.owner.name) == 0 &&
           strcmp(first.owner.id, second.owner.id) == 0;
}