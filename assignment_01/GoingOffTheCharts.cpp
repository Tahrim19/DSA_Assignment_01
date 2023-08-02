#include<iostream>
#include <fstream>
#include <sstream>
using namespace std;

// function to print number.
int MaximumNumber(int a,int b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}

// function for calculating maximum consecutive days worked.
int GoingOffTheCharts(int arr[], int wh){
	int mcd=0; // maximum consecutive days of overtime
	int cd=0; // consecutive days of overtime
	for(int i= 0; i<wh; i++){
		if(arr[i]>6){
			cd++;
		}
		else{
			cd=0;
		}
		mcd = MaximumNumber(mcd,cd) ;
	}
	return mcd ;
}

int main()
{
	int wh ,arr[100];
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
    inputFile >> wh;
    cout << "The size of array is: " << wh << endl;

    // read the elements of array
    string numbers;
    inputFile.ignore(); // Ignore the newline character after reading the array size
    getline(inputFile, numbers); // Read the entire line as a string

    // Use stringstream to extract individual numbers separated by commas
    stringstream ss(numbers);
    for (int i = 0; i < wh; i++) {
        string num_str;
        getline(ss, num_str, ','); // Extract the number before the comma
        istringstream iss(num_str);
        iss >> arr[i]; // Convert the extracted string to an integer and store it in the array
    }

    // closing the file
    inputFile.close();
    
    cout<< "The array is:"<<" ";
    // printing the array
	for(int i=0; i<wh; i++){
		cout<< arr[i];
		// this will prevent the comma to be printed after the last element.
		if(i<(wh-1)){
			cout<<",";
		}	
	}
	
	cout<< endl;
	// calling GoingOffTheCharts function 
	int workinghours = GoingOffTheCharts(arr,wh);
	
	// printing the maximum no. of days of overtime. 
	cout<<"Number of maximum consecutive days worked are: "<< workinghours;
    return 0;
}
