//============================================================================
// Name        : HeapSort.cpp
// Author      : Pengrui
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

void HeapAdjust(vector<int> &lst,int start,int end){
	int tmp = lst[start];
	for(int i=start*2+1;i<=end;i=2*i+1){
		if(i<end && lst[i]<lst[i+1])
			i = i+1;
		if(tmp>=lst[i])
			break;
		else{
			lst[start] = lst[i];
			start = i;
		}

	}
	lst[start] = tmp;
}

void HeapSort(vector<int> &lst){
	for(int i=lst.size()/2;i>=0;i--){
		HeapAdjust(lst,i,lst.size()-1);

	}

	for(int i=lst.size()-1;i>0;i--){
		int tmp = lst[i];
		lst[i] = lst[0];
		lst[0] = tmp;
		HeapAdjust(lst,0,i-1);
	}
}

int main() {
	vector<int> lst;
	int len = 10;
	srand((unsigned)time(NULL));
	for(int i=0;i<len;i++){
		lst.push_back(rand()%100);
		cout<<lst.back()<<" ";
	}
	cout<<endl;
	HeapSort(lst);
	for(size_t i=0;i<lst.size();i++)
		cout<<lst[i]<<" ";
	return 0;
}
