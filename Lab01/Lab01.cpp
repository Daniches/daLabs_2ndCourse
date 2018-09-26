#include "TVector.cpp"
#include "TString.cpp"
#include <iostream>

int main() {
	//TVector <int> wow(0);

	//TVector <char> str(0);
	
	TString str;
	TString str2;

	str.Input(1);
	str.Print();

	str2.Input(1);
	str2.Print();

	TVector <TString> wuf(0);
	wuf.PushBack(str);
	wuf.PushBack(str2);

	
}