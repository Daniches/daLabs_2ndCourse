#include "TString2.cpp"
#include "TVector2.cpp"
#include <iostream>

int main() {
	//TVector <int> wow(0);

	//TVector <char> str(0);

	data e,e2;
	TVector lol;

	e.key.Input(4);
	e.value.Input(4);
	lol.PushBack(e);
	
	e2.key.Input(4);
	e2.value.Input(4);
	lol.PushBack(e2);


	lol.Show(0).key.Print();
	lol.Show(0).value.Print();
	lol.Show(1).key.Print();
	lol.Show(1).value.Print();

	
}