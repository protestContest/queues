BUILD = ./build
TEST = ./test
LIB = ./lib
SRC = ./src
GTEST = $(LIB)/gtest-1.6.0
GTEST_MAINA = $(GTEST)/make/gtest_main.a
GTEST_INCLUDES = -I$(GTEST) -I$(GTEST)/include

QTEST = $(TEST)/queue_test.o
AQUEUE = $(SRC)/AQueue/Queue.o
LQUEUE = $(SRC)/LQueue/Queue.o
VQUEUE = $(SRC)/VQueue/Queue.o

CPP = g++
CPPFLAGS = -Wall -Wextra


all: lqueue_test 

aqueue_test: aqueue $(QTEST) $(GTEST_MAINA)
	$(CPP) $(CPPFLAGS) $(GTEST_MAINA) $(QTEST) $(SRC)/Queue.o \
			-pthread -o $(BUILD)/aqueue_test

vqueue_test: vqueue $(QTEST) $(GTEST_MAINA)
	$(CPP) $(CPPFLAGS) $(GTEST_MAINA) $(QTEST) $(SRC)/Queue.o \
			-pthread -o $(BUILD)/vqueue_test

lqueue_test: lqueue $(QTEST) $(GTEST_MAINA)
	$(CPP) $(CPPFLAGS) $(GTEST_MAINA) $(QTEST) $(SRC)/Queue.o $(SRC)/Node.o \
			-pthread -o $(BUILD)/lqueue_test


$(QTEST): $(TEST)/queue_test.cpp
	cd $(TEST) && $(MAKE) queue_test

aqueue: $(SRC)/AQueue/AQueue.cpp
	cd $(SRC)/AQueue && $(MAKE)
	cp $(SRC)/AQueue/AQueue.h $(SRC)/Queue.h

lqueue: $(SRC)/LQueue/LQueue.cpp $(SRC)/LQueue/Node.cpp
	cd $(SRC)/LQueue && $(MAKE)
	cp $(SRC)/LQueue/LQueue.h $(SRC)/Queue.h
	cp $(SRC)/LQueue/Node.h $(SRC)/Node.h

vqueue: $(SRC)/VQueue/VQueue.cpp
	cd $(SRC)/VQueue && $(MAKE)
	cp $(SRC)/VQueue/VQueue.h $(SRC)/Queue.h

$(GTEST_MAINA): $(GTEST)/src/*.cc $(GTEST)/src/*.h
	cd $(GTEST)/make && $(MAKE)


clean:
	$(MAKE) -C $(SRC)/AQueue clean
	$(MAKE) -C $(SRC)/LQueue clean
	$(MAKE) -C $(SRC)/VQueue clean
	$(MAKE) -C $(TEST) clean
	rm -rf $(BUILD)/*queue_test
	rm -rf $(SRC)/*.o
	rm -rf $(SRC)/*.h
