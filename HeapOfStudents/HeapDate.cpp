//HeapDate.cpp
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "HeapDate.h"
using namespace std;

//HeapDate constructor
HeapDate::HeapDate(){
	HeapDate::day = "1";
	HeapDate::month = "1";
	HeapDate::year = "2000";
};
void HeapDate::dateChange(string date){
	stringstream ss;
	ss << date;
	string element;
	int i = 0;
	string datInfo[3];
	while(getline(ss, element, '/')){
		datInfo[i] = element;
		i++;
	};
	HeapDate::setMonth(datInfo[0]);
	HeapDate::setDay(datInfo[1]);
	HeapDate::setYear(datInfo[2]);


};
//day functions
void HeapDate::setDay(string day){
	HeapDate::day = day;
}// end setday

string HeapDate::getDay(){
	return day;
}//end getday

//month functions
void HeapDate::setMonth(string month){
	HeapDate::month = month;
}//end setmonth

string HeapDate::getMonth(){
	return month;
}//end getmonth

//year functions
void HeapDate::setYear(string year){
	HeapDate::year = year;
}//end setyear

string HeapDate::getYear(){
	return year;
}//end getyear

string HeapDate::printDate(){
	return month + " " + day + ", " + year;
};
//HeapDate::~HeapDate(){

//};
