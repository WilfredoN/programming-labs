#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lib.h"

#define BUFFER_SIZE 100

int main()
{
    vehicle_t vehicle;
    bool isVehicleCreated = false;
    char choice = '\0';
    char buffer[BUFFER_SIZE];

    memset(&vehicle, 0, sizeof(vehicle));

    while (choice != 'q')
    {
        printf("Choose an option:\n");

        if (!isVehicleCreated)
        {
            printf("1. Add Vehicle\n");
        }
        if (isVehicleCreated)
        {
            printf("2. Modify Vehicle\n");
            printf("3. Modify Owner\n");
            printf("4. Add Service\n");
            printf("5. Clear Data\n");
            printf("6. Display\n");
        }
        printf("q. Quit\n");
        printf("Enter your choice: ");

        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            if (sscanf(buffer, " %c", &choice) != 1)
            {
                printf("Invalid input.\n");
                choice = '\0';
            }
        }

        switch (choice)
        {
        case '1':
            if (isVehicleCreated)
            {
                printf("Vehicle already exists.\n");
                break;
            }
            {
                owner_t owner;

                printf("Enter the owner's name: ");
                if (fgets(owner.name, sizeof(owner.name), stdin) != NULL)
                {
                    owner.name[strcspn(owner.name, "\n")] = '\0';
                }

                printf("Enter the owner's ID: ");
                if (fgets(owner.id, sizeof(owner.id), stdin) != NULL)
                {
                    owner.id[strcspn(owner.id, "\n")] = '\0';
                }

                if (isVehicleExist(&vehicle, owner.id))
                {
                    printf("Vehicle with ID %s already exists.\n", owner.id);
                    break;
                }

                printf("Enter the vehicle's brand: ");
                if (fgets(vehicle.brand, sizeof(vehicle.brand), stdin) != NULL)
                {
                    vehicle.brand[strcspn(vehicle.brand, "\n")] = '\0';
                }

                printf("Enter the vehicle's model: ");
                if (fgets(vehicle.model, sizeof(vehicle.model), stdin) != NULL)
                {
                    vehicle.model[strcspn(vehicle.model, "\n")] = '\0';
                }

                printf("Enter the vehicle's year: ");
                if (fgets(buffer, sizeof(buffer), stdin) != NULL)
                {
                    if (sscanf(buffer, "%d", &vehicle.year) != 1)
                    {
                        printf("Invalid year input.\n");
                        break;
                    }
                }

                registerVehicle(&vehicle, owner);
                isVehicleCreated = true;
            }
            break;
        case '2':
            if (!isVehicleCreated)
            {
                printf("No vehicles available to modify.\n");
                break;
            }
            {
                char id[MAX_ID_LENGTH];
                printf("Enter Owner ID to modify Vehicle: ");
                if (fgets(id, sizeof(id), stdin) != NULL)
                {
                    id[strcspn(id, "\n")] = '\0';
                }
                if (strcmp(vehicle.owner.id, id) == 0)
                {
                    modifyVehicle(&vehicle);
                }
                else
                {
                    printf("Vehicle with ID %s not found.\n", id);
                }
            }
            break;
        case '3':
            if (!isVehicleCreated)
            {
                printf("No owners available to modify.\n");
                break;
            }
            {
                char id[MAX_ID_LENGTH];
                printf("Enter Owner ID to modify Owner: ");
                if (fgets(id, sizeof(id), stdin) != NULL)
                {
                    id[strcspn(id, "\n")] = '\0';
                }
                if (strcmp(vehicle.owner.id, id) == 0)
                {
                    modifyOwner(&vehicle.owner);
                }
                else
                {
                    printf("Owner with ID %s not found.\n", id);
                }
            }
            break;
        case '4':
            if (!isVehicleCreated)
            {
                printf("No vehicles available to add services.\n");
                break;
            }
            {
                char id[MAX_ID_LENGTH];
                service_t service;
                printf("Enter Owner ID to add Service: ");
                if (fgets(id, sizeof(id), stdin) != NULL)
                {
                    id[strcspn(id, "\n")] = '\0';
                }
                if (strcmp(vehicle.owner.id, id) != 0)
                {
                    printf("Vehicle with ID %s not found.\n", id);
                    break;
                }

                printf("Enter the service name: ");
                if (fgets(service.name, sizeof(service.name), stdin) != NULL)
                {
                    service.name[strcspn(service.name, "\n")] = '\0';
                }

                printf("Enter the service price: ");
                if (fgets(buffer, sizeof(buffer), stdin) != NULL)
                {
                    if (sscanf(buffer, "%f", &service.price) != 1)
                    {
                        printf("Invalid price input.\n");
                        break;
                    }
                }

                addServiceRecord(&vehicle, service);
                printf("Service added to %s.\n", vehicle.model);
                break;
            }
        case '5':
            memset(&vehicle, 0, sizeof(vehicle));
            isVehicleCreated = false;
            printf("Data cleared.\n");
            break;
        case '6':
            if (!isVehicleCreated)
            {
                printf("No vehicles to display.\n");
                break;
            }
            display(&vehicle);
            printf("\n");
            break;
        case 'q':
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }

        if (choice != 'q')
        {
            printf("Press Enter to continue...");
            fgets(buffer, sizeof(buffer), stdin);
            system("clear");
        }
    }

    return 0;
}