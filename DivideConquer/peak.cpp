#include <iostream>
#include <fstream>

using namespace std;

int peakAlgorithm(int data[], int head, int tail){

	//we have the array of data. now we need to discover the peak

	//create three variables to work as placeholders for this algorithm.

	//1-the head
	int h = head;

	//3-the tail
	int t= tail;

	//2-the midpoint
	int m = (h + t)/2;
	
	int peakPosition = m;
	//give back the position of the peak value

	//we now have the data, and must compare our current h,t, and m

	//if left of peak....
	//if one position left of midpoint is < midpoint, and one posisition right of midpoint > midpoint
	if(data[m-1] < data[m] && data[m+1] > data[m]){
		//set a new left side
		h = m-1;
		//we have our data, now recursively call the function
		peakAlgorithm(data, h, t);

	//if right of peak....
	//if one position left of midpoint is > midpoint, and one posisition right of midpoint is < midpoint
	}else if(data[m-1] > data[m] && data[m]>data[m+1]){
		//then set a new right side
		t = m+1;
		//we have our new data, now recursively call the funciton
		peakAlgorithm(data, h, t);
	
	//if at peak
	//if one posisition left of midpoint is < midpoint, and one posisition right of midpoint is < midpoint
	}else if(data[m-1] < data[m] && data[m+1] < data[m]){
		//then the current m = peak
		//we need to set our return value as the current peak posisition
		peakPosition = m;
		//give back the position of the peak value	
		return peakPosition;
	}else{
		cout << "something went out" << endl;
	}

}

int main(){
	int dataArray[30] = {};
	int arraySize = 0;
	//read in file
	ifstream infile("peak.txt");
	int data;
	while(infile >> data){
		//set each line to a position in the array
		dataArray[arraySize] = data;
		//find the total size
		arraySize++;
	}
	//ensure data is taken in correctly
	cout << "Here is the array of data taken in:" << endl;
	for(int i=0; i<arraySize; i++){
		cout << dataArray[i] << ", ";
	}
	cout << endl;
	
	//run the algorithm recursively
	int peakPosition = peakAlgorithm(dataArray, 0, arraySize);
	cout << "The posisition for the peak is: " << peakPosition << endl;
	cout << "The value of the posisition is: " << dataArray[peakPosition] << endl;
}


