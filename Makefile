BUILD = ./build
TEST = ./test
LIB = ./lib
SRC = ./src
GTEST = $(LIB)/gtest-1.6.0
GTEST_MAINA = $(GTEST)/make/gtest_main.a
GTEST_INCLUDES = -I$(GTEST) -I$(GTEST)/include

OBJECTS = $(TEST)/queue_test.o $(SRC)/AQueue/AQueue.o \
		$(SRC)/LQueue/LQueue.o $(SRC)/VQueue/VQueue.o

QTEST = $(TEST)/queue_test.o
AQUEUE = $(SRC)/AQueue/AQueue.o
LQUEUE = $(SRC)/LQueue/LQueue.o
VQUEUE = $(SRC)/VQueue/VQueue.o

CPP = g++
CPPFLAGS = -Wall -Wextra

tests: $(OBJECTS) $(GTEST_MAINA)
	$(CPP) $(CPPFLAGS) $(OBJECTS) $(GTEST_MAINA) \
			-pthread -o $(BUILD)/queue_test


$(TEST)/queue_test.o: $(TEST)/queue_test.cpp
	cd $(TEST) && $(MAKE) queue_test

$(SRC)/AQueue/AQueue.o: $(SRC)/AQueue/AQueue.cpp
	cd $(SRC)/AQueue && $(MAKE)

$(SRC)/LQueue/LQueue.o: $(SRC)/LQueue/LQueue.cpp
	cd $(SRC)/LQueue && $(MAKE)

$(SRC)/VQueue/VQueue.o: $(SRC)/VQueue/VQueue.cpp
	cd $(SRC)/VQueue && $(MAKE)

$(GTEST_MAINA): $(GTEST)/src/*.cc $(GTEST)/src/*.h
	cd $(GTEST)/make && $(MAKE)


clean:
	$(MAKE) -C $(SRC)/AQueue clean
	$(MAKE) -C $(SRC)/LQueue clean
	$(MAKE) -C $(SRC)/VQueue clean
	$(MAKE) -C $(TEST) clean
	rm -rf $(BUILD)/*queue_test
