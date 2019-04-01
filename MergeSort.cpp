//============================================================================
// Name        : MergeSort.cpp
// Author      : Pengrui
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

void merge(vector<int>& lst,int start,int end,int len){

	int tmp1[end-start+1];
	int tmp2[len-end];
	for(int i=0;i<end-start+1;i++)
		tmp1[i] = lst[start+i];
	for(int i=0;i<len-end;i++){
		tmp2[i] = lst[end+1+i];
	}

	int i = 0;
	int j = 0;
	int k;
	for(k=start;i<end-start+1 && j<len-end;k++){
		if(tmp1[i] < tmp2[j]){
			lst[k] = tmp1[i];
			i++;
		}else{
			lst[k] = tmp2[j];
			j++;
		}
	}
	if(i<end-start+1)
		for(int h=i;h<end-start+1;h++){
			lst[k] = tmp1[h];
			k++;

		}

	if(j<len-end)
		for(int h=j;h<len-end;h++){
			lst[k] = tmp2[h];

			k++;
		}

}

void Msort(vector<int>& lst,int start,int end){
	if(start!=end){
		int mid = (start+end)/2;
		Msort(lst,start,mid);
		Msort(lst,mid+1,end);
		merge(lst,start,mid,end);
	}
}

//
int main() {
	vector<int> lst;
	int len = 10;
	srand((unsigned)time(NULL));
	for(int i=0;i<len;i++){
		lst.push_back(rand()%1000);
		cout<<lst[i]<<" ";
	}


	Msort(lst,0,lst.size()-1);

	cout<<endl;
	for(int v:lst)
		cout<<v<<" ";

	return 0;
}
