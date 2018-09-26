#ifndef TVECTOR
#define TVECTOR

#include <iostream>
#include "TString2.cpp"

struct data {
	TString key;
	TString value;
};

const int DEFAULT_VECTOR_SIZE = 4;

class TVector {

public:

	//Constructor without arguments
	TVector() {
		array_ = new data[DEFAULT_VECTOR_SIZE];
		sizeReserved_ = DEFAULT_VECTOR_SIZE;

		size_ = 0;

	}

	//Destructor
	~TVector() {
		//std::cout << "hi there";
		delete[] array_;
	}

	void ReserveDouble() {
		data *newArray = array_;
		array_ = new data[sizeReserved_ * 2];

		for (int i = 0; i < size_; i++) {
			array_[i] = newArray[i];
		}

		delete[] newArray;
		sizeReserved_ *= 2;
	}

	void PushBack(const data pushedValue) {
		if (size_ == sizeReserved_) {
			ReserveDouble();
		}
		array_[size_] = pushedValue;
		size_++;
	}

	void Swap(int first, int second) {
		data tmp = array_[first];
		array_[first] = array_[second];
		array_[second] = array_[first];
	}

	void Change(int position, data value) {
		array_[position] = value;
	}

	void Print() {
		for (int i = 0; i < size_; i++) {
			array_[i].key.Print();
			std::cout << ' ';
			array_[i].value.Print();
			std::cout << std::endl;
		}
	}

	data Show(int position) {
		return array_[position];
	}

	void Information() {
		std::cout << "Size: " << size_ << ", reserved: " << sizeReserved_ << std::endl;
	}

	int Size() {
		return size_;
	}


private:
	data *array_;
	int size_;
	int sizeReserved_;
};

#endif // !TVECTOR