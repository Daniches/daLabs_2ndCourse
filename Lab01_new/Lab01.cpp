#include<iostream>
//#include<vld.h>
#include"TString.h"
#include"TVector.h"
#include"RadixSort.h"

int main() {
	TVector dataArray;

	char c;
	bool isMD5 = true;
	data pair;
	pair.key = new TString();
	pair.value = new TString();

	while(true){
		c = getchar();

		if (c == BREAK_CODE || c== EOF) {
			if (pair.key->Size() > 0) {
				dataArray.PushBack(pair);
			}
			else {
				delete pair.key;
				delete pair.value;
			}
			break;
		}
		if (c == '\t') {
			isMD5 = false;
			continue;
		}
		if (c == '\n') {
			if (pair.key->Size() > 0) {
				dataArray.PushBack(pair);

				pair.key = new TString();
				pair.value = new TString();
			}
			
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

	RadixSort(dataArray);

	for (int i = 0; i < dataArray.Size(); i++) {
		dataArray[i].key->Print();
		std::cout << '\t';
		dataArray[i].value->Print();
		std::cout << '\n';
	}

}