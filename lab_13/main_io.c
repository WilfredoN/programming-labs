#include "lib.h"
#include "lib_io.h"

#define FILE_TXT "vehicles.txt"
#define FILE_BIN "vehicles.bin"

int main(int argc, char const *argv[])
{
    forward_list_t *list = NULL;
    create_list(&list);

    vehicle_t data_1;
    memset(&data_1, 0, sizeof(vehicle_t));

    strcpy(data_1.brand, "Tesla");
    strcpy(data_1.model, "Model X");

    data_1.year = 2023;

    strcpy(data_1.owner.name, "Nikita Afanasiev");
    strcpy(data_1.owner.id, "1");

    data_1.length = 0;

    push_front(list, data_1);

    vehicle_t data_2;
    memset(&data_2, 0, sizeof(vehicle_t));

    strcpy(data_2.brand, "Honda");
    strcpy(data_2.model, "Civic");

    data_2.year = 2021;

    strcpy(data_2.owner.name, "J B");
    strcpy(data_2.owner.id, "2");

    data_2.length = 0;

    insert_after(list, data_1, data_2);

    vehicle_t data_3;
    memset(&data_3, 0, sizeof(vehicle_t));

    strcpy(data_3.brand, "Ford");
    strcpy(data_3.model, "Focus");

    data_3.year = 2019;

    strcpy(data_3.owner.name, "JD");
    strcpy(data_3.owner.id, "3");

    data_3.length = 0;

    insert_after(list, data_2, data_3);

    vehicle_t data_4;
    memset(&data_4, 0, sizeof(vehicle_t));

    strcpy(data_4.brand, "Chevrolet");
    strcpy(data_4.model, "Impala");

    data_4.year = 1967;

    strcpy(data_4.owner.name, "John Winchester");
    strcpy(data_4.owner.id, "4");

    data_4.length = 0;

    insert_before(list, data_2, data_4);

    if (save_to_text(list, FILE_TXT))
        printf("List saved to vehicles.txt\n");
    else
    {
        printf("Failed to save to text file.\n");
        return 0;
    }

    if (save_to_binary(list, FILE_BIN))
        printf("List saved to vehicles.bin\n");
    else
    {
        printf("Failed to save to binary file.\n");
        return 0;
    }
    free_list(&list);
    create_list(&list);

    if (load_from_text(list, "vehicles.txt"))
        printf("List loaded from vehicles.txt\n");
    else
    {
        printf("Failed to load from text file.\n");
        return 0;
    }

    display_list(list);

    free_list(&list);
    create_list(&list);

    if (load_from_binary(list, "vehicles.bin"))
        printf("List loaded from vehicles.bin\n");
    else
    {
        printf("Failed to load from binary file.\n");
        return 0;
    }

    display_list(list);

    free_list(&list);
    return 0;
}