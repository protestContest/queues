BUILD = ./build
TEST = ./test
LIB = ./lib
SRC = ./src
GTEST = $(LIB)/gtest-1.6.0
GTEST_MAINA = $(GTEST)/make/gtest_main.a
GTEST_INCLUDES = -I$(GTEST) -I$(GTEST)/include

QTEST = $(TEST)/queue_test.o
TIME = $(SRC)/time/time.o

CPP = g++
CPPFLAGS = -Wall -Wextra


all: tests time


tests: aqueue_test lqueue_test vqueue_test

time: aqueue_time lqueue_time vqueue_time

aqueue_test: aqueue $(QTEST) $(GTEST_MAINA)
	$(CPP) $(CPPFLAGS) $(GTEST_MAINA) $(QTEST) $(SRC)/Queue.o \
			-pthread -o $(BUILD)/aqueue_test

vqueue_test: vqueue $(QTEST) $(GTEST_MAINA)
	$(CPP) $(CPPFLAGS) $(GTEST_MAINA) $(QTEST) $(SRC)/Queue.o \
			-pthread -o $(BUILD)/vqueue_test

lqueue_test: lqueue $(QTEST) $(GTEST_MAINA)
	$(CPP) $(CPPFLAGS) $(GTEST_MAINA) $(QTEST) $(SRC)/Queue.o $(SRC)/Node.o \
			-pthread -o $(BUILD)/lqueue_test


aqueue_time: aqueue $(TIME)
	$(CPP) $(CPPFLAGS) $(SRC)/Queue.o $(TIME) -o $(BUILD)/aqueue_time

vqueue_time: vqueue $(TIME)
	$(CPP) $(CPPFLAGS) $(SRC)/Queue.o $(TIME) -o $(BUILD)/vqueue_time

lqueue_time: lqueue $(TIME)
	$(CPP) $(CPPFLAGS) $(SRC)/Queue.o $(SRC)/Node.o $(TIME) -o $(BUILD)/lqueue_time


$(QTEST): $(TEST)/queue_test.cpp
	cd $(TEST) && $(MAKE) queue_test

$(TIME): $(SRC)/time/time.cpp
	cd $(SRC)/time && $(MAKE)

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
	rm -rf $(BUILD)/*
	rm -rf $(SRC)/*.o
	rm -rf $(SRC)/*.h
