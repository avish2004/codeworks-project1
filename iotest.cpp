//============================================================================
// Name        : iotest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

const int ARRAY_SIZE = 50;
const int ELEMENT_RANGE = 10;

void countOccurrences(int array[], int size);

int main() {
    int array[ARRAY_SIZE] = {0};
    int size = 0;
    char option;
    string filename;

    cout << "Read array from keyboard or file? (K/F): ";
    cin >> option;

    if (option == 'F' || option == 'f') {
        cout << "Enter filename: ";
        cin >> filename;

        ifstream infile(filename.c_str());
        if (!infile) {
            cerr << "Error opening file " << filename << endl;
            return 1;
        }

        int value;
        while (infile >> value) {
            array[size++] = value;
        }

        infile.close();
    } else {
        cout << "Enter up to 50 integers between 1 and 10, (0 to stop):\n";
        int value;
        do {
            cin >> value;
            if (value > 0 && value <= ELEMENT_RANGE && size < ARRAY_SIZE) {
                array[size++] = value;
            }
        } while (value != 0);
    }

    sort(array, array + size);
    countOccurrences(array, size);

    ofstream outfile("LabOutput4-2.txt");
    if (!outfile) {
        cerr << "Error opening file LabOutput4-2.txt" << endl;
        return 1;
    }

    outfile << "N\tCount" << endl;
    for (int i = ELEMENT_RANGE; i >= 1; i--) {
        if (countArray[i] != 0) {
            cout << i << "\t" << countArray[i] << ;
            outfile << i << "\t" << countArray[i] << ;
            countArray[i] = 0;
        }
    }

    outfile.close();

    return 0;
}

void countOccurrences(int array[], int size) {
    int countArray[ELEMENT_RANGE + 1] = {0};

    for (int i = 0; i < size; i++) {
        countArray[array[i]]++;
    }

    for (int i = 1; i <= ELEMENT_RANGE; i++) {
        countArray[i] = countArray[i] + countArray[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        countArray[array[i]]--;
        if (countArray[array[i]] == 0) {
            cout << array[i] << "\t" << countArray[array[i] + 1] << endl;
            countArray[array[i]] = countArray[array[i] + 1];
        }
    }
}


