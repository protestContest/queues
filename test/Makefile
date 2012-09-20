BUILD = ../build
TEST = ../test
LIB = ../lib
SRC = ../src
GTEST = $(LIB)/gtest-1.6.0
GTEST_MAINA = $(GTEST)/make/gtest_main.a
GTEST_INCLUDES = -I$(GTEST) -I$(GTEST)/include
INCLUDES = $(GTEST_INCLUDES) -I$(SRC)

CPP = g++
CPPFLAGS = -Wall -Wextra

queue_test: queue_test.cpp 
	$(CPP) $(CPPFLAGS) $(INCLUDES) -c queue_test.cpp

$(GTEST_MAINA): $(GTEST)/src/*.cc $(GTEST)/src/*.h
	cd $(GTEST)/make && $(MAKE)

clean:
	rm -rf queue_test.o
