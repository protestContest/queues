#include "../Queue.h"
#include <ctime>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main() {
	Queue* q = new Queue();
	int start, end, elapsed, iterations;
	double seconds;
	iterations = 10000;

	// Enqueue
	cout << "Average enqueue time: ";
	for (int i = 0; i < iterations; ++i) {
		start = clock();
		q->enqueue(i);
		end = clock();
		elapsed = end - start;
		seconds += (double) elapsed/CLOCKS_PER_SEC;
	}
	seconds /= iterations;

	cout << seconds << endl;

	// Dequeue
	seconds = 0;
	cout << "Average dequeue time: ";
	for (int i = 0; i < iterations; ++i) {
		start = clock();
		int x = q->dequeue();
		end = clock();
		elapsed = end - start;
		seconds += (double) elapsed/CLOCKS_PER_SEC;
	}
	seconds /= iterations;

	cout << seconds << endl;
	delete q;

	// Size
	q = new Queue();
	seconds = 0;
	cout << "Average size time: ";
	for (int i = 0; i < iterations; ++i) {
		q->enqueue(i);
		start = clock();
		q->size();
		end = clock();
		elapsed = end - start;
		seconds += (double) elapsed/CLOCKS_PER_SEC;
	}
	seconds /= iterations;

	cout << seconds << endl;
	delete q;

	// isEmpty
	q = new Queue();
	seconds = 0;
	cout << "Average isEmpty time: ";
	for (int i = 0; i < iterations; ++i) {
		q->enqueue(i);
		start = clock();
		q->isEmpty();
		end = clock();
		elapsed = end - start;
		seconds += (double) elapsed/CLOCKS_PER_SEC;
	}
	seconds /= iterations;

	cout << seconds << endl << endl;

	delete q;
}
