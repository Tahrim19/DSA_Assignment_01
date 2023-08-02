#include<iostream>
#include <fstream>
#include <sstream>
using namespace std;

// function for insertion sort.
int InsertionSort(int arr[], int arr_size){
	int j=0, key;
	for(int i=1; i<arr_size; i++){
		key = arr[i];
		j=i-1;
		while(j>=0 && arr[j] > key){
			arr[j+1] = arr[j];
			j=j-1;
		}
		arr[j+1] = key;
	}
}

// function for finding median
int SelectingTheMedian(int arr_size, int arr[]){
	int median;
	InsertionSort(arr , arr_size);
	// if array size is odd, return middle value 
	if ((arr_size%2)!=0){
		median = (arr_size-1)/2;
	}
	// if array is even, return average of two middle values	
	else{
		int mid1 = arr_size / 2;
        int mid2 = arr_size / 2 - 1;
        median = (arr[mid1] + arr[mid2]) / 2;
	}
	return median;
}


int main()
{
	int arr[2000] , arr_size;
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
    inputFile >> arr_size;
    cout << "The size of array is: " << arr_size << endl;

    // read the elements of array
    string numbers;
    inputFile.ignore(); // Ignore the newline character after reading the array size
    getline(inputFile, numbers); // Read the entire line as a string

    // Use stringstream to extract individual numbers separated by commas
    stringstream ss(numbers);
    for (int i = 0; i < arr_size; i++) {
        string num_str;
        getline(ss, num_str, ','); // Extract the number before the comma
        istringstream iss(num_str);
        iss >> arr[i]; // Convert the extracted string to an integer and store it in the array
    }

    // closing the file
    inputFile.close();
    
	
	// using insertion sort function so that array would be printed sorted.
	InsertionSort(arr , arr_size);
	
	// printing the inputted array
	for(int i=0; i<arr_size; i++){
		cout<< arr[i];
		// this will prevent the comma to be printed after the last element.
		if(i<(arr_size-1)){
			cout<<",";
		}	
	}
	cout<< endl;
	
	// calling SelectingTheMedian function
	int med = SelectingTheMedian(arr_size, arr);
	
	// will return the median value.
	cout<< "The median is : " << arr[med]<< endl;
	
	// will return what the position of median value is
	// cout<< " The median is found at at position: " << med; 

return 0;
}

