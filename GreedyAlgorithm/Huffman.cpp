#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct node{
	//pass in the data we already have
	string ascii;
	int freqency;
	//create the path in the tree to nodes below this node
	node *left;
	node *right;
	//construct the node
	node(string ascii, int freq){
		//initialize everything to zero
		left = right = NULL;
		//set the curent node's ascii and freqency values
		this->ascii = ascii;
		this->freqency = freqency;
	}//end constructor
};

void HuffmanTree(string ascii[], int frequency[], int n){
	//we have all our data. now we need to create nodes that are connected, to create our tree
	struct node *sum, *leftChild, *rightChild;
	//now that we have our initial data, create a vector to go through our data
	int size = n;
	vector<node*> data;
	for (int a = 0; a < size; n++){
		//add a new element to the data
		data.push_back(new node(ascii[a], frequency[a]));
		//i have discovered that my vector I created cannout access the node data,
		//and I am not sure of how to create a list of these nodes.
		//cout << data[0].ascii;
	}
	//we have everything in data, which we can go through each element, and then remove it now.
	//so now, go through all elements in data
	//also create a variable to iterate and
	//assign ascii data
	int current;
	while (data.size() != 1){
		//I am writing pseudocode, since mine does not correctly access its data
		//left = data.front
		//remove the data.front;
		//data.erase(data.front);
		//set right child node, which is now the top
		//right = data.front;
		//data.erase(data.front);

		//after this, the top needs set
		//top = new node('_', left->frequency + right -> frequency);
		//top->left = left;
		//top->right = right;
		//minHeap.push(top);
		//then I would need to print out the tree, which is minimal work
	}
}



int main(){
	int frequency[20] = {};
	string ascii[20] = {};
	int n = 0;
	//read in file
	ifstream infile("freq.txt");
	string data;
	//create tmp counter
	int counter = 0;
	int tmp = 0;
	while (infile >> data){
		//data is seperated into ascii, number, ascii, ect
		cout << tmp << endl;
		//we need to store all even in ascii
		if (tmp % 2 == 0){
			ascii[counter] = data;
			cout << data << ",asci " << counter << endl;
			counter++;
		}
		else{
			stringstream convert(data);
			convert >> frequency[counter-1];

			cout << data << ",freq " << counter-1 << endl;
		}
		tmp++;
	}
	//we have all the data. we need to arrange everything in increasing order.
	
	//simple insertion sort
	int tmpFreq;
	string tmpAscii;
	int i,j = 0;
	for (i = 1; i < counter; i++){
		//going through each element...
		//set "temp" to the current element
		tmpFreq = frequency[i];
		tmpAscii = ascii[i];
		//go through all elements before, and if less than current element, swap current element.
		for (j = i - 1; (j >= 0) && (tmpFreq<frequency[j]); j--){
			frequency[j + 1] = frequency[j];
			ascii[j + 1] = ascii[j];
		}
		frequency[j + 1] = tmpFreq;
		ascii[j + 1] = tmpAscii;

	}

	//create tree
	HuffmanTree(ascii, frequency, n);


	//ensure data is taken in correctly
	cout << "Here is the array of data taken in: "<< counter << endl;

	for (int z = 0; z<counter; z++){
		cout << frequency[z] << ", ";
	}
	cout << endl;
	for (int x = 0; x<counter; x++){
		cout << ascii[x] << ", ";
	}
	cout << endl;

	
}
