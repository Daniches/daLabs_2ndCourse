#ifndef TVECTOR
#define TVECTOR

#include <iostream>
#include "TString.h"
	
struct data {
	TString key;
	TString value;
};

const int DEFAULT_VECTOR_SIZE = 32;

class TVector {
public:
	TVector();
	TVector(int);
	~TVector();
	void ReserveDouble();
	void PushBack(const data);
	void Swap(int, int);
	void Change(int, data);
	void Print();
	data Show(int);
	void Information();
	int Size();
private:
	data *array_;
	int size_;
	int sizeReserved_;
};

#endif // !TVECTOR