//main.cpp
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "HeapStudentClass.h"
using namespace std;

void sort(string array[]);

int main(){
	//set student to the heap
	HeapStudentClass* scholar = new HeapStudentClass[50];
	//step1: read the file

	//to read the file, and convert the data
	ifstream inFile;
	inFile.open("data.txt");
	string element;
	int counter = 0;
	string Array[50];
	while (!inFile.eof()){
		getline(inFile, element);
		Array[counter] = element;
		counter++;
	}//and lo, behold, I am finished
	inFile.close();
	sort(Array);
	int count;
	for(count=0;count<50;count++){
		scholar[count].dataSet(Array[count]);
		//information ordered by: Surname,GivenName,
		//StreetAddress,Address 2,City,State,ZipCode
		//Birthday,Graduation,GPA,Credit Hours Complete
	}//and lo, behold, I am finished

	

	int i=0;
	cout<<"Welcome, I'm going to print out a file, when you press enter."<< endl;
	cout<<"press Enter to continue"<<endl;
	cin.ignore();


	cout<<"Print Name(Simple Print)"<<endl;
	for(i=0; i<50; i++){
		scholar[i].printSimple();
	}
	cout<<"Print the Record of each student"<<endl;
	for(i=0; i<50; i++){
		scholar[i].printRecord();
	}
	scholar[1].printRecord();
	delete[] scholar;

};
void sort(string array[]){
	int i,j;
	string temp;
	for(i=0; i<50; i++){
		for(j=0; j< 49; j++){
			if(array[j].compare(array[j+1]) > 0){
	        	temp = array[j];
	        	array[j] = array[j+1];
	        	array[j+1] = temp;
        	} // end if
		} //end for
	} //end otherfor
}//end sort


