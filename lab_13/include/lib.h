#ifndef LIB_H
#define LIB_H

#include "structures.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void push_front(forward_list_t *list, vehicle_t data);
void pop_front(forward_list_t *list);

void display_node(node_t *node);
void display_list(forward_list_t *list);
void display_list_id(forward_list_t *list);
void display_list_owner(forward_list_t *list);

void free_list(forward_list_t **list);

void create_list(forward_list_t **list);
node_t *create_node(vehicle_t data);

node_t *find(forward_list_t *list, vehicle_t data);
node_t *find_prev_node(forward_list_t *list, vehicle_t data);

void insert_after(forward_list_t *list, vehicle_t target, vehicle_t data);
void insert_before(forward_list_t *list, vehicle_t target, vehicle_t data);

void erase_after(forward_list_t *list, vehicle_t target);
bool is_empty(forward_list_t *list);
bool is_node_equal(vehicle_t first, vehicle_t second);

#endif // LIB_H