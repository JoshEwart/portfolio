//create a program to find the placement for n queens in an [n,n] board
//Joshua Ewart(jewart)
//Big O analysis:

//The first portion of the code that takes a significant portion of time is my initial while loop.
//This loop lasts until it has placed every queen, casuing big O to start off with n.
//The next portion of code that adds to the total complexity of the algorithm is the inner for loop.
//This for loop iterates three times for each iteration of a queen. (For each time the while loop runs, the for loop runs three times)
//This causes the complexity to become n(1+2+3+ect~ to the size of the array). The reason why my for loop, inside conflict, leads to that result, is because
//for each iteration of the while loop, the for loop goes through i from 0 to the length of the vector, or the stack.  This leads to the equation O(n!) because
//1+2+3+ect......+n is the total number of iterations for the last iteration of the while loop, however, there are also previous while iterations to consider, causing
// the complexity to be come (1+2+3+....n)(1+2+3+....(n-1)).....(1) which leads to (n)(n-1)(n-2)(n-3)...(1) which is equilivant to (n!)
#include <iostream>
#include <vector>
using namespace std;
//create a method to check if queens interfere with other queen moves.
int conflict(int size, vector<int>& stack, int check_queen){
	//create loop to iterate through each column so that as each row is passed,
	//a queen will be placed in each row
	//create length to record total rows with queens
	int length = stack.size();

	//create int to return;
	int correct = 1;
	int bounds = 2;
	for(int i =0; i < length; i++){
		//create values to represent the current location in regard to those on the stack.
		int Rdiagonal= stack[i] - check_queen;
		int Ldiagonal= -Rdiagonal;
		//for vertical(column) checks, if the value[column] at position equals
		//the value of check_queen, there's an interception.
		if (check_queen>=size){
			//out of bounds of column
			return bounds;
		}else if(stack[i] == check_queen){
			return correct;
		//if the difference in row == the difference in column
		}else if((length-i) == Rdiagonal){
			return correct;
		//if the difference in row == the negative counterpart
		}else if((length-i) == Ldiagonal){
			return correct;
		}
		//say no conflict, then
	}
	return 0;
}

int queen_place(int size){
	//create the vector to keep track of the stack by using the position as the row element,
	// thus only working one element at a time in each iteration of the following loop,
	//causing only a need for vertical) and diagonal checks.

	vector <int> stack;
	//initialize the first queen, and add her to the stack
	int start_queen =0;
	stack.push_back(start_queen);
	//create a variable to keep track of total queens.
	int filled = 1;
	//create variable to keep track of which column the algorithm is in (vector position will change for the row)
	int check_queen = 0;
	//create to end while loop
	bool keepgoing = true;
	while(keepgoing){
		//create a variable to represent any conflicts
		int problem = conflict(size, stack, check_queen);
		//check if there is no problem,
		//and then add another queen if so,
		//then when the number of queens is the proper amount, end while
		if(problem == 0){
			filled++;
			stack.push_back(check_queen);
			if(filled == size){
				keepgoing = false;
			//if not at the end,
			//start over by reseting the column[check_queen] and row [stack.push_back]
			}else{
				check_queen = 0;
			}//end inner if
		
			//if there is a conflict, and/or the column count is larger than the size,
			// then pop back the data.

		}else if(problem == 2){
			//"second end if " << endl;
			filled--;
			cout<<"Pop"<<"["<<(stack.size()-1)<<","<<stack.back()<<"]"<<endl;
			check_queen = stack.back();
			stack.pop_back();
			
			check_queen++;
			//stack.back() = check_queen;
		//if there is a problem, and the iterator is under the proper length,
		//add to the column[check_queen] to check next position
		}else if(problem == 1 && check_queen<size){
			check_queen++;
		
		}
	}
	//display the output on the stack
	cout<<"Output:"<<endl;
	for(int a=0; a<size;a++){
		cout<<"["<<a<<","<<stack[a]<<"]"<<endl;
	}
}

int main(){
	//need row, column, and number of queens,
	int size=0;
	//as the user for input
	cout<<"please put in a size greater than 3, unless you are looking for 1 or the rows and columns"<<endl;
	cin>>size;
	//calculate the organization
	queen_place(size);
}
