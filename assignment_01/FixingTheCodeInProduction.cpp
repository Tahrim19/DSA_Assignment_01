#include<iostream>
#include <fstream>
#include <sstream>
using namespace std;

// function for insertion sort.
int InsertionSort(int arr[], int len){
	int j=0, key;
	for(int i=1; i<len; i++){
		key = arr[i];
		j=i-1;
		while(j>=0 && arr[j] > key){
			arr[j+1] = arr[j];
			j=j-1;
		}
		arr[j+1] = key;
	}
}

// function for binary search
int FixingTheCodeInProduction(int arr[], int len, int num){
	int left = 0;
	int right = len-1; 
	
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == num) {
            return mid; // Found the number at index mid
        } else if (arr[mid] < num) {
            left = mid + 1; // number is in the right half
        } else {
            right = mid - 1; // number is in the left half
        }
    }

    return -1;
}


int main()
{
	int num, len, arr[2000];
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
    
    // number to be searched
    inputFile >> num;
    cout << "The number to be searched: " << num << endl;

    // read the array size
    inputFile >> len;
    cout << "The size of array is: " << len << endl;

    // read the elements of array
    string numbers;
    inputFile.ignore(); // ignore the newline character after reading the array size
    getline(inputFile, numbers); // iead the entire line as a string

    // use stringstream to extract individual numbers separated by commas
    stringstream ss(numbers);
    for (int i = 0; i < len; i++) {
        string num_str;
        getline(ss, num_str, ','); // extract the number before the comma
        istringstream iss(num_str);
        iss >> arr[i]; // convert the extracted string to an integer and store it in the array
    }

    // closing the file
    inputFile.close();
    
	// sorting the array which is necessary for binary search
	InsertionSort(arr, len);
	
	// printing the array
	for(int i=0; i<len; i++){
		cout<< arr[i];
		// this will prevent the comma to be printed after the last element.
		if(i<(len-1)){
			cout<<",";
		}	
	}
	cout<< endl;
	
	int position = FixingTheCodeInProduction(arr, len, num);

    // printing the result
    if ( position != -1) {
        cout << "Number " << num << " found at index " << position << endl;
    } else {
        cout << "Number " << num << " not found in the array."<< endl << position;
        
    }
	
	
return 0;
}

