#include <iostream>
#include "TVector.h"

TVector::TVector() {
	array_ = new data[DEFAULT_VECTOR_SIZE];
	size_ = 0;
	sizeReserved_ = DEFAULT_VECTOR_SIZE;

	if (array_ == NULL) {
		std::cout << " Memory error";
		sizeReserved_ = 0;
	}
}

TVector::TVector(int given_size) {
	int new_size = DEFAULT_VECTOR_SIZE;
	while (new_size < given_size) {
		new_size *= 2;
	}
	array_ = new data[new_size];
	sizeReserved_ = new_size;
	size_ = given_size;
	if (array_ == NULL) {
		std::cout << " Memory error";
		sizeReserved_ = 0;
	}
}


bool TVector::ReserveDouble() {
	data *new_array = new data[sizeReserved_*VECTOR_GROW];
	if (new_array == NULL) {
		std::cout << " Memory error";
		return false;
	}
	
	for (int i = 0; i < size_; i++) {
		new_array[i] = array_[i];
	}

	data* old_array = array_;
	array_ = new_array;
	delete[] old_array;
	sizeReserved_ *= 2;

	return true;
}

bool TVector::PushBack(const data val) {
	if (size_ == sizeReserved_) {
		if (!ReserveDouble()) {
			return false;
		}
	}
		
	array_[size_] = val;
	size_++;
	return true;
}

int TVector::Size() {
	return size_;
}

data& TVector::operator[](int index) {
	return array_[index];
}

TVector::~TVector() {
	delete[] array_;
}