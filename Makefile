BUILD = ./build
TEST = ./test
LIB = ./lib
SRC = ./src
GTEST = $(LIB)/gtest-1.6.0
GTEST_MAINA = $(GTEST)/make/gtest_main.a
GTEST_INCLUDES = -I$(GTEST) -I$(GTEST)/include

QTEST = $(TEST)/queue_test.o
AQUEUE = $(SRC)/AQueue/AQueue.o
LQUEUE = $(SRC)/LQueue/LQueue.o
VQUEUE = $(SRC)/VQueue/VQueue.o

CPP = g++
CPPFLAGS = -Wall -Wextra


all: aqueue_test lqueue_test vqueue_test

aqueue_test: $(QTEST) $(AQUEUE) $(GTEST_MAINA) 
	$(CPP) $(CPPFLAGS) $(GTEST_MAINA) $(AQUEUE) $(QTEST) \
			-pthread -o $(BUILD)/aqueue_test

lqueue_test: $(QTEST) $(LQUEUE) $(GTEST_MAINA) 
	$(CPP) $(CPPFLAGS) $(GTEST_MAINA) $(LQUEUE) $(QTEST) \
			-pthread -o $(BUILD)/lqueue_test

vqueue_test: $(QTEST) $(VQUEUE) $(GTEST_MAINA) 
	$(CPP) $(CPPFLAGS) $(GTEST_MAINA) $(VQUEUE) $(QTEST) \
			-pthread -o $(BUILD)/vqueue_test


$(QTEST): $(TEST)/queue_test.cpp
	cd $(TEST) && $(MAKE) queue_test

$(AQUEUE): $(SRC)/AQueue/AQueue.cpp
	cd $(SRC)/AQueue && $(MAKE)

$(LQUEUE): $(SRC)/LQueue/LQueue.cpp
	cd $(SRC)/LQueue && $(MAKE)

$(VQUEUE): $(SRC)/VQueue/VQueue.cpp
	cd $(SRC)/VQueue && $(MAKE)

$(GTEST_MAINA): $(GTEST)/src/*.cc $(GTEST)/src/*.h
	cd $(GTEST)/make && $(MAKE)


clean:
	$(MAKE) -C $(SRC)/AQueue clean
	$(MAKE) -C $(SRC)/LQueue clean
	$(MAKE) -C $(SRC)/VQueue clean
	$(MAKE) -C $(TEST) clean
	rm -rf $(BUILD)/*queue_test
