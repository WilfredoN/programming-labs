#ifndef LIB_H
#define LIB_H

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
    struct node_t *prev;
} node_t;

typedef struct forward_list_t
{
    node_t *head;
    node_t *tail;
} forward_list_t;

void push_front(forward_list_t *list, vehicle_t data);
void pop_front(forward_list_t *list);

void display_node(node_t *node);
void display_list(forward_list_t *list);
void display_list_id(forward_list_t *list);
void display_list_owner(forward_list_t *list);
void display_list_reverse(forward_list_t *list);

void free_list(forward_list_t **list);

void create_list(forward_list_t **list);
node_t *create_node(vehicle_t data);

node_t *find(forward_list_t *list, vehicle_t data);
node_t *find_prev_node(forward_list_t *list, vehicle_t data);

void insert_after(forward_list_t *list, vehicle_t target, vehicle_t data);
void insert_before(forward_list_t *list, vehicle_t target, vehicle_t data);

void erase_after(forward_list_t *list, vehicle_t target);
bool is_empty(forward_list_t *list);
bool is_equal(vehicle_t first, vehicle_t second);

#endif // LIB_H