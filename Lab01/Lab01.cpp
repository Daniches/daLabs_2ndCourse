#include <iostream>
#include "TString.h"
#include "TVector.h"
const int MAX_NUMBER = 16;

int CharValue(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	if (c >= 'a' && c <= 'f') {
		return c - 'a' + 10;
	}
	if (c >= 'A' && c <= 'F') { 
		return c - 'A' + 10;
	}
	return 0;
}

void CountingSort(TVector& arr, int position) {

	TVector tmpArr(arr.Size());

	int count[MAX_NUMBER + 1];

	for (int i = 0; i <= MAX_NUMBER; i++) {
		count[i] = 0;
	}

	for (int i = 0; i < arr.Size(); i++) {
		count[CharValue(arr.Show(i).key.Show(position))]++;
	}

	for (int i = 1; i <= MAX_NUMBER; i++) {
		count[i] += count[i - 1];
	}

	for (int i = arr.Size() - 1; i >= 0; i--) {
		tmpArr.Change(--count[CharValue(arr.Show(i).key.Show(position))], arr.Show(i));
	}

	for (int i = 0; i < arr.Size(); i++) {
		arr.Change(i, tmpArr.Show(i));
	}


}

void RadixSort(TVector& arr) {
	for (int i = arr.Show(0).key.Size() - 1; i >= 0; i--) {
		CountingSort(arr, i);
	}

}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	TVector arrData;

	while(true) {
		data e;
		if (!e.key.InputMD5()) { 
			if (e.key.Size() > 0) {
				std::cout << "ERROR: Invalid input. Each string must contatin MD5Sum, TAB character and string.";
				exit(0);
			}
			else {
				break;
			}
		}
		if (!e.value.Input()) {
			arrData.PushBack(e);
			break;
		}
		arrData.PushBack(e);
	}

	RadixSort(arrData);

	for (int i = 0; i < arrData.Size(); i++) {
		arrData.Show(i).key.Print();
		std::cout << '\t';
		arrData.Show(i).value.Print();
		std::cout << '\n';
		
	}

}