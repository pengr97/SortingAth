//============================================================================
// Name        : RadixSort.cpp
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
		lst.push_back(rand()%1000);
		cout<<lst.back()<<" ";
	}
	cout<<endl;

	int max = 0;
	for(int v:lst)
		if(v>max)
			max = v;


	for(int i=1;max/i>0;i*=10){
		int tmp[len] = {0};
		int radix[10] = {0};	//加入桶排序（避免使用链表）
		for(int j=0;j<len;j++){
			int index = (lst[j]/i)%10;
			radix[index]+=1;
		}
		for(int j=1;j<10;j++){
			radix[j] = radix[j] + radix[j-1];
		}
		for(int j=len-1;j>=0;j--){
			int index = (lst[j]/i)%10;
			tmp[radix[index]-1] = lst[j];
			radix[index]--;
		}
		for(int j=0;j<len;j++){
			lst[j] = tmp[j];
		}

		//打印每一趟排序结果
		for(int v:lst)
			cout<<v<<" ";
		cout<<endl;
	}


	return 0;
}
