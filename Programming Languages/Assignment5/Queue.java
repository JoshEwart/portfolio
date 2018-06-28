import java.util.*;
//create our java Abstract Data Type to house our Queue and the remaing members of the program
public class Queue {
	//create an array we can access in this class, as well as the size of the array
	//create the rear to represent the last element of the Queue
	private int[] queueArray;
	private int size;
	private int rear;
		
	private Queue(int length){
		//the size of the array is length, but we need size to be length+1
		//to ensure that we are inside the array bounds when dequeue executes
		size = length +1;
		//when the class is created, we need to create the Queue.
		//the queue is represented my max size defined by user is length
		queueArray = new int[size];
		
		//we have not added elements to the queue yet, so the rear remains at 0
		rear = 0;
	}
	private void enqueue(int element){
		//add 'element' to the end of the Queue- at the 'rear'.
		if(rear != size){
			//since the rear isn't the last position of the array, we can continue

			//the rear isn't the last element of the Queue.....
			//(we start at 0, not 1, so rear is 1 larger than we need)
			queueArray[rear] = element;
			//the size of our Queue has increased, so the rear needs to update
			rear++;
			//inform the user we have successfully added an element
			System.out.print(element);
			System.out.print(" added to Queue.");
			System.out.println("Queue size now is: ");
			System.out.println(rear);
		}else{
			//if we are trying to add an element when the rear is already at the max Size,
			//we can't continue
			System.out.print("Error could not add: ");
			System.out.println(element);
			System.out.println("Reason: Queue is full!");
		}
	}
	public void dequeue(){
		//verify that the Queue is not empty
		if(rear>0){
			//tell the user we are removing an element, since we can
			System.out.print("Removing: ");
			System.out.print(queueArray[0]);
			System.out.print(" from head of Queue.");
			//now we need to physically remove the FIRST ELEMENT of the Queue
			//to remove this, we must replace it.. with the next element..
			//and continue to do this until we get to the rear, when we 
			//decrease 'rear' and have the Queue size decreased
			for(int i=0;i<rear; i++){
				//have the current element equal to the next
				//this works when queueArray[rear-1] = queuearray[rear]
				//when rear=size because the array is actually an element larger
				//and queueArray[rear] is actually 0, which should be the new rear.
				queueArray[i] = queueArray[i+1];
			}
			System.out.print("Element Removed, now Queue size is: ");
			//decrease the size of our Queue..
			rear--;
			System.out.println(rear);
		}else{
			//if the rear is 0, the Queue is empty!
			System.out.println("Queue is empty, no more elements to dequeue.");
		}
	}
	private void printQueue(){
		//this is to simply print out what the current Queue is, by going
		//through each element of the array until we reach the rear, and
		//print out each element seperated by a comma (as long as we aren't at the end)
		System.out.println("The Queue is: ");
		for(int i=0;i<rear; i++){
			if(i<rear-1){
				System.out.print(queueArray[i]);
				System.out.print(", ");
			}else{
				System.out.print(queueArray[i]);
			}
		}
	}

	public static void main(String[] args){
		//first determine the size of the Queue from the user
		Scanner input = new Scanner(System.in);
		System.out.println("How large do you want the queue to be?");
		int length = input.nextInt();
		//set the size of the Queue
		Queue queue = new Queue(length);
		//now we need to determine how many times we will enqueue
		System.out.println("How many numbers would you like to add to the Queue?");
		int iterations = input.nextInt();
		int element;
		//perform enqueue and ask for number to add until finished all iterations
		for(int i=0;i<iterations;i++){
			System.out.println("Put in the number to add to the Queue.");
			element = input.nextInt();
			queue.enqueue(element);
		}
		//show user current Queue
		queue.printQueue();
		//now we need to remove elements, ask user for ammount to remove
		System.out.println();
		System.out.println("How many numbers would you like to remove from the Queue?");
		iterations = input.nextInt();
		//remove elements from the queue until finished all iterations
		for(int i=0;i<iterations;i++){
			queue.dequeue();
		}
		//print the Queue again to show the user the current Queue.
		queue.printQueue();
		System.out.println("");
		System.out.println("Now we will delete the Queue, and end the program.");
	}
};
