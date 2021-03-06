#include <iostream>
#include "TVector.h"
#include "TString.h"
#include "RadixSort.h"



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

	int count[MAX_NUMBER+1];

	for (int i = 0; i <= MAX_NUMBER; i++) {
		count[i] = 0;
	}

	for (int i = 0; i < arr.Size(); i++) {
		count[arr.Show(i).key.Show(position)]++;
	}

	for (int i = 1; i <= MAX_NUMBER; i++) {
		count[i] += count[i - 1];
	}

	for (int i = arr.Size() - 1; i >= 0; i++) {
		tmpArr.Change(count[arr.Show(i).key.Show(position)] --, arr.Show(i));
	}

	for (int i = 0; i < arr.Size(); i++) {
		arr.Change(i, tmpArr.Show(i));
	}
	

}