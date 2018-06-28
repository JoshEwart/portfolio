#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
using namespace std;

int main(){
	string letterList  = "abcdefghijklmnopqrstuvwxyz";
	int number;
	string letter;
	map<string, int> alphabet;
	for(int i=0;i<26;i++){
		letter = letterList[i];
		number = i;
		alphabet.insert(pair<string, int> (letter, number));
		cout << letter << ", " << number << endl;
	}
	letter = letterList[0];
//	cout<< "map[0]=" << alphabet[0]<<endl;
	cout<< "map[a]=" << alphabet[letter]<<endl;
	for(int i=0;i<26;i++){
		letter = letterList[i];
		cout<< letter;
	//	letter = letterList[number];
		cout<<", " << alphabet[letter];
	}
}
