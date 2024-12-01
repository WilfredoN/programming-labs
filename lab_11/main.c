#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lib.h"

int main()
{
    vehicle_t vehicle;
    bool isVehicleCreated = false;
    char choice = '\0';

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
        if (scanf(" %c", &choice) != 1)
        {
            printf("Invalid input.\n");
        }
        getchar();

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
                scanf(" %99[^\n]", owner.name);

                printf("Enter the owner's ID: ");
                scanf(" %99[^\n]", owner.id);

                if (isVehicleExist(&vehicle, owner.id))
                {
                    printf("Vehicle with ID %s already exists.\n", owner.id);
                    break;
                }

                printf("Enter the vehicle's brand: ");
                scanf(" %99[^\n]", vehicle.brand);

                printf("Enter the vehicle's model: ");
                scanf(" %99[^\n]", vehicle.model);

                printf("Enter the vehicle's year: ");
                scanf("%d", &vehicle.year);

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
                scanf(" %99[^\n]", id);
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
                scanf(" %99[^\n]", id);
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
                scanf(" %99[^\n]", id);
                if (strcmp(vehicle.owner.id, id) != 0)
                {
                    printf("Vehicle with ID %s not found.\n", id);
                    break;
                }

                printf("Enter the service name: ");
                scanf(" %99[^\n]", service.name);

                printf("Enter the service price: ");
                scanf("%f", &service.price);

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
            getchar();
            system("clear");
        }
    }

    return 0;
}