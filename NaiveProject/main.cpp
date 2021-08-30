#include<iostream>
#include<string>
#include"NaiveVector.h"
int main()
{
	{
		NaiveVector<int> v;
		for (int i = 0; i < 1000; i++)
		{
			v.PushBack(i);
		}
		v.Print();
	}
	std::getchar();
	return 0;
}