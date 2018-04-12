#pragma once
#ifndef RANDOMTEST_H
#define RANDOMTEST_H

#include <iostream>
#include <ctime>//time函数
#include <cassert>//assert函数
using namespace std;

 namespace randomtest{
	 //生成n个元素随机数组，【rangel，ranger】
	int* generaterandomarray(int n,int rangel, int ranger)
	{
		assert(rangel<=ranger);//保证上下界
		int* arr=new int[n]; //要想到delete[]
		srand(time(NULL));
		for(int i=0;i<n;i++)
			arr[i]=rand()%(ranger-rangel+1)+rangel;
		return arr;

	}
	 template<typename T>
	 void printarray(T arr[], int n)
	 {
		 for(int i=0; i<n; i++)
			 cout<< arr[i] <<" ";
		 cout << endl;
		 
		 return;
	 }

}












int main()
{
	int n = 10000;
	int* arr = randomtest::generaterandomarray(n,0,n);
	//do sth
	randomtest::printarray(arr,n);
	delete[] arr;//因为有new，防止内存泄漏
	
	
	return 0;
}


