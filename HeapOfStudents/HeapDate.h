//Date header
#ifndef HEAPDATE_H_EXISTS
#define HEAPDATE_H_EXISTS
#include <iostream>
#include <string>
using namespace std;

class HeapDate{
	private:
		string day;
		string month;
		string year;
	public:
		//constructor
		HeapDate();


		void dateChange(string date);
		//make general set/get for data
		void setDay(string day);
		string getDay();

		void setMonth(string month);
		string getMonth();
		
		void setYear(string year);
		string getYear();
		
		string printDate();
		//~HeapDate();
};

#endif //HEAPDATE_H