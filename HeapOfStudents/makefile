theheaper: HeapAddress.o HeapDate.o HeapStudentClass.o main.o
	g++ HeapAddress.o HeapDate.o HeapStudentClass.o main.o -o theheaper
HeapAddress.o: HeapAddress.cpp HeapAddress.h
	g++ -c HeapAddress.cpp
HeapDate.o: HeapDate.cpp HeapDate.h
	g++ -c HeapDate.cpp
HeapStudentClass.o: HeapStudentClass.cpp HeapStudentClass.h
	g++ -c HeapStudentClass.cpp
main.o: main.cpp HeapStudentClass.h
	g++ -c main.cpp
clean:
		rm -f *.o
		rm theheaper