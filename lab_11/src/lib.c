#include <lib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void registerVehicle(vehicle_t *vehicle, owner_t owner)
{
    strncpy(vehicle->owner.name, owner.name, MAX_NAME_LENGTH - 1);
    vehicle->owner.name[MAX_NAME_LENGTH - 1] = '\0';
    strncpy(vehicle->owner.id, owner.id, MAX_ID_LENGTH - 1);
    vehicle->owner.id[MAX_ID_LENGTH - 1] = '\0';

    vehicle->length = 0;

    printf("Vehicle %s registered to %s now.\n", vehicle->model, vehicle->owner.name);
}

void addServiceRecord(vehicle_t *vehicle, service_t service)
{
    if (vehicle->length >= MAX_SERVICES_AMOUNT)
    {
        printf("Cannot add more services to %s.\n", vehicle->model);
        return;
    }

    strncpy(vehicle->services[vehicle->length].name, service.name, MAX_SERVICE_NAME_LENGTH - 1);
    vehicle->services[vehicle->length].name[MAX_SERVICE_NAME_LENGTH - 1] = '\0';
    vehicle->services[vehicle->length].price = service.price;
    vehicle->length++;

    printf("Service record added to %s.\n", vehicle->model);
}

void displayServiceHistory(const vehicle_t *vehicle)
{
    if (vehicle->length == 0)
    {
        printf("No service records for %s.\n", vehicle->model);
        return;
    }

    printf("Service history of %s:\n", vehicle->model);

    for (int i = 0; i < vehicle->length; i++)
    {
        printf("Service %d: %s, %.2f\n", i + 1, vehicle->services[i].name, vehicle->services[i].price);
    }
}

void display(const vehicle_t *vehicle)
{
    if (vehicle->owner.name[0] == '\0')
    {
        printf("No vehicle registered.\n");
        return;
    }

    printf("Vehicle %s %s %d\n", vehicle->brand, vehicle->model, vehicle->year);
    printf("Owner: %s (ID: %s)\n", vehicle->owner.name, vehicle->owner.id);

    displayServiceHistory(vehicle);
}

void modifyVehicle(vehicle_t *vehicle)
{
    if (vehicle->owner.name[0] == '\0')
    {
        printf("No vehicle to modify.\n");
        return;
    }

    printf("Modify Vehicle Details:\n");

    printf("Enter new brand (current: %s): ", vehicle->brand);
    fgets(vehicle->brand, sizeof(vehicle->brand), stdin);
    vehicle->brand[strcspn(vehicle->brand, "\n")] = '\0';

    printf("Enter new model (current: %s): ", vehicle->model);
    if (fgets(vehicle->model, sizeof(vehicle->model), stdin) != NULL)
    {
        vehicle->model[strcspn(vehicle->model, "\n")] = '\0';
    }

    char year_buffer[4];
    printf("Enter new year (current: %d): ", vehicle->year);
    if (fgets(year_buffer, sizeof(year_buffer), stdin) != NULL)
    {
        vehicle->year = atoi(year_buffer);
    }
    printf("Vehicle details updated.\n");
}

void modifyOwner(owner_t *owner)
{
    if (owner->name[0] == '\0')
    {
        printf("No owner to modify.\n");
        return;
    }
    printf("Modify Owner Details:\n");

    printf("Enter new name (current: %s): ", owner->name);
    if (fgets(owner->name, sizeof(owner->name), stdin) != NULL)
    {
        owner->name[strcspn(owner->name, "\n")] = '\0';
    }
    printf("Enter new ID (current: %s): ", owner->id);
    if (fgets(owner->id, sizeof(owner->id), stdin) != NULL)
    {
        owner->id[strcspn(owner->id, "\n")] = '\0';
    }

    printf("Owner details updated.\n");
}

bool isVehicleExist(const vehicle_t *vehicle, const char *id)
{
    return strcmp(vehicle->owner.id, id) == 0;
}