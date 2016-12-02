all: prog

prog: main.o MyString.o
	g++ main.o MyString.o -o prog

MyString.o: MyString.cpp MyString.h
	g++ -c MyString.cpp

main.o: main.cpp MyString.h MyAVL2.h MyAVLNode.h MyQueue.h MyList.h
	g++ -c main.cpp 

clean:
	rm -f  *.o prog 
