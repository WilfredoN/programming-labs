#include <stdbool.h>
#include <stddef.h>

#ifndef LIB_H
#define LIB_H

#define MAX_SERVICES_AMOUNT 10
#define MAX_SERVICE_NAME_LENGTH 100
#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 50

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

// MAIN
void registerVehicle(vehicle_t *vehicle, owner_t owner);      // Registers a vehicle to an owner
void addServiceRecord(vehicle_t *vehicle, service_t service); // Adds a service record to a vehicle.
void displayServiceHistory(const vehicle_t *vehicle);         // Displays the service history of a vehicle.

// SECONDARY
void display(const vehicle_t *vehicle); // Displays the vehicle information.
int modifyVehicle(vehicle_t *vehicle);  // Modifies the vehicle information.
int modifyOwner(owner_t *owner);        // Modifies the owner information.

// helpers
bool isVehicleExist(const vehicle_t *vehicle, const char *id); // Checks if vehicle exists

#endif // LIB_H