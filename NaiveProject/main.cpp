#include<iostream>
#include"NaiveVector.h"
int main()
{
	NaiveVector v;
	v.PushBack(5);
	v.PushBack(6);
	v.Print();
	std::getchar();
	return 0;
}