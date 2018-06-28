//Sorting Algorithm Creation

//begin by importing a string seperator
using namespace std;
#include <iostream>
#include <sstream>


void selectionSort(){
	//int array and integer
	int length;
	//set up variables for swapping
	int temp;
	int min;
	//set up variables for user input
	int text;
	//set up user input
	cout << "Hello, and welcome to sorting 101" << endl;
	cout << "Please enter in a length for how many numbers you wish to sort, without letters, spaces, or special characters." << endl;
	cin >> length;
	//length = length-1;
	if(!cin){
		cin.clear();
		cin >> length;
	}
	int integers[length];
	cout << "Now please enter in the numbers you wish to organize, seperated by spaces. Warning: if the list is out of bounds, data will be lost." << endl;
	cout << "Enter in the numbers set in the format '1' enter, '2' enter, for each element." << endl;
	for(int i=0; i<length; i++){
		cin >> text;
		integers[i] = text;
	}
	cout << "your array (list) is:" << endl;
	for(int a=0; a<length; a++){
		cout << integers[a] << "," << endl;
	}

	//create sorting function portion of code
		//go through, and find the minimum number
	for (int find = 0; find < length-1; find++){
		//set the minimum number
		min = find;
		//go through and search the remaining of the list
		for (int search = find+1; search < length; search++){
			if (integers[search] < integers[min]){
				//if the next element is the minimum, set as the minimum 
				min = search;
			}
		}
		//replace integer's find element with the smallest element
		temp = integers[find];
		integers[find] = integers[min];
		integers[min] = temp;
	}
	cout << "Your sorted list:"<<endl;
	for(int p=0; p<length; p++){
		cout << integers[p] << ",";
	}
}
	
int main(){
	selectionSort();
}
