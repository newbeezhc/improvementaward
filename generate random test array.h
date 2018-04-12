#pragma once
#ifndef RANDOMTEST_H
#define RANDOMTEST_H

#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;

 namespace randomtest{
	 //生成n个元素随机数组，【rangel，ranger】
	int* generaterandomarray(int n,int rangel, int ranger)
	{
		assert(rangel<=ranger);
		int* arr=new int[n];
		srand(time(NULL));
		for(int i=0;i<n;i++)
			arr[i]=rand()%(ranger-rangel+1)+rangel;
		return arr;

	}

}
