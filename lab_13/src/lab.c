#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 20
#define MAX_SERVICE_NAME_LENGTH 50
#define MAX_SERVICES_AMOUNT 10

typedef struct
{
    char name[MAX_NAME_LENGTH];
    char id[MAX_ID_LENGTH];
} owner_t;

typedef struct
{
    char name[MAX_SERVICE_NAME_LENGTH];
    float price;
} service_t;

typedef struct
{
    char brand[MAX_NAME_LENGTH];
    char model[MAX_NAME_LENGTH];
    int year;
    owner_t owner;
    service_t services[MAX_SERVICES_AMOUNT];
    int length;
} vehicle_t;

typedef struct node_t
{
    vehicle_t data;
    struct node_t *next;
} node_t;

typedef struct forward_list_t
{
    node_t *head;
} forward_list_t;

void push_front(forward_list_t *list, vehicle_t data);
void pop_front(forward_list_t *list);
// implement this function
void display_node(node_t *node);
void display_list(forward_list_t *list);
void display_list_id(forward_list_t *list);
void display_list_owner(forward_list_t *list);
void free_list(forward_list_t **list);
void create_list(forward_list_t **list);
node_t *create_node(vehicle_t data);
node_t *find(forward_list_t *list, vehicle_t data); // find current node
node_t *find_prev_node(forward_list_t *list, vehicle_t data);
void insert_after(forward_list_t *list, vehicle_t target, vehicle_t data);
void insert_before(forward_list_t *list, vehicle_t target, vehicle_t data);
// add yourself
void erase_after(forward_list_t *list, vehicle_t target);
bool is_empty(forward_list_t *list);
bool is_equal(vehicle_t first, vehicle_t second);

void display_list_2(node_t *head);

int main(int argc, char const *argv[])
{
    forward_list_t *list = NULL;
    create_list(&list);

    vehicle_t data_1;
    strcpy(data_1.brand, "Tesla");
    strcpy(data_1.model, "Model X");
    data_1.year = 2023;
    strcpy(data_1.owner.name, "Nikita Afanasiev");
    strcpy(data_1.owner.id, "1");
    data_1.length = 0;
    push_front(list, data_1);

    vehicle_t data_2;
    strcpy(data_2.brand, "Honda");
    strcpy(data_2.model, "Civic");
    data_2.year = 2021;
    strcpy(data_2.owner.name, "J B");
    strcpy(data_2.owner.id, "2");
    data_2.length = 0;
    insert_after(list, data_1, data_2);

    vehicle_t data_3;
    strcpy(data_3.brand, "Ford");
    strcpy(data_3.model, "Focus");
    data_3.year = 2019;
    strcpy(data_3.owner.name, "JD");
    strcpy(data_3.owner.id, "3");
    data_3.length = 0;
    insert_after(list, data_2, data_3);

    printf("Displaying list after insertions:\n");
    display_list(list);

    node_t *prev = find_prev_node(list, data_2);
    if (prev != NULL)
    {
        printf("Prev node details:\n");
        display_node(prev);
    }
    else
    {
        printf("Previous node not found.\n");
    }

    vehicle_t data_4;
    strcpy(data_4.brand, "Chevrolet");
    strcpy(data_4.model, "Impala");
    data_4.year = 1967;
    strcpy(data_4.owner.name, "John Winchester");
    strcpy(data_4.owner.id, "4");
    data_4.length = 0;
    insert_before(list, data_2, data_4);

    printf("Displaying list after inserting before Honda Civic:\n");
    display_list(list);

    printf("Displaying list by ID:\n");
    display_list_id(list);

    printf("Displaying list by Owner:\n");
    display_list_owner(list);

    free_list(&list);
    return 0;
}

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
    node_t *current = head; // 1st
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
    node_t *current = list->head->next; // 1st
    while (current != NULL)
    {
        printf("%s->", current->data.owner.id);
        current = current->next;
    }
    printf("NULL\n");
}
void display_list_owner(forward_list_t *list)
{
    node_t *current = list->head->next; // 1st
    while (current != NULL)
    {
        printf("%s->", current->data.owner.name);
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

node_t *find(forward_list_t *list, vehicle_t data)
{
    node_t *current = list->head->next; // 1st
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
    node_t *current = find_prev_node(list, target); // 1st
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
