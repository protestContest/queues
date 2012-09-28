BUILD = ../../build
CPP = g++
CPPFLAGS = -Wall -Wextra
TEST = ../../test

LQueue.o: LQueue.h LQueue.cpp Node.o
	$(CPP) $(CPPFLAGS) -c LQueue.cpp -o ../Queue.o

Node.o: Node.h Node.cpp
	$(CPP) $(CPPFLAGS) -c Node.cpp -o ../Node.o

clean:
	rm -f *.o
	rm -f *~
