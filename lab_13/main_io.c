#include "lib.h"
#include "lib_io.h"

#define FILE_TXT "vehicles.txt"
#define FILE_BIN "vehicles.bin"

vehicle_t create_vehicle(const char *brand, const char *model, int year, const char *owner_name, const char *owner_id) {
    vehicle_t vehicle;
    memset(&vehicle, 0, sizeof(vehicle_t));
    strcpy(vehicle.brand, brand);
    strcpy(vehicle.model, model);
    vehicle.year = year;
    strcpy(vehicle.owner.name, owner_name);
    strcpy(vehicle.owner.id, owner_id);
    vehicle.length = 0;
    return vehicle;
}

int main(int argc, char const *argv[])
{
    forward_list_t *list = NULL;
    create_list(&list);

    vehicle_t data_1 = create_vehicle("Tesla", "Model X", 2023, "Nikita Afanasiev", "1");
    push_front(list, data_1);

    vehicle_t data_2 = create_vehicle("Honda", "Civic", 2021, "J B", "2");
    insert_after(list, data_1, data_2);

    vehicle_t data_3 = create_vehicle("Ford", "Focus", 2019, "JD", "3");
    insert_after(list, data_2, data_3);

    vehicle_t data_4 = create_vehicle("Chevrolet", "Impala", 1967, "John Winchester", "4");
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