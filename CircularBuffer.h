#pragma once

#include <exception>
namespace cmpsc122 {

	template <class T>
	class CircularBuffer {
	public:
		CircularBuffer(int capacity) {
			data = new T[capacity];
			this->capacity = capacity;
			indexNextIn = indexNextOut = 0;
			mCount = 0;
		}
		~CircularBuffer(void) { delete[] data; }

		inline void enqueue(T datum) {
			if (indexNextIn < capacity - 1)
				data[indexNextIn++] = datum;
			else {
				data[indexNextIn] = datum;
				indexNextIn = 0;
			}
			mCount++;
		}

		inline T dequeue() {
			if (empty())
				throw exception("Buffer is empty - cannot dequeue!");
			mCount--;
			if (indexNextOut < capacity - 1)
				return data[indexNextOut++];
			else {
				T datum = data[indexNextOut];
				indexNextOut = 0;
				return datum;
			}
		}

		inline int count () const { return mCount; }
		inline bool empty () const { return mCount == 0; }
		inline bool full () const { return mCount == capacity; }

	private:
		T* data;
		int capacity;
		int indexNextIn, indexNextOut;
		int mCount;
	};

}