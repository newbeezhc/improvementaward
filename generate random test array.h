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
	 template<typename T>
         bool isSorted(T arr[], int n) {
        //判断是否排好了
        for (int i = 0; i < n - 1; i++)
            if (arr[i] > arr[i + 1])
                return false;

        return true;
    }

    	template<typename T>
	void testSort(const string &sortName, void (*sort)(T[], int), T arr[], int n) {
      //函数指针求时间
      	  clock_t startTime = clock();
     	   sort(arr, n);
      	  clock_t endTime = clock();

      	  assert(isSorted(arr, n));//拍好的情况下
     	   cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

      	  return;
    }

}


template<typename T>
void selectionSort(T arr[], int n){

    for(int i = 0 ; i < n ; i ++){

        int minIndex = i;
        for( int j = i + 1 ; j < n ; j ++ )
            if( arr[j] < arr[minIndex] )
                minIndex = j;

        swap( arr[i] , arr[minIndex] );
    }
}



int main()
{
	int n = 10000;
	int* arr = randomtest::generaterandomarray(n,0,n);
	//do sth
	randomtest::testSort("Selection Sort", selectionSort, arr, n);
	delete[] arr;//因为有new，防止内存泄漏
	
	
	return 0;
}


