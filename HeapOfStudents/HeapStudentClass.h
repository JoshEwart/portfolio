//studentClass header
#ifndef HEAPSTUDENTCLASS_H_EXISTS
#define HEAPSTUDENTCLASS_H_EXISTS

#include <iostream>
#include <string>
#include "HeapAddress.h"
#include "HeapDate.h"
using namespace std;

class HeapStudentClass{
	private:
		HeapAddress address;
		HeapDate birth;
		HeapDate grad;
		string name1;
		string name2;
		string gpa;
		string credith;
	public:
		HeapStudentClass();
		void dataSet(string data);


		string getName1();
		void setName1(string name1);
		string getName2();
		void setName2(string name2);
		string getGpa();
		void setGpa(string name2);
		string getCredith();
		void setCredith(string credith);

		void printSimple();
		void printRecord();
		//~HeapStudentClass();
};
#endif //HEAPSTUDENTCLASS_H