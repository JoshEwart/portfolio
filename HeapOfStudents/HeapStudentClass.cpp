//studentClass.cpp
#include <iostream>
#include <sstream>
#include <string>
#include "HeapStudentClass.h"
using namespace std;

//student contstructor
HeapStudentClass::HeapStudentClass(){
	HeapStudentClass::name1 = "Ewart";
	HeapStudentClass::name2 = "Josh";
	HeapStudentClass::gpa = "3.25";
	HeapStudentClass::credith = "27";		
};
void HeapStudentClass::dataSet(string data){
	stringstream ss(data);
	string element;
	int i = 0;
	string info[11];
	while(getline(ss, element, ',')){
		info[i] = element;
		i++;
	}
	HeapStudentClass::setName1(info[0]);
	HeapStudentClass::setName2(info[1]);
	address.setLine1(info[2]);
	address.setLine2(info[3]);
	address.setCity(info[4]);
	address.setState(info[5]);
	address.setZip(info[6]);
	birth.dateChange(info[7]);
	grad.dateChange(info[8]);
	HeapStudentClass::setGpa(info[9]);
	HeapStudentClass::setCredith(info[10]);
};
string HeapStudentClass::getName1(){
	return name1;
};
void HeapStudentClass::setName1(string name1){
	HeapStudentClass::name1 = name1;
};

string HeapStudentClass::getName2(){
	return name2;
};
void HeapStudentClass::setName2(string name2){
	HeapStudentClass::name2 = name2;
};

string HeapStudentClass::getGpa(){
	return gpa;
};

void HeapStudentClass::setGpa(string gpa){
	HeapStudentClass::gpa = gpa;
};
string HeapStudentClass::getCredith(){
	return credith;
};
void HeapStudentClass::setCredith(string credith){
	HeapStudentClass::credith = credith;
};


void HeapStudentClass::printRecord(){
	cout<<""<<endl;
	cout<<"FirstName: " + getName2()<<endl;
	cout<<"LastName: " +getName1()<<endl;
	cout <<"Address: " <<address.printAddreses() <<endl;
	cout<<"Birth Date: "<<birth.printDate()<<endl;
	cout<<"Graduation Date: " + grad.printDate()<<endl;
	cout <<"GPA: " + getGpa()<<endl;
	cout<<"Credit hours: " + getCredith()<<endl;
	cout<<""<<endl;
};

void HeapStudentClass::printSimple(){
	cout <<"First Name: " + getName2()<<endl;
	cout <<"Last Name: " + getName1()<<endl;
};
//HeapStudentClass::~HeapStudentClass(){

//};