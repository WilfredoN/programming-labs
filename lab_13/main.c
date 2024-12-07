#include "lib.h"

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

    printf("Displaying list after insertions:\n\n");
    display_list(list);

    node_t *prev = find_prev_node(list, data_2);

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

    vehicle_t data_4;
    strcpy(data_4.brand, "Chevrolet");
    strcpy(data_4.model, "Impala");
    data_4.year = 1967;
    strcpy(data_4.owner.name, "John Winchester");
    strcpy(data_4.owner.id, "4");
    data_4.length = 0;
    insert_before(list, data_2, data_4);

    printf("\nDisplaying list after inserting before Honda Civic:\n\n");
    display_list(list);

    printf("\nDisplaying list by ID:\n");
    display_list_id(list);

    printf("\nDisplaying list by Owner:\n");
    display_list_owner(list);

    printf("\nDisplaying list in reverse order:\n\n");
    display_list_reverse(list);

    erase_after(list, data_1);
    printf("\nDisplaying list after deleting after Tesla Model X:\n");
    display_list(list);

    free_list(&list);
    return 0;
}