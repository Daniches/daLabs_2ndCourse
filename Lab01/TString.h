#ifndef TSTRING
#define TSTRING

#include <iostream>

const int DEFAULT_STRING_SIZE = 32;
const char BREAK_CODE = 26;
const int MD5SUM_DIGITS = 32;
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
	void Change(int, char);
	void Delete(int);
	void Print();
	char Show(int);
	int Size();
private:
	char *string_;
	int size_;
	int sizeReserved_;
};

#endif // !TSTRING