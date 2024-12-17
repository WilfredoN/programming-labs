#include "lib.h"

int main(int argc, char const *argv[])
{
    forward_list_t *list = NULL;
    create_list(&list);

    vehicle_t vehicles[] = {
        {.brand = "Tesla",
         .model = "Model X",
         .year = 2023,
         .owner = {.name = "Nikita Afanasiev", .id = "1"},
         .length = 0},
        {.brand = "Honda",
         .model = "Civic",
         .year = 2021,
         .owner = {.name = "J B", .id = "2"},
         .length = 0},
        {.brand = "Ford",
         .model = "Focus",
         .year = 2019,
         .owner = {.name = "JD", .id = "3"},
         .length = 0},
        {.brand = "Chevrolet",
         .model = "Impala",
         .year = 1967,
         .owner = {.name = "John Winchester", .id = "4"},
         .length = 0}};

    push_front(list, vehicles[0]);
    insert_after(list, vehicles[0], vehicles[1]);
    insert_after(list, vehicles[1], vehicles[2]);

    printf("Displaying list after insertions:\n\n");
    display_list(list);

    node_t *prev = find_prev_node(list, vehicles[1]);

    if (prev != NULL)
    {
        printf("Prev node details:\n");
        display_node(prev);
        printf("\n");
    }
    else
    {
        printf("Previous node not found.\n");
    }

    insert_before(list, vehicles[1], vehicles[3]);

    printf("\nDisplaying list after inserting before Honda Civic:\n\n");
    display_list(list);

    printf("\nDisplaying list by ID:\n");
    display_list_id(list);

    printf("\nDisplaying list by Owner:\n");
    display_list_owner(list);

    printf("\nDisplaying list in reverse order:\n\n");
    display_node(list->tail);

    erase_after(list, vehicles[0]);
    printf("\nDisplaying list after deleting after Tesla Model X:\n");
    display_list(list);

    free_list(&list);
    return 0;
}