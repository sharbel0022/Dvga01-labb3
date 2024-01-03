#include "fil.h"

int main()
{
    vehicle vehicleReg[REG_SIZE] = {};
    int option;
    bool alive = true;

    readFromFile(vehicleReg);

    while (alive)
    {
        printf("\nMenu:\n");
        printf("1. Add Vehicle\n");
        printf("2. Remove Vehicle\n");
        printf("3. Sort Registry\n");
        printf("4. Show Vehicle Details\n");
        printf("5. Show Entire Registry\n");
        printf("0. Quit\n");

        printf("Enter your choice: ");
        if (scanf("%d", &option) != 1) {
            // Clear input buffer in case of non-integer input
            while (getchar() != '\n');
            printf("Invalid input. Please enter a valid menu option.\n");
            continue;
        }

        switch (option)
        {
        case 1:
            addToRegister(vehicleReg);
            break;
        case 2:
            if (getArrayIndex(vehicleReg) != 0)
            {
                removeVehicle(vehicleReg);
            }
            else
            {
                printf("Register is empty. No vehicle to remove.\n");
            }
            break;
        case 3:
            brandSort(vehicleReg);
            printf("Registry sorted by brand.\n");
            break;
        case 4:
            if (getArrayIndex(vehicleReg) != 0)
            {
                printVehicleInfo(vehicleReg);
            }
            else
            {
                printf("Register is empty.\n");
            }
            break;
        case 5:
            if (getArrayIndex(vehicleReg) != 0)
            {
                printFullRegister(vehicleReg);
            }
            else
            {
                printf("Register is empty.\n");
            }
            break;
        case 0:
            writeToFile(vehicleReg);
            alive = false;
            break;
        default:
            printf("Invalid option. Please choose a valid menu option.\n");
        }
    }

    return 0;
}
