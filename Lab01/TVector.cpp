#include <iostream>
#include "TString.h"
#include "TVector.h"

TVector::TVector() {
	try {
		array_ = new data[DEFAULT_VECTOR_SIZE];
		sizeReserved_ = DEFAULT_VECTOR_SIZE;

		size_ = 0;
	}

	catch (...) {
		std::cout << "ERROR: Cannot create vector due to lack of memory.";
		exit(0);
	}
}

TVector::TVector(int sizeSpecified) {
	try { 
		array_ = new data[DEFAULT_VECTOR_SIZE];
		sizeReserved_ = DEFAULT_VECTOR_SIZE;

		while (sizeReserved_ < sizeSpecified) {
			ReserveDouble();
		}
		size_ = sizeSpecified;

		for (int i = 0; i < sizeSpecified; i++) {
			data e;
			Change(i, e);
		}
	}
	catch (...) {
		std::cout << "ERROR: Cannot create vector due to lack of memory.";
		exit(0);
	}
}

TVector::~TVector() {
	delete[] array_;
}

void TVector::ReserveDouble() {
	try {
		data *newArray = array_;
		array_ = new data[sizeReserved_ * 2];

		for (int i = 0; i < size_; i++) {
			array_[i] = newArray[i];
		}

		delete[] newArray;
		sizeReserved_ *= 2;
	}
	catch (...) {
		std::cout << "ERROR: Cannot resize vector due to lack of memory.";
		exit(0);
	}
}

void TVector::PushBack(const data pushedValue) {
	if (size_ == sizeReserved_) {
		ReserveDouble();
	}
	array_[size_] = pushedValue;
	size_++;
}

void TVector::Swap(int first, int second) {
	data tmp = array_[first];
	array_[first] = array_[second];
	array_[second] = tmp;
}

void TVector::Change(int position, data value) {
	array_[position] = value;
}

void TVector::Print() {
	for (int i = 0; i < size_; i++) {
		array_[i].key.Print();
		std::cout << ' ';
		array_[i].value.Print();
		std::cout << '\n';
	}
}

data TVector::Show(int position) {
	return array_[position];
}

void TVector::Information() {
	std::cout << "Size: " << size_ << ", reserved: " << sizeReserved_ << '\n';
}

int TVector::Size() {
	return size_;
}
