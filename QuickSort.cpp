//============================================================================
// Name        : QuickSort.cpp
// Author      : Pengrui
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int parpition(vector<int> &lst,int start,int end){
	int tmp = lst[start];
	while(start<end){
		/*if(lst[end]<tmp){
			lst[start] = lst[end];
			lst[end] = tmp;
			start++;
		}else {
			end--;
			continue;
		}
		if(start==end)
			break;
		if(lst[start]>tmp){
			lst[end] = lst[start];
			lst[start] = tmp;
			end--;
		}
		else{
			start++;
		}*/
		while(start<end && lst[end]>=tmp)
			end--;
		lst[start] = lst[end];
		while(start<end && lst[start]<=tmp)
			start++;
		lst[end] = lst[start];
	}
	lst[start] = tmp;
	return start;
}

void quickSort(vector<int> &lst,int start,int end){

	if(start<end){
		int p = parpition(lst,start,end);
		quickSort(lst,start,p-1);
		quickSort(lst,p+1,end);
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
	quickSort(lst,0,lst.size()-1);
	for(int i=0;i<len;i++){
		cout<<lst[i]<<" ";
	}
	return 0;
}
