//============================================================================
// Name        : QuickSelect.cpp
// Author      : Pengrui
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int partition(vector<int> &lst,int start,int end){
	int tmp = lst[start];
	while(start<end){
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

int quickSelect(vector<int> &lst,int start,int end,int target){
	if(start<end){
		int p = partition(lst,start,end);

		if(p<target)
			return quickSelect(lst,p+1,end,target);
		else if(p>target)
			return quickSelect(lst,start,p-1,target);
		else{
			return lst[p];
		}

	}
	return lst[start];
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
	int v = quickSelect(lst,0,lst.size()-1,5);
	for(int i=0;i<len;i++){
		cout<<lst[i]<<" ";
	}
	cout<<endl;
	cout<<"第4大的数为："<<v;
	return 0;
}
