#include<iostream>
#include"TString.h"
#include"TVector.h"
#include"RadixSort.h"

int main() {
	TVector lol;

	char c;
	bool isMD5 = true;
	data pair;
	pair.key = new TString();
	pair.value = new TString();

	while(true){
		c = getchar();

		if (c == BREAK_CODE || c== EOF) {
			if (pair.key->Size() > 0) {
				lol.PushBack(pair);
			}
			break;
		}
		if (c == '\t') {
			isMD5 = false;
			continue;
		}
		if (c == '\n') {
			if (pair.key->Size() > 0) {
				lol.PushBack(pair);
			}
			pair.key = new TString();
			pair.value = new TString();
			
			isMD5 = true;
			continue;
		}
		if (isMD5) {
			pair.key->PushBack(c);
		}
		else {
			pair.value->PushBack(c);
		}
	};

	RadixSort(lol);

	for (int i = 0; i < lol.Size(); i++) {
		lol[i].key->Print();
		std::cout << '\t';
		lol[i].value->Print();
		std::cout << '\n';
	}


}