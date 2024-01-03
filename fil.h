
#ifndef FIL_H
#define FIL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 100
#define REG_SIZE 10

// Define a structure for a person
typedef struct Person
{
    int age;
    char name[SIZE];
    char surname[SIZE];
} person;

// Define a structure for a vehicle that includes a person as an owner
typedef struct Vehicle
{
    char brand[SIZE];
    char type[SIZE];
    char plateNum[SIZE];
    person owner;
} vehicle;

// Function to create a new vehicle and return it
vehicle createVehicle()
{
    vehicle tempVehicle;
    printf("Brand: ");
    scanf("%100s", tempVehicle.brand);
    printf("Type: ");
    scanf("%100s", tempVehicle.type);
    printf("Plate number: ");
    scanf("%100s", tempVehicle.plateNum);
    printf("Name: ");
    scanf("%100s", tempVehicle.owner.name);
    printf("Surname: ");
    scanf("%100s", tempVehicle.owner.surname);
    printf("Age: ");
    while (scanf("%d", &tempVehicle.owner.age) != 1)
    {
        while (getchar() != '\n')
            ;
        printf("Invalid input for age. Please enter a valid integer.\nAge: ");
    }
    return tempVehicle;
}

// Function to get the index of an open position in the vehicle array
int getArrayIndex(vehicle tempReg[REG_SIZE])
{
    int openPosition;
    for (int i = REG_SIZE - 1; i >= 0; i--)
    {
        if (strlen(tempReg[i].brand) == 0)
        {
            openPosition = i;
        }
    }
    return openPosition;
}

// Function to print the details of vehicles in the register
void printRegister(vehicle tempReg[REG_SIZE])
{
    for (int i = 0; i < getArrayIndex(tempReg); i++)
    {
        printf("%d: \n", i + 1);
        printf("Brand: %s\n", tempReg[i].brand);
        printf("Type: %s\n", tempReg[i].type);
        printf("Plate number: %s\n", tempReg[i].plateNum);
        printf("Owners age: %d\n", tempReg[i].owner.age);
        printf("Owners name: %s\n", tempReg[i].owner.name);
        printf("Owners surname: %s\n", tempReg[i].owner.surname);
        printf("\n");
    }
}

// Function to remove a vehicle from the register
void removeVehicle(vehicle tempReg[REG_SIZE])
{
    int input;

    printRegister(tempReg);
    printf("Enter the position of the vehicle you want to remove\n");

    // Check if the input is a valid integer
    while (scanf("%d", &input) != 1)
    {
        while (getchar() != '\n') // Clear the input buffer
            ;

        printf("Invalid input. Please enter a valid integer: ");
    }

    // Check if the input is within the valid range
    if (input >= 1 && input <= getArrayIndex(tempReg))
    {
        for (input -= 1; input < getArrayIndex(tempReg); input++)
        {
            tempReg[input] = tempReg[input + 1];
        }
    }
    else
    {
        printf("The vehicle you want to remove does currently not exist in the register\n");
    }
}


// Function to add a new vehicle to the register
void addToRegister(vehicle tempReg[REG_SIZE])
{
    if (getArrayIndex(tempReg) < REG_SIZE)
    {
        tempReg[getArrayIndex(tempReg)] = createVehicle();
    }
    else
    {
        printf("Register is full\n");
    }
}

// Function to sort the vehicles in the register based on the brand
void brandSort(vehicle tempReg[REG_SIZE])
{
    vehicle temp;
    for (int i = 0; i < getArrayIndex(tempReg) - 1; i++)
    {
        for (int j = 0; j < getArrayIndex(tempReg) - i - 1; j++)
        {
            if (strcmp(tempReg[j].brand, tempReg[j + 1].brand) > 0)
            {
                temp = tempReg[j];
                tempReg[j] = tempReg[j + 1];
                tempReg[j + 1] = temp;
            }
        }
    }
}

void printVehicleInfo(vehicle tempReg[REG_SIZE])
{
    int input;
    printRegister(tempReg);
    printf("Enter the position of the vehicle to display information: ");
    scanf("%d", &input);

    if (input >= 1 && input <= getArrayIndex(tempReg) + 1)
    {
        printf("\nDetails of vehicle at position %d:\n", input);
        printf("Brand: %s\n", tempReg[input - 1].brand);
        printf("Type: %s\n", tempReg[input - 1].type);
        printf("Plate number: %s\n", tempReg[input - 1].plateNum);
        printf("Owner's age: %d\n", tempReg[input - 1].owner.age);
        printf("Owner's name: %s\n", tempReg[input - 1].owner.name);
        printf("Owner's surname: %s\n\n", tempReg[input - 1].owner.surname);
    }
    else
    {
        printf("Invalid position. No information displayed.\n");
    }
}

void printFullRegister(vehicle tempReg[REG_SIZE])
{
    printf("\nVehicle Register:\n");
    for (int i = 0; i < getArrayIndex(tempReg); i++)
    {
        printf("Position %d:\n", i + 1);
        printf("Brand: %s\n", tempReg[i].brand);
        printf("Type: %s\n", tempReg[i].type);
        printf("Plate number: %s\n", tempReg[i].plateNum);
        printf("Owner's age: %d\n", tempReg[i].owner.age);
        printf("Owner's name: %s\n", tempReg[i].owner.name);
        printf("Owner's surname: %s\n\n", tempReg[i].owner.surname);
        printf("\n");
    }
}

// Function to read vehicle details from a file into the register
void readFromFile(vehicle tempReg[REG_SIZE])
{
    FILE *fp = NULL;
    if ((fp = fopen("register.txt", "r")) == NULL)
    {
        printf("File could not be opened\n");
    }
    else
    {
        for (int i = 0; i < REG_SIZE; i++)
        {
            fscanf(fp, "%s\n%s\n%s\n%d\n%s\n%s\n\n", tempReg[i].brand, tempReg[i].type, tempReg[i].plateNum, &tempReg[i].owner.age, tempReg[i].owner.name, tempReg[i].owner.surname);
        }
    }
    fclose(fp);
}

// Function to write vehicle details from the register to a file
void writeToFile(vehicle tempReg[REG_SIZE])
{
    FILE *fp = NULL;
    if ((fp = fopen("register.txt", "w")) == NULL)
    {
        printf("File could not be opened\n");
    }
    else
    {
        for (int i = 0; i < getArrayIndex(tempReg); i++)
        {
            fprintf(fp, "%s\n%s\n%s\n%d\n%s\n%s\n\n", tempReg[i].brand, tempReg[i].type, tempReg[i].plateNum, tempReg[i].owner.age, tempReg[i].owner.name, tempReg[i].owner.surname);
        }
    }
    fclose(fp);
}
#endif