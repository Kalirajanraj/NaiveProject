#pragma once
#include<iostream>
class NaiveVector
{
	int* m_data;
	int m_size;
	int m_lastFilledIndex;
public:
	NaiveVector() {
		m_size = 1;
		m_lastFilledIndex = -1;
		m_data = new int[m_size];
	}
	void PushBack(int value) {
		if (m_lastFilledIndex >= m_size-1)
		{
			m_size *= 2;
			auto temp = m_data;
			m_data = new int[m_size];
			for (int i = 0; i <= m_lastFilledIndex; i++)
			{
				m_data[i] = temp[i];
			}
			delete temp;
		}
		m_lastFilledIndex++;
		m_data[m_lastFilledIndex] = value;
	}
	void Print()
	{
		for (int i = 0; i <= m_lastFilledIndex; i++)
		{
			std::cout << m_data[i] << std::endl;
		}
	}
	~NaiveVector()
	{
		delete[] m_data;
	}
};