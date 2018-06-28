#include <sstream>
#include <iostream>
#include <math.h>

using namespace std;

class changeMaker{
	//create the methods for our three programs- int, float, and double
	public:
		void changeInt(float cost, float paid);
		void changeFloat(float cost, float paid);
		void changeDouble(float cost, float paid);
};


//method1
void changeMaker::changeInt(float cost, float paid){
	float leftovers = paid - cost;
	if(leftovers < 0){ 
		cout << "You didn't pay enough." << endl;
	}else{
		int change = leftovers * 100;
			while(change > 0){
				//we now have our int for how much change there is
				cout << "Your Change Returned: " << endl;
					
				int dollars = change/100;
				cout << dollars;
				cout << "- Dollars, "<< endl;
					
				int temp = dollars * 100;
				change = change - temp;
					
				int quarters = change/25;
				cout << quarters;
				cout << "- Quarters, "<< endl;	
				temp = quarters * 25;
				change = change - temp;
					
				int dimes = change/10;
				cout << dimes;
				cout << "- Dimes, " << endl;
				
				temp = dimes * 10;
				change = change - temp;
					
				int nickels = change/5;
				cout << nickels;
				cout << "- Nickels, "<< endl;	
					
				temp = nickels * 5;
				change = change - temp;
					
				int pennies = change;
				cout << pennies;
				cout << "- Pennies " << endl;
					
				change = change - pennies;
		}
	}
}


//method2
void changeMaker::changeFloat(float cost, float paid){
	float change = paid - cost;
	if(change < 0){ 
		cout << "You didn't pay enough." << endl;
	}else{
		while(change > 0){
			//we now have our int for how much change there is
			
			float dollars = floor(change);
			change = change - dollars;
			
			float quarters = change * 4;
			quarters = floor(quarters);
			float temp = quarters/4;
			change = change - temp;
			
			float dimes = change * 10;
			dimes = floor(dimes);
			temp = dimes / 10;
			change = change - temp;
			
			float nickels = change * 20;
			nickels = floor(nickels);
			temp = nickels /20;
			change = change - temp;
			
			float pennies = change * 100;
			pennies = ceil(pennies);
			
			cout << "Your Change Returned: " << endl;
			cout << dollars;
			cout << "- Dollars, "<< endl;
			cout << quarters;
			cout << "- Quarters, "<< endl;
			cout << dimes;
			cout << "- Dimes, "<< endl;
			cout << nickels;
			cout << "- Nickels, "<< endl;
			cout << pennies;
			cout << "- Pennies" << endl; 
			change = change - change;
			
		}
	}
}

///method3
void changeMaker::changeDouble(float cost, float paid){
	float change = paid - cost;
	//we now have our int for how much change there is

	if( change < 0){ 
		cout << "You didn't pay enough." << endl;
	}else{
		while(change > 0){
			double dollars = floor(change);
			float temp = dollars;
			change = change - dollars;
			
			cout << change << endl;
			
			double quarters = change * 4;
			quarters = floor(quarters);
			temp = quarters/4;
			change = change - temp;
			
			double dimes = change * 10;
			dimes = floor(dimes);
			temp = dimes/10;
			change = change - temp;
			
			double nickels = change * 20;
			nickels = floor(nickels);
			temp = nickels/20;
			change = change - temp;
			double pennies = change * 100;
			pennies = ceil(pennies);
			
			cout << "Your change is: " << endl;
			cout << dollars;
			cout << "- Dollars, " << endl;
			cout << quarters;
			cout << "- Quarters, " << endl;
			cout << dimes;
			cout << "- Dimes, "<< endl;
			cout << nickels;
			cout << "- Nickels, " << endl;
			cout << pennies;
			cout << "- Pennies " << endl;
			change = change - change;
		}
	}
}

int main(){
	//create an instance of our class
	changeMaker moneyCalc;

	//get information from user

	float cost;
	float paid;
	cout << "Please put in the total cost of your purchase: $" << endl;
	cin >> cost;
	cout << "How much are you going to pay for? $" << endl;
	cin >> paid;

	//ask user for program type:
	cout << "Are you using: Integers(1), Floats(2), or Doubles(3)?"<< endl;
	int dataType;
	cin >> dataType;
	//datatype now has what version of data we are using, now let's work on that method
	if(dataType == 1){
		//int data
		moneyCalc.changeInt(cost, paid);
	}else if(dataType == 2){
		moneyCalc.changeFloat(cost, paid);
	}else if(dataType == 3){
			moneyCalc.changeDouble(cost, paid);
	}
}