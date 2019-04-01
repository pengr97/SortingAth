//============================================================================
// Name        : ShellSort.cpp
// Author      : Pengrui
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

void shellSort(vector<int>& lst,int d){

	for(int i=0;i<(int)lst.size()-d;i++){
		if(lst[i+d]<lst[i]){
			int tmp = lst[i+d];
			int j;
			for(j=i;j>=0;j-=d){
				if(tmp<lst[j])
					lst[j+d] = lst[j];
				else
					break;
			}
			lst[j+d] = tmp;
		}
	}
}

int main() {
	vector<int> lst = {513, 636, 8, 920, 415, 686, 554, 507, 935, 473 };
	int len = 10;
	srand((unsigned)time(NULL));
	for(int i=0;i<len;i++){
		//lst.push_back(rand()%1000);
		cout<<lst[i]<<" ";
	}


	int incremental[6] = {11,9,7,5,2,1};
	for(int i=0;i<6;i++){
		shellSort(lst,incremental[i]);
	}

	cout<<endl;
	for(int v:lst)
		cout<<v<<" ";

	return 0;
}
