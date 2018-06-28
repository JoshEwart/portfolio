#include <sstream>
#include <iostream>
using namespace std;
//create an abstract data type to house our Queue
class Queue {
	private:
		//create elements to access only inside the class
		//create the array size
		int size;
		//create the Queue size
		int rear;
		//create a pointer to represent 
		//our Queue/array until we can define it
		int *queueArray;
	public:
		//create methods to use for the program
		//create a method to define the Queue array's size
		int setSize(int length){
			//set the size,
      		size = length;
      		//tell the user the size was set
      		cout << "size: ";
			cout << length << endl;
    	}
    	//this constructor is run when the Queue ADT is created
		Queue(){
			//create the Queue by setting the Array's size
			queueArray = new int [size];
			//our Queue still is empty...
			rear = 0;
		}
		//we need to delete the Queue when we're done!
		~Queue(){
			//delete the Queue
			delete [] queueArray;
			//this happens automatically after we are out of the ADT's scope (main)
		}
		void enqueue(int element){
			//method to add an element to the end of the array
			//as long as we aren't at the end of the Array..
			if(rear != size){
				//we start at 0, not 1, so rear is 1 larger than we need, so set the element, then add to the size
				queueArray[rear] = element;
				rear ++;
				//now tell the user of the updated Queue
				cout << element;
				cout << " added to Queue." << endl;
				cout << "Queue size now is: ";
				cout << rear << endl;

			}else{
				//if the rear is the same as the max size, the Queue is full!
				cout << "Error: could not add:";
				cout << element << endl;
				cout << "Reason: Queue is full!" << endl;
			}

		}
		void dequeue(){
			//verify that queue has elements to remove
			if(rear > 0){
				//method to remove an element from the begining of the array
				//update the user what we are removing.. the head
				cout << "Removing: ";
				cout << queueArray[0];
				cout << " from head of Queue." << endl;
				//now we need to physically remove the FIRST ELEMENT of the Queue
				//to remove this, we must replace it.. with the next element..
				//and continue to do this until we get to the rear, when we 
				//decrease 'rear' and have the Queue size decreased
				for(int i = 0; i < rear; i++){
					queueArray[i] = queueArray[i+1];
				}
				//now explain to the user that we successfully removed the element,
				// and update the size of Queue
				cout << "First element of Queue Removed, now Queue size is: ";
				rear--;
				cout << rear << endl;
			}else{
				cout << "Queue is empty, no more elements to dequeue" << endl;
			}
		}
		void printQueue(){
			//this is to simply print out what the current Queue is, by going
			//through each element of the array until we reach the rear, and
			//print out each element seperated by a comma (as long as we aren't at the end)
			cout << "The Queue is: " << endl;
			for (int i = 0; i < rear; i++){
				if(i < rear-1){
					cout<< queueArray[i];
					cout << ", ";
				}else{
					cout << queueArray[i] << endl;
				}
			}
		}
};

int main(){
	//get the size of the Queue from the user
	cout << "How large do you want the queue to be?" << endl;
	//first create an instance of our Queue, and change the size of the array
	Queue queue;
	int length;
	cin >> length;
	//update the size
	queue.setSize(length);
	//we now have an array, we need to add elements
	
	//ask the user how many elements we need to add
	cout << "How many numbers would you like to add to the Queue?" << endl;
	int iterations;
	cin >> iterations;
	int element;
	//now for the number of ITERATIONS we will add ELEMENTS to the queue's array...
	//IF  the ITERATIONS < LENGTH.... if not, the enqueue method handles what's next..
	for(int i = 0; i < iterations; i++){
		cout << "Put in the number to add to the queue." << endl;
		cin >> element;
		//add our new element to the rear of the queue
		queue.enqueue(element);
	}
	//show the user what they have created
	queue.printQueue();
	//we can't keep this thing forever, now we need to remove some stuff..
	cout << "Now we need to remove elements. How many elements would you like to remove?" << endl;
	cin >> iterations;
	//we'll delete as many heads of the queue as there are ITERATIONS, unless the Queue is empty..
	//yep, that's also handled by dequeue
	for(int i = 0; i < iterations; i++){
		//we only remove elements from the front, not specific elements,
		//so no need for an "ELEMENT" here...
		queue.dequeue();
	}
	//show the user what is left over...
	queue.printQueue();
	//tell the user the Queue will be deleted.. (it will)
	cout << "Now we will delete the Queue, and end the program." << endl;
	//queue is deleted with termination of use, thus after main terminates, so does 'queue'
	return 0;
}