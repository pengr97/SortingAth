//============================================================================
// Name        : CountingSort.cpp
// Author      : Pengrui
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int main() {
	vector<int> lst;
	int len = 10;
	srand((unsigned)time(NULL));
	for(int i=0;i<len;i++){
		lst.push_back(rand()%100);
		cout<<lst.back()<<" ";
	}
	cout<<endl;
	int max = 0;
	for(int v:lst)
		if(v>max)
			max = v;
	vector<int> l2(max+1,0);

	for(int v:lst)
		l2[v]+=1;

	for(int i=1;i<max+1;i++){
		l2[i] = l2[i] + l2[i-1];
	}

	int res[len] = {0};

	for(int v:lst){
		res[l2[v]-1] = v;
		l2[v]-=1;
	}
	for(int v:res)
		cout<<v<<" ";

	return 0;
}
