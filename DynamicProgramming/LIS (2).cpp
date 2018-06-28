#include <iostream>
#include <fstream>

using namespace std;

int main(){
	//read in file
	ifstream infile("incseq.txt");
	int data;

	int size;
	int c = 0;
	int input[15];
	while (infile >> data){
		//set each line to a position in the array
		if (c == 0){
			//first line is array size
			size = data;
		}
		else{
			input[c-1] = data;
			//find the total size
		}
		c++;
	}

	//ensure data is taken in correctly
	cout << "Here is the array of data taken in:" << endl;
	for (int i = 0; i < size; i++){
		if (i != size - 1){
			cout << input[i] << ", ";
		}
		else{
			cout << input[i] << endl;
		}
	}
	//input is output correctly

	//create array to store the values of the array
	

	//run the algorithm to find the length of the longest subsequence
	int possibleLength[size];//create array to hold longest subsequence lengths
	for (int b = 0; b < size; b++){
		//set all values to 0
		possibleLength[b] = 0;
	}
	int tmp = input[0];//create a variable for the first posisition, and to move through the algorithm
	for (int n = 0; n < size; n++){
		//create array to hold current lis 
		//I am including pseudoClode for part b, since i don't have enought time
		//create a vector of vectors, one vector for each n, from 1-size
		//the length of each vector is the ammount of iterations of time the if
		//statement is done
		//
		//
		for (int j = n; j < size; j++){
			if (tmp < input[j]){//we have another element
				tmp = input[j];
				possibleLength[n] = possibleLength[n] + 1;
			//
			//
			//in this, append(input[j]) to the vector
			//
			//
			
			
			}
			else if (input[j] <= tmp){
				//do nothing, this element isn't in the array
			}
			else{
			}
		}
	}
	//we have all sizes for the input array determined. now we need to find the max
	int max = possibleLength[0];
	//find the max
	for (int a = 0; a < size; a++){
	//go through all the possible lengths
		cout << max << endl;
		if (max < possibleLength[a]){
			max = possibleLength[a];
			//if at the last element, for part b,
			//find the vector[a]
			//that is the vector that will contain all necessary elements

		}
	}
	//we now have our maximum
	cout << "the maximum size for the Longest Increasing Subsequence problem is: " << endl;
	cout << max << endl;

}

