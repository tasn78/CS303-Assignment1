// Tom Steinman
// CS303-0001
// Created by Owner on 6/12/2023.
// Assignment 1

#include "ArrayOfIntegers.h"

// Only function needed to call in main, runs entire menu and function options
void arrayMain() {
    string file = "array.txt";    // Change file name here
    int arraySize = 100;          // Change amount of integers in file if not 100

    int myArray[150];
    int menuSelection = 10;
    int userNumberToFind;
    int userIndex;
    int arrayIndexFound;
    int newReplacementNumber;
    int integerToAddToArray;
    CreateArray(myArray, file, arraySize);  // Creates array from file
    while (menuSelection != 0) {
        menuSelection = menuOptions();      // Gives user menu options to search or modify the array

        if (menuSelection == 1) {
            userNumberToFind = NumberToSearch();                          // User input to find a certain integer
            CheckIfIntegerInArray(myArray, arraySize, userNumberToFind);  // Checks if integer is in array
        }
        else if (menuSelection == 2) {
            ModifyArrayByIndex(myArray, arraySize);  // User input to choose replacement number
            printArray(myArray, arraySize);
            continue;
        }
        else if (menuSelection == 3) {
            AddIntegerToArray(myArray, arraySize);          // Adds integer to end of array
            arraySize += 1;
            printArray(myArray, arraySize);
            continue;
        }
        else if (menuSelection == 4) {
            removeIndexFromArray(myArray, arraySize);      // Removes integer from array by index
            arraySize -= 1;
            printArray(myArray, arraySize);
            continue;
        }
        else {
            break;
        }
    }
}


// Creates array from file of integers and inserts them into an array
void CreateArray(int myArray[], string& file, int& arraySize) {
    ifstream fin;
    fin.open(file);
    if (!fin.is_open()) {
        cout << "Unable to open input file\n";
        exit(0);
    }

    else {
        cout << "Using data from : " << file << endl;
        for (int i = 0; i < arraySize; i++) {
            fin >> myArray[i];
        }
    }
    fin.close();

    printArray(myArray, arraySize);
}

// Creates a menu option to make continual changes to the array by continuing to loop through menu until quit (0) is chosen
int menuOptions() {
    string menuChoice;
    while (true) {
        try {
            cout << "\nChoose a menu option:" << endl;
            cout << "1) Search if number exists and return the index" << endl;
            cout << "2) Modify an integer based on index chosen" << endl;
            cout << "3) Add new integer to the end of the array" << endl;
            cout << "4) Provide index to remove from array" << endl;
            cout << "0) Quit " << endl;
            cin >> menuChoice;
            cout << endl;
            if (menuChoice == "1" || menuChoice == "2" || menuChoice == "3" || 
                menuChoice == "4" || menuChoice == "0") {
                return stoi(menuChoice);
            }
            else {
                throw menuChoice;
            }   
        }
        catch (invalid_argument) {
            cout << "Please use options 1, 2, 3, 4 or 0" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        catch (int menuChoice) {
            cout << "Please use options 1, 2, 3 or 4" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        catch (...) {
            cout << "Please use options 1, 2, 3 or 4" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }
}

// Function to search for a number in the array
int NumberToSearch() {
    int userNumber;
    while (true) {
        try {
            cout << "What number would you like to search for in the array?" << endl;
            cin >> userNumber;
            cout << endl;
        }
        catch (invalid_argument) {
            cout << "Please use integers only" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        return userNumber;
    }
}

void CheckIfIntegerInArray(int myArray[], int& arraySize, int& numberToFind) {
    int found = 0;
    int index;
    for (int i = 0; i < arraySize; i++) {
        if (myArray[i] == numberToFind){
            found = 1;
            index = i;
        }
    }
    if (found == 1) {
        cout << "The number " << numberToFind << " is at index " << index << endl;
    }
    else {
        cout << "The number " << numberToFind << " is not in the array" << endl;
    }
}

int indexSelection(int& arraySize) {
    string stringIndex;
    int selectedIndex;
    while (true) {
        try {
            cout << "What index would you like to choose?" << endl;
            cin >> stringIndex;
            cout << endl;
            selectedIndex = stoi(stringIndex);
            if (selectedIndex >= 0 && selectedIndex < arraySize) {
                return selectedIndex;
            }
            else {
                throw selectedIndex;
            }
        }
        catch (invalid_argument) {
            cout << "Please use an integer from 0 to " << arraySize - 1 << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        catch (int selectedIndex) {
            cout << "Please use an integer from 0 to " << arraySize - 1 << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }
}

void ModifyArrayByIndex(int myArray[], int& arraySize) {
    int newInteger;
    int userIndex;
    int oldInteger;
    while (true) {
        userIndex = indexSelection(arraySize);                          // User input to choose index
        try {
            cout << "Please choose the new integer you would like to replace at index " << userIndex << endl;
            cin >> newInteger;
            cout << endl;
        }
        catch (invalid_argument) {
            cout << "Your input was not an integer, please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        catch (...) {
            cout << "Your input was not an integer, please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        oldInteger = myArray[userIndex];
        cout << "Old value at index " << userIndex << " : " << oldInteger << endl;
        myArray[userIndex] = newInteger;
        cout << "Old value at index " << userIndex << " : " << newInteger << endl << endl;
        break;
    }
}


void printArray(int array[], int& arraySize) {
    cout << "Your array consists of [\n";
    for (int i = 0; i < arraySize; i++) {
        if (i % 10 == 0 && i != 0) {
            cout << endl;
        }
        cout << setw(5) << array[i] << " ";
    }
    cout << "]\n";
}


void AddIntegerToArray(int myArray[], int& arraySize) {
    int newInteger;
    while (true) {
        try {
            cout << "Please choose the new integer you would like to add at the end of the array" << endl;
            cin >> newInteger;
            cout << endl;
            if (!cin) {
                throw newInteger;
            }
        }
        catch (invalid_argument) {
            cout << "Your input was not an integer, please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        catch (int newInteger) {
            cout << "Your input was not an integer, please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }
    myArray[arraySize] = newInteger;
}

void removeIndexFromArray(int myArray[], int& arraySize) {
    int indexToRemove;
    while (true) {
        try {
            cout << "Please choose the index you would like to remove from the array" << endl;
            cin >> indexToRemove;
            cout << endl;
        }
        catch (invalid_argument) {
            cout << "Your input was not an integer, please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        catch (...) {
            cout << "Your input was not an integer, please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }
    for (int i = indexToRemove; i < arraySize - 1; i++) {
        myArray[i] = myArray[i + 1];
    }
}