README:



To run the Queue in C++, take Queue.cpp program file inside the .zip, and upload to pegasus. Log into pegasus, and go to the directory you uploaded the file. Once there, go to the directory where the file is saved, type in:

g++ Queue.cpp
This will create an "a.out" executable file by compiling the Queue. Run this by typing in:
./a.out


This will prompt you to determine the max size of the Queue. Enter in a size, such as 14, (any will do) and press enter.  You will then be prompted to provide how many elements (numbers) you want to add to this Queue.  Once you have put in that number as a numberic value, you will be prompted to add each element until you have either added every element, or you have tried to add an element to the Queue after it is full.  After this, the program will ask you how many elements you wish to remove from the Queue.  Then the program will remove elements from the head of the Queue until it finishes removing the number of elements you specified, or until the Queue is empty, which ever comes first. Once this happens, you wil be told what remains in the Queue. Then, as main terminates, the created Queue will be deleted.



To run the Queue in Java, take Queue.java program file inside the .zip, and upload to pegasus. Log into pegasus, and go to the directory you uploaded the file. Once there, go to the directory where the file is saved, type in:

javac Queue.java
This will create a "Queue.class" file by compiling the java file into a quickly interpritable .class fille, which can be ran using:
java Queue

This will prompt you to determine the max size of the Queue. Enter in a size, such as 14, (any will do) and press enter.  You will then be prompted to provide how many elements (numbers) you want to add to this Queue.  Once you have put in that number as a numberic value, you will be prompted to add each element until you have either added every element, or you have tried to add an element to the Queue after it is full.  After this, the program will ask you how many elements you wish to remove from the Queue.  Then the program will remove elements from the head of the Queue until it finishes removing the number of elements you specified, or until the Queue is empty, which ever comes first. Once this happens, you wil be told what remains in the Queue. Then, as main terminates, the created Queue will be deleted.

These two programs perform the same process, and provide (approximately) the same result. To best see how this impliments a Queue, I would suggest creating a small Queue, of 10 elements or less, and having each element increase in chronological order for each element you Enqueue. (i.e.- 1,2,3, ect~)