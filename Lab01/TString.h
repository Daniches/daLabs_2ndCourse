#ifndef TSTRING
#define TSTRING

#include <iostream>

const int DEFAULT_STRING_SIZE = 8;
const char BREAK_CODE = 26;

bool isAllowedNumber(char c);

class TString {
public:
	TString();
	TString(int);
	~TString();
	void ReserveDouble();
	void ReserveHalf();
	void PushBack(const char);
	void Input(int);
	bool Input();
	bool InputMD5();
	void Swap(int, int);
	void Change(int, char);
	void Delete(int);
	void Print();
	char Show(int);
	void Information();
	int Size();
private:
	char *string_;
	int size_;
	int sizeReserved_;
};

#endif // !TSTRING