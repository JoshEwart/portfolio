//Create A program to check spelling, asking user for words.
//Joshua Ewart, 11/7/15
//The first step is set up the to read in the file, and parsing the data first by words, then placing each word into the respective first, then second letter.
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
class hash2{
	//seperate the dictionary by the second letter, after the first.
	//create the dictionary
	vector<vector<string> > dictionary;
	//now to go through the dictionary
	map<string, int> hashmap;
	public:
		hash2();
		//how to access the vector
		void addWord(string term);
};
hash2::hash2(){
	string temp;
	for(int i=0; i <= 25; i++){
		temp = alphabet.at(i);
		dictionary.push_back(vector<string>());
		hashmap.insert(temp, i);
		cout << hashmap["temp"] << endl;
	}
hash2::addWord(string word, int key){
	//hash2::hashmap.insert(word.at(1), key);
	//
	hash2::dictionary[hashmap[word.at(1)]].pushback(word);
}
class hash1{
	//seperate dictionary terms by first letter
	map<string, hash2> locateLetter;
	public:
		hash1();
		void addword(string key);
};
hash1::hash1(){
	//string alphabet = "abcdefghijklmnopqrstuvwxyz";
	string temp;
	for(int i=0; i <= 25; i++){
		temp = alphabet.at(i);
		locateLetter.insert(temp, hash2());;
		cout << locateLetter["temp"] << endl;
	}
}
hash1::addword(string key){
		stringstream sstream;
		string letter;
		char temp = key[0];
		sstream << temp;
		sstream >> letter;
		locateLetter[letter].addword();
		//hash2().addword(key, temp2);
}
int main(){
	/* create empty hash tables
	hash2::hash2();
	hash1::hash1();
	*/
	cout<< "Please enter in the Dictionary"<<endl;
	ifstream file;
	file.open("Dictionary.txt");
	string word;
	//string alphabet = ""
	while(!file.eof()){
		getline(file, word);
		//we read in the file, now we need to store the file with hashing
		cout << word << ", ";
		//find numerical value of first and second letter
		//add word to proper hash1
		hash1::addword(word);
	}
	/*
	cout<< "Please enter in a word to check spelling"<< endl;
	string input;
	cin<< input <<endl;
	*/
}

