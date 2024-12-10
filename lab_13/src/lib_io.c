#include "lib_io.h"

bool save_to_text(forward_list_t *list, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        return false;
    }

    node_t *current = list->head->next;
    while (current)
    {
        fprintf(file, "%s,%s,%d,%s,%s\n",
                current->data.brand,
                current->data.model,
                current->data.year,
                current->data.owner.name,
                current->data.owner.id);
        current = current->next;
    }

    fclose(file);
    return true;
}

bool load_from_text(forward_list_t *list, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        return false;
    }

    char brand[MAX_NAME_LENGTH];
    char model[MAX_NAME_LENGTH];
    int year;
    char owner_name[MAX_NAME_LENGTH];
    char owner_id[MAX_ID_LENGTH];

    while (fscanf(file, "%[^,],%[^,],%d,%[^,],%s\n",
                  brand, model, &year, owner_name, owner_id) == 5)
    {
        vehicle_t vehicle;
        strcpy(vehicle.brand, brand);
        strcpy(vehicle.model, model);
        vehicle.year = year;
        strcpy(vehicle.owner.name, owner_name);
        strcpy(vehicle.owner.id, owner_id);
        vehicle.length = 0;
        push_front(list, vehicle);
    }

    fclose(file);
    return true;
}

bool save_to_binary(forward_list_t *list, const char *filename)
{
    FILE *file = fopen(filename, "wb");
    if (!file)
    {
        return false;
    }

    node_t *current = list->head->next;
    while (current)
    {
        fwrite(&current->data, sizeof(vehicle_t), 1, file);
        current = current->next;
    }

    fclose(file);
    return true;
}

bool load_from_binary(forward_list_t *list, const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (!file)
    {
        return false;
    }

    vehicle_t vehicle;
    while (fread(&vehicle, sizeof(vehicle_t), 1, file) == 1)
    {
        push_front(list, vehicle);
    }

    fclose(file);
    return true;
}