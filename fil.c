#include "fil.h"

vehicle createVehicle();
int getArrayIndex(vehicle tempReg[REG_SIZE]);
void printRegister(vehicle reg[REG_SIZE]);
void removeVehicle(vehicle reg[REG_SIZE]);
void addToRegister(vehicle reg[REG_SIZE]);
void brandSort(vehicle reg[REG_SIZE]);
void readFromFile(vehicle tempReg[REG_SIZE]);
void writeToFile(vehicle reg[REG_SIZE]);
