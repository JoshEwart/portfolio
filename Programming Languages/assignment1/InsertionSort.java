//InsertionSort for Java by Joshua Ewart
import java.util.ArrayList;
import java.util.*;
//create class to contain project
public class InsertionSort {
	//create an array to sort the data
	public static ArrayList<Integer> data = new ArrayList<Integer>();
	//create a method to add in the elements
	public static void addData(int input){
		data.add(input);
	}
	//create method to run insertionsort
	public static void insertionSort(){
		//create variables for going through the data
		int temp, i, j;
		//go through each element of the array
		for(i=1;i<data.size();i++){
			//set temp variable 'j' to current position
			temp= data.get(i);
			//go through until reach the begining, and the too values are not equal
			for(j=i-1; j>=0 && temp<data.get(j); j--){
				//swap the variables of elements, if data[i] is less than than data[j]
				data.set(j+1, data.get(j));
			}
			//then set the next element back to temp
			data.set(j+1, temp);
		}
	}
	//create main method to run the program
	public static void main(String[] args){
		//add in the data
		Scanner input = new Scanner(System.in);
		System.out.println("Please enter in the number of elements");
		int length = input.nextInt();
		System.out.println("Please enter in each element, as an integer, followed by pressing 'enter'.");
		for(int i=0; i<length; i++){
			System.out.print("Please enter in element: ");
			System.out.println(i+1);
			int element = input.nextInt();
			addData(element);
		}
		//display unsorted data:
		System.out.println("Unsorted: ");
		//go through each element
		for(int i=0; i<length; i++){
			System.out.print(data.get(i));
			//create formatting
			if(i != 9){
				System.out.print(", ");
			}
		}
		System.out.println("");
		//run sorting algorithm method
		insertionSort();		
		//Print Sorted data
		System.out.print("Sorted: ");
		//itterate through each element of the array
		for(int i=0; i<10; i++){
			System.out.print(data.get(i));
			//create formatting for the output
			if(i != 9){
				System.out.print(", ");
			}	
		}
	}
}

