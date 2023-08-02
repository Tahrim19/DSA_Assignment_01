#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// function to sort the array.
int BribedQueue(int arr[], int q) {
    int count = 0;
    // using bubble sort
    for (int i = 0; i < q - 1; i++) {
        for (int j = 0; j < q - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }
        }
    }
    return count;
}

int main() {
    int size, arr[100];
    string filepath;

    // taking input of filepath
    cout << "Enter the file path:" << endl;
    getline(cin, filepath);
    
    // opening the file which the user inputted the path of.
    ifstream inputFile(filepath.c_str()); // using .c_str() to change string into char.
    if (!inputFile.is_open()) {
        cout << "File could not be opened!" << endl;
        return 1;
    }

    // read the array size
    inputFile >> size;
    cout << "The size of array is: " << size << endl;

    // read the elements of array
    string numbers;
    inputFile.ignore(); // Ignore the newline character after reading the array size
    getline(inputFile, numbers); // Read the entire line as a string

    // Use stringstream to extract individual numbers separated by commas
    stringstream ss(numbers);
    for (int i = 0; i < size; i++) {
        string num_str;
        getline(ss, num_str, ','); // Extract the number before the comma
        istringstream iss(num_str);
        iss >> arr[i]; // Convert the extracted string to an integer and store it in the array
    }

    // closing the file
    inputFile.close();
    
    // Print the array elements
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        // this will prevent the comma to be printed after the last element
        if (i < size - 1)
            cout << ",";
    }
    cout << endl;
    
    // calling the BribedQueue function.
    int bribes = BribedQueue(arr, size);

    // printing the number of turns it took to sort the array.
    cout << "Number of bribes: " << bribes;

    return 0;
}

