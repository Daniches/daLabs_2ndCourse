#ifndef TSTRING
#define TSTRING

#include <iostream>

const int DEFAULT_STRING_SIZE = 16;
const char BREAK_CODE = 26;
const int STRING_GROW = 2;

class TString {
public:
	TString();
	bool ReserveDouble();
	bool PushBack(const char);
	int Size();
	void Print();
	~TString();
private:
	char *string_;
	int size_;
	int sizeReserved_;
};

#endif // !TSTRING
