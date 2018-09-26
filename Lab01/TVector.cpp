#ifndef TVECTOR
#define TVECTOR

#include <iostream>



const int DEFAULT_ARRAY_SIZE = 4;

template <typename arrType>
class TVector {

public:

	//Constructor without arguments
	TVector() {
		array_ = new arrType[DEFAULT_ARRAY_SIZE];
		sizeReserved_ = DEFAULT_ARRAY_SIZE;

		size_ = 0;

	}

	//Constructor with specified size
	TVector(unsigned long long sizeSpecified) {
		array_ = new arrType[DEFAULT_ARRAY_SIZE];
		sizeReserved_ = DEFAULT_ARRAY_SIZE;

		while (sizeReserved_ < sizeSpecified) {
			ReserveDouble();
		}

		size_ = sizeSpecified;
	}

	//Constructor with specified size and elements
	TVector(unsigned long long sizeSpecified, arrType element) {
		array_ = new arrType[DEFAULT_ARRAY_SIZE];
		sizeReserved_ = DEFAULT_ARRAY_SIZE;

		while (sizeReserved_ < sizeSpecified) {
			ReserveDouble();
		}

		size_ = sizeSpecified;

		for (int i = 0; i < size_; i++) {
			array_[i] = element;
		}
	}

	//Destructor
	~TVector() {
		std::cout << "hi there";
		delete[] array_;
	}

	void ReserveDouble() {
		arrType *newArray = array_;
		array_ = new arrType[sizeReserved_ * 2];

		for (int i = 0; i < size_; i++) {
			array_[i] = newArray[i];
		}

		delete[] newArray;
		sizeReserved_ *= 2;
	}


	void ReserveHalf() {
		if (sizeReserved_ > DEFAULT_ARRAY_SIZE && size_ <= sizeReserved_ / 2) {
			arrType *newArray = array_;
			array_ = new arrType[sizeReserved_ / 2];

			for (int i = 0; i < size_; i++) {
				array_[i] = newArray[i];
			}


			delete[] newArray;
			sizeReserved_ /= 2;
		}
	}

	void PushBack(const arrType pushedValue) {
		if (size_ == sizeReserved_) {
			ReserveDouble();
		}
		array_[size_] = pushedValue;
		size_++;
	}

	void Swap(int first, int second) {
		arrType tmp = array_[first];
		array_[first] = array_[second];
		array_[second] = array_[first];
	}

	void Change(int position, arrType value) {
		array_[position] = value;
	}

	void Delete(int position) {
		for (int i = position; i < size_ - 1; i++) {
			array_[i] = array_[i + 1];
		}
		size_--;
		if (size_ <= sizeReserved_ / 2) {
			ReserveHalf();
		}
	}

	void Print() {
		for (int i = 0; i < size_; i++) {
			std::cout << array_[i] << std::endl;
		}
	}

	arrType Show(int position) {
		return array_[position];
	}

	void Information() {
		std::cout << "Size: " << size_ << ", reserved: " << sizeReserved_ << std::endl;
	}

	int Size() {
		return size_;
	}


private:
	arrType *array_;
	int size_;
	int sizeReserved_;
};

#endif // !TVECTOR