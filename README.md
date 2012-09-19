CSCI 333 -- Fall 2012
Project 1 -- Queue Implementations
==================================
Due date: Wednesday, September 26, 2012 at 11:55PM

For this project, you will implement an integer Queue API in 3 ways: (1) using a Linked List, (2) using an STL vector, and (3) using a raw array. You will also write timing tests to see which implementations are faster in practice.

The Queue API consists of 3 methods, so each implementation should include these, and only these in its public API (you are encouraged to use private methods):

- dequeue: remove the element from the front of the queue
- enqueue: add an element to the back of the queue
- size: returns the number of elements in the queue
- isEmpty: returns true if the queue is empty

The array implementation is the hardest, and should be done using the ring buffer approach as shown in class. If the queue reaches its maximum capacity and an enqueue operation is performed, a new array should be created that is twice the size and the contents should be copied to the new array. If the queue is smaller than half of its capacity (but not below its initial capacity), then a new array should be created that is half the size and the contents should be copied to the new array.

You should write several unit tests for each of the methods in the entire public API, and you should use assertions liberally throughout your code (in both public and private methods). Your unit tests for the public API can be re-used for each of the implementations, but you’ll need a Make target to build the tests with each of the implementations.

Speaking of makefiles, the root directory of your project should have the following subdirectories::

- build -- this is where the makefile will put the final executable timing test
- src -- this is your source code and your compiled object files
- lib -- this is where you’ll store third-party code (like the google c++ testing framework)
- test -- this is where you’ll include your unit tests

Your src directory should contain 4 subdirectories: AQueue, LQueue, and VQueue. Each should contain an associated header file (with appropriate header guards) and an implementation file. Your test file will have a single Queue.cpp test file that contains unit tests which test the public API for a queue.

The root directory, the src directory, and the test directory should have makefiles. If I type ‘make’ in your root directory, everything should be built including the google testing suite. The root directory makefile should make use of the makefiles in the subdirectories. You may use the in-class stack example as a model (and re-use any code/makefiles you find there).

I’ll post some timing test examples to get you started in the in-class stack example.

You may use any code examples from class, your textbook, and any sites linked from moodle. You may e-mail me or stop by with questions. You may talk to other students in broad terms about implementation details, but you may not copy code. You may not use any other resources for this project.