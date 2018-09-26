#include "TVector.cpp"
#include <iostream>


class TString {

public:
	TString() {
		//TVector <char> string_();
	}

	void Input(int length) {
		char c;
		for (int i = 0; i < length; i++) {
			
			char c;	
			std::cin >> c;

			string_.PushBack(c);
		}
	}
	void Print() {
		for (int i = 0; i < string_.Size(); i++) {
			std::cout << string_.Show(i);
		}
	}

	char Show(int position) {
		return string_.Show(position);
	}

	int Length() {
		return string_.Size();
	}

private:
	TVector <char> string_;
};

