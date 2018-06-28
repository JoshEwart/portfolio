#include <iostream>
#include <fstream>

using namespace std;

void minWork(int i, int j, int kMatrix[8][8], int m[8]){
	int currentPosisition = kMatrix[i][j];//update our current posisition
	int length = j - i;
	if (currentPosisition == i && length > 1){
		cout << "[";
		cout << m[i - 1];
		cout << "*";
		cout << m[currentPosisition];
		cout << "]";
		//we have printed out what is being multiplied, now keepgoing
		minWork(currentPosisition + 1, j, kMatrix, m);
	}
	else if (currentPosisition != i && length > 1){//if not at given i, and there's more length left,

		if (currentPosisition + 1 == j){
			cout << "{";
			minWork(i, currentPosisition, kMatrix, m);//keepgoing, and print out
			cout << "(";
			cout <<m[currentPosisition] << "*";
			cout <<m[j];
			cout << ")";
			cout << "}";
		}
		else if (currentPosisition != i && length > 1){
			cout << "(";
			minWork(i, currentPosisition, kMatrix, m);//keepgoing, and print out
			cout << "*";
			minWork(currentPosisition+1, j, kMatrix, m);
			cout << ")";
		}
		
	}
	else{
		//print out
		cout << "[(";
		cout << m[i - 1];
		cout << "*";
		cout << m[currentPosisition];
		cout << ")(";
		cout << m[currentPosisition];
		cout << "*";
		cout << m[j];
		cout << ")]";
	}
}

int main(){
	//create data for all array rows and columns
	int m[] = { 10, 17, 12, 25, 14, 30, 15, 9};
	//create our 2d array to work with
	int matrix[8][8];
	int matrixRow = 8;
	int matrixColumn = 8;
	//we also need to create a way to keep track of k values. print it out in a matching matrix where the value of the posisition is the k that was lowest for that posisition
	int kMatrix[8][8];
 	//now that we have an array to work with, we need to fill it with data, say zeros for now.
	for (int a = 1; a < matrixRow; a++){
		for (int b = 1; b < matrixColumn; b++){
			matrix[a][b] = 0;
			kMatrix[a][b] = 0;
		}
	}
	//we have given everything an initial value, now we must go through and compute the value of the upper right triangle of Matrix
	//go through diagonal
	for (int d = 1; d <= matrixRow - 1; d++){
		for (int i = 1; i <= matrixRow - d; i++){
			int j = i + d;

			//we must find the minimum k, and set it's value to matrix(i, j)

			//we now have i and j, and must find all k,
			//such that i <= k < j
			//start by creating two arrays to hold one k and 
			//the other array to hold the M values
			int kMin;
			int kMinValue;
			int currentMValue;
			for (int k = i; k < j; k++){
				//start at the current value for i, end before j
				//evaluate current k value, and set them in kValue array
				currentMValue = matrix[i][k] + matrix[k + 1][j] + (m[i - 1]*m[k]*m[j]);
				//we now have our current Value that might be the value for the matrix. if it is less than the smallest Value,
				//or the first Value we have, set it to kMinValue, and set k to kMin.
				if (k == i){
					kMinValue = currentMValue;
					kMin = k;
				}
				else if (kMinValue >  currentMValue){
					//the value is smaller, and needs replaced
					kMinValue = currentMValue;
					kMin = k;
				}
				else{
					//something went Fishy, or kMinValue<currentMValue, and thus not a minimum
				}
			}
			//you have the k and the value, now set the posisition in the matrix the lowest
			matrix[i][j] = kMinValue;//we now have set the value
			kMatrix[i][j] = kMin;
		}
	}

//we now have the array. now output it
	for (int g = 1; g < matrixRow; g++){
		for (int h= 1; h < matrixColumn; h++){
			cout<< matrix[g][h] << "    ";
		}

		cout << endl;
	}
	cout << endl;
	cout << endl;
	cout << endl;
	for (int g = 1; g < matrixRow; g++){
		for (int h = 1; h < matrixColumn; h++){
			cout << kMatrix[g][h] << "    ";
		}

		cout << endl;
	}

	minWork(1, 7, kMatrix, m);
	cout << endl;
}

