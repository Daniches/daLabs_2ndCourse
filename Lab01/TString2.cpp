#ifndef TSTRING
#define TSTRING

#include <iostream>

const int DEFAULT_STRING_SIZE = 8;

class TString {

public:

	//Constructor without arguments
	TString() {
		string_ = new char[DEFAULT_STRING_SIZE];
		sizeReserved_ = DEFAULT_STRING_SIZE;

		size_ = 0;

	}

	//Constructor with specified size
	TString(int sizeSpecified) {
		string_ = new char[DEFAULT_STRING_SIZE];
		sizeReserved_ = DEFAULT_STRING_SIZE;

		while (sizeReserved_ < sizeSpecified) {
			ReserveDouble();
		}

		size_ = sizeSpecified;
	}

	//Destructor
	~TString() {
		//std::cout << "hi there";
		//delete[] string_;
	}

	void ReserveDouble() {
		char *newString = string_;
		string_ = new char[sizeReserved_ * 2];

		for (int i = 0; i < size_; i++) {
			string_[i] = newString[i];
		}

		delete[] newString;
		sizeReserved_ *= 2;
	}


	void ReserveHalf() {
		if (sizeReserved_ > DEFAULT_STRING_SIZE && size_ <= sizeReserved_ / 2) {
			char *newString = string_;
			string_ = new char[sizeReserved_ / 2];

			for (int i = 0; i < size_; i++) {
				string_[i] = newString[i];
			}


			delete[] newString;
			sizeReserved_ /= 2;
		}
	}

	void PushBack(const char pushedValue) {
		if (size_ == sizeReserved_) {
			ReserveDouble();
		}
		string_[size_] = pushedValue;
		size_++;
	}

	void Input(int size) {
		char c;
		for (int i = 0; i < size; i++) {
			std::cin >> c;
			PushBack(c);
		}
	}
	void Input() {
		char c;
		while (size_ < 1) {
			while (c = std::cin.get()) {
				if (c == '\t' || c == '\n' || c == ' ') {
					break;
				}
				PushBack(c);
			}
		}
	}

	void Swap(int first, int second) {
		char tmp = string_[first];
		string_[first] = string_[second];
		string_[second] = string_[first];
	}

	void Change(int position, char value) {
		string_[position] = value;
	}

	void Delete(int position) {
		for (int i = position; i < size_ - 1; i++) {
			string_[i] = string_[i + 1];
		}
		size_--;
		if (size_ <= sizeReserved_ / 2) {
			ReserveHalf();
		}
	}

	void Print() {
		for (int i = 0; i < size_; i++) {
			std::cout << string_[i];
		}
	}

	char Show(int position) {
		return string_[position];
	}

	void Information() {
		std::cout << "Size: " << size_ << ", reserved: " << sizeReserved_ << std::endl;
	}

	int Size() {
		return size_;
	}


private:
	char *string_;
	int size_;
	int sizeReserved_;
};

#endif // !TSTRING