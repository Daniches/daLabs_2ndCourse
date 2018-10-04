#include <iostream>
#include "TString.h"

bool isAllowedNumber(char c) {
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A'&&c <= 'F')) {
		return true;
	}
	return false;
}
//Constructor without arguments
TString::TString() {
	try {
		string_ = new char[DEFAULT_STRING_SIZE];
		sizeReserved_ = DEFAULT_STRING_SIZE;

		size_ = 0;
	}
	catch (...) {
		std::cout << "ERROR: Cannot create string due to lack of memory.";
		exit(0);
	}

}

//Constructor with specified size
TString::TString(int sizeSpecified) {
	try {
		string_ = new char[DEFAULT_STRING_SIZE];
		sizeReserved_ = DEFAULT_STRING_SIZE;

		while (sizeReserved_ < sizeSpecified) {
			ReserveDouble();
		}

		size_ = sizeSpecified;
	}
	catch (...) {
		std::cout << "ERROR: Cannot create string due to lack of memory.";
		exit(0);
	}
}

//Destructor
TString::~TString() {
	//delete[] string_;
}

void TString::ReserveDouble() {
	try {
		char *newString = string_;
		string_ = new char[sizeReserved_ * 2];

		for (int i = 0; i < size_; i++) {
			string_[i] = newString[i];
		}

		delete[] newString;
		sizeReserved_ *= 2;
	}
	catch (...) {
		std::cout << "ERROR: Cannot resize string due to lack of memory.";
		exit(0);
	}
}


void TString::ReserveHalf() {
	try {
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
	catch (...) {
		std::cout << "ERROR: Cannot resize string due to lack of memory.";
		exit(0);
	}
}

void TString::PushBack(const char pushedValue) {
	if (size_ == sizeReserved_) {
		ReserveDouble();
	}
	string_[size_] = pushedValue;
	size_++;
}

void TString::Input(int size) {
	char c;
	for (int i = 0; i < size; i++) {
		std::cin >> c;
		if (!isAllowedNumber(c)) {
			std::cout << "ERROR: Invalid MD5Sum input. You can use only 0-9, a-f, A-F digits.";
			exit(0);
		}
		PushBack(c);
	}
}

bool TString::Input() {
	char c;
	while (size_ < 1) {
		while (true) {
			c = std::cin.get();
			if (c == EOF || c == BREAK_CODE) {
				return false;
			}
			if (c == '\t' || c == '\n' || c == ' ') {
				break;
			}

			PushBack(c);
		}
	}
	return true;
}

bool TString::InputMD5() {
	char c;
	while (size_ < 1) {
		while (true) {
			c = std::cin.get();
			if (c == EOF || c == BREAK_CODE) {
				return false;
			}
			if (c == '\t' || c == '\n' || c == ' ') {
				break;
			}
			if (!isAllowedNumber(c)) {
				std::cout << "ERROR: Invalid MD5Sum input. You can use only 0-9, a-f, A-F digits.";
				exit(0);
			}

			PushBack(c);
		}
	}
	
	if (size_!=32) {
		std::cout << "ERROR: Invalid MD5Sum input. It must have 32 digits.";
		exit(0);
	}
	
	return true;
}

void TString::Change(int position, char value) {
	string_[position] = value;
}

void TString::Delete(int position) {
	for (int i = position; i < size_ - 1; i++) {
		string_[i] = string_[i + 1];
	}
	size_--;
	if (size_ <= sizeReserved_ / 2) {
		ReserveHalf();
	}
}

void TString::Print() {
	for (int i = 0; i < size_; i++) {
		std::cout << string_[i];
	}
}

char TString::Show(int position) {
	return string_[position];
}

int TString::Size() {
	return size_;
}
