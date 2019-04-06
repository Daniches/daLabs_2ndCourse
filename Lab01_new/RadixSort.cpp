#include<iostream>
#include"TVector.h"
#include"TString.h"
#include"RadixSort.h"

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
 
void CountingSort(TVector& arr, int pos) {

	TVector tmpArr(arr.Size());

	int count[MAX_NUMBER + 1];

	for (int i = 0; i <= MAX_NUMBER; i++) {
		count[i] = 0;
	}

	for (int i = 0; i < arr.Size(); i++) {
		count[CharValue(arr[i].key->Element(pos))] ++;
	}

	for (int i = 1; i <= MAX_NUMBER; i++) {
		count[i] += count[i - 1];
	}

	for (int i = arr.Size() - 1; i >= 0; i--) {
		tmpArr[--count[CharValue(arr[i].key->Element(pos))]] = arr[i];
	}

	for (int i = 0; i < arr.Size(); i++) {
		arr[i] = tmpArr[i];
	}

}

void RadixSort(TVector& arr) {
	if (arr.Size()>1){
		for (int i = arr[0].key->Size() - 1; i >= 0; i--) {
			CountingSort(arr, i);
		}
	}
	
}