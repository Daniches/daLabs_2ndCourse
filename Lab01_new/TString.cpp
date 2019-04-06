#include <iostream>
#include "TString.h"

TString::TString() {
	string_ = new char[DEFAULT_STRING_SIZE];
	size_ = 0;
	sizeReserved_ = DEFAULT_STRING_SIZE;

	if (string_ == NULL) {
		std::cout << " Memory error";
		sizeReserved_ = 0;
	}
}

bool TString::ReserveDouble() {
	char *new_string = new char[sizeReserved_* STRING_GROW];
	if (new_string == NULL) {
		std::cout << " Memory error";
		return false;
	}

	for (int i = 0; i < size_; i++) {
		new_string[i] = string_[i];
	}

	char *old_string = string_;
	string_ = new_string;
	delete[] old_string;
	sizeReserved_ *= 2;

	return true;
}

bool TString::PushBack(const char c) {
	if (size_ == sizeReserved_) {
		if (!ReserveDouble()) {
			return false;
		}
	}
	string_[size_] = c;
	size_++;

	return true;
}

int TString::Size() {
	return size_;
}

void TString::Print() {
	for (int i = 0; i < size_; i++) {
		std::cout << string_[i];
	}
}

char TString::Element(int pos) {
	return string_[pos];
}

TString::~TString() {
	delete[] string_;
}