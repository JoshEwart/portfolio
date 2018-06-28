#include <sstream>
#include <iostream>
using namespace std;
//craete InsertionSort function
void InsertionSort(){
	int length;
	cout << "Hello, and welcome to sorting 101" << endl;
	cout << "Please enter in a length for how many numbers you wish to sort, without letters, spaces, or special characters." << endl;
	cin >> length;
	//length = length-1;
	if(!cin){
		cin.clear();
		cin >> length;
	}
	//create data array and set up variables for swapping
	int data [length];
	//ask for the data
	cout << "Now please enter in the numbers you wish to organize, seperated by spaces. Warning: if the list is out of bounds, data will be lost." << endl;
	cout << "Enter in the numbers set in the format '1' enter, '2' enter, for each element." << endl;
	int text;
	for(int i=0; i<length; i++){
		cin >> text;
		data[i] = text;
	}
	//print out the unsorted data
	cout << "unsorted List: " << endl;
	for(int i=0; i<length-1; i++){
		//add formatting
		cout<< " "<< data[i] << ",";
	}
	cout<< ""<<endl;
	//create sorting function portion of code
	//create 'j' and 'temp' incase of position switching.
	int j=0;
	int temp;
	for (int i= 1; i < length; i++){
		//going through each element...
		//set "temp" to the current element
		temp= data[i];
		//go through all elements before, and if less than current element, swap current element.
		for (j= i-1; (j>=0) && (temp<data[j]); j--){
			data[j+1] = data[j];
		}
		data[j+1]= temp;
	}
	//now the data is sorted, print out results
	cout << "Sorted list: "<<endl;
	for(int p=0; p<length-1; p++){
		//add in formatting for the data
		cout << data[p] << ", ";
	}
}
//run InsertionSort
int main(){

	InsertionSort();
}
