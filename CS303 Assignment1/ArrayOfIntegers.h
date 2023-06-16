#pragma once
// Tom Steinman
// CS303-0001
// Created by Owner on 6/12/2023.
// Assignment 1

#ifndef CS303_ASSIGNMENT_1_ARRAYOFINTEGERS_H
#define CS303_ASSIGNMENT_1_ARRAYOFINTEGERS_H

#endif //CS303_ASSIGNMENT_1_ARRAYOFINTEGERS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void arrayMain();
void CreateArray(int myArray[], string& file, int& arraySize);
int menuOptions();
int NumberToSearch();
void CheckIfIntegerInArray(int myArray[], int& arraySize, int& numberToFind);
int indexSelection(int& arraySize);
void ModifyArrayByIndex(int myArray[], int& arraySize);
void printArray(int array[], int& arraySize);
void AddIntegerToArray(int myArray[], int& arraySize);
void removeIndexFromArray(int myArray[], int& arraySize);
