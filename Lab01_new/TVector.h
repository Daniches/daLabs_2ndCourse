#ifndef TVECTOR
#define TVECTOR

#include <iostream>
#include "TString.h"

const int DEFAULT_VECTOR_SIZE = 16;
const int VECTOR_GROW = 2;

struct data {
	TString *key;
	TString *value;
};


class TVector {
public:
	TVector();
	TVector(int);
	bool ReserveDouble();
	bool PushBack(const data);
	data& operator[](int);
	int Size();
	~TVector();
private:
	data *array_;
	int size_;
	int sizeReserved_;
};

#endif // !TVECTOR