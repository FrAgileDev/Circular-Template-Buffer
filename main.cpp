#include <iostream>
#include "CircularBuffer.h"

using namespace std;
using namespace cmpsc122;

int main () {
	CircularBuffer<int> buffer(100);
	CircularBuffer<string> strings(10);

	string data[] = {"Fred", "Bob", "Jim"};

	for (int i = 0; i < 3; i++) {
		strings.enqueue(data[i]);
	}

	return 0;
}