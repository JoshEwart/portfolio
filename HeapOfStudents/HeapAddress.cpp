//HeapAddress.cpp
#include <iostream>
#include <string>
#include "HeapAddress.h"
using namespace std;

//HeapAddress constructor
HeapAddress::HeapAddress(){
	HeapAddress:line1 = "Line1";
	HeapAddress::line2 = "Line2";
	HeapAddress::city = "city";
	HeapAddress::state = "state";
	HeapAddress::zip = "zipcode";
};

//get/set functions defined
void HeapAddress::setLine1(string line1){
	HeapAddress::line1 = line1;
}//end setline1

string HeapAddress::getLine1(){
	return line1;
}//end getline1

void HeapAddress::setLine2(string line2){
	HeapAddress::line2 = line2;
}//end setline2

string HeapAddress::getLine2(){
	return line2;
}//end getline2

void HeapAddress::setCity(string city){
	HeapAddress::city = city;
}//end set city

string HeapAddress::getCity(){
	return city;
}//end getcity

void HeapAddress::setState(string state){
	HeapAddress::state = state;
}//end state

string HeapAddress::getState(){
	return state;
}//end getstate

void HeapAddress::setZip(string zip){
	HeapAddress::zip = zip;
}//end setzip

string HeapAddress::getZip(){
	return zip;
}//end getzip

string HeapAddress::printAddreses(){
	return line1 + "," + line2 + '\n' + city + "," + state + "," + zip;
};
//HeapAddress::~HeapAddress(){

//};