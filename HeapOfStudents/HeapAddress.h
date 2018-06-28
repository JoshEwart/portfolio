//Address header
#ifndef HEAPADDRESS_H_EXISTS
#define HEAPADDRESS_H_EXISTS

#include <iostream>
#include <string>
using namespace std;

class HeapAddress{
	private:
		string line1;
		string line2;
		string city;
		string state;
		string zip;
	public:
		//can't forget that constructor;
		HeapAddress();


		// set/get information from Address input
		void setLine1(string line1);
		string getLine1();

		void setLine2(string line2);
		string getLine2();

		void setCity(string city);
		string getCity();
		
		void setState(string state);
		string getState();

		void setZip(string zip);
		string getZip();
		string printAddreses();
		//~HeapAddress();
};

#endif //HEAPADDRESS_H
