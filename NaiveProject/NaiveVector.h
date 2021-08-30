#pragma once
#include<iostream>
#include<exception>

template<typename T>
class NaiveVector
{
	T* m_data;
	int m_size;
	int m_lastFilledIndex;
	void CopyData(T* dataToCopy) {
		for (int i = 0; i <= m_lastFilledIndex; i++)
		{
			m_data[i] = dataToCopy[i];
		}
	}
public:
	NaiveVector() : m_size{ 1 }, m_lastFilledIndex{ -1 }, m_data{ new T[m_size] }
	{}
	NaiveVector(T value){
		m_size = 1;
		m_lastFilledIndex = 0;
		m_data = new T[m_size];
		m_data[m_lastFilledIndex] = value;
	}
	NaiveVector(std::initializer_list<T> list){
		m_size = list.size();
		m_lastFilledIndex = list.size() - 1;
		m_data = new T[m_size];
		for (auto iter = list.begin(); iter != list.end(); iter++)
			m_data[iter - list.begin()] = *iter;
	}
	NaiveVector(const NaiveVector& source){
		m_size = source.m_size;
		m_data = new T[m_size];
		m_lastFilledIndex = source.m_lastFilledIndex;
		CopyData(source.m_data);
	}
	NaiveVector& operator=(const NaiveVector& source) {
		delete[] m_data;
		m_size = source.m_size;
		m_data = new T[m_size];
		m_lastFilledIndex = source.m_lastFilledIndex;
		CopyData(source.m_data);
		return *this;
	}
	NaiveVector(NaiveVector&& v){
		m_size = v.m_size;
		m_data = v.m_data;
		m_lastFilledIndex = v.m_lastFilledIndex;
		v.m_size = 0;
		v.m_data = nullptr;
		v.m_lastFilledIndex = -1;
	}
	NaiveVector& operator=(NaiveVector&& v){
		m_size = v.m_size;
		m_data = v.m_data;
		m_lastFilledIndex = v.m_lastFilledIndex;
		v.m_size = 0;
		v.m_data = nullptr;
		v.m_lastFilledIndex = -1;
		return *this;
	}
	void PushBack(T value) {
		if (m_lastFilledIndex >= m_size-1)
		{
			m_size *= 2;
			auto temp = m_data;
			m_data = new T[m_size];
			CopyData(temp);
			delete[] temp;
		}
		m_lastFilledIndex++;
		m_data[m_lastFilledIndex] = value;
	}
	void Print() const {
		for (int i = 0; i <= m_lastFilledIndex; i++)
		{
			std::cout << m_data[i] << std::endl;
		}
	}
	T operator[](T index) {
		try {
			if (index > m_lastFilledIndex)
				throw std::exception("Invalid access");
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
			throw e;
		}
		return m_data[index];
	}
	NaiveVector operator++() = delete;
	NaiveVector operator++(int) = delete;
	NaiveVector operator--() = delete;
	NaiveVector operator--(int) = delete;
	NaiveVector& operator+=(NaiveVector&) = delete;
	NaiveVector& operator-=(NaiveVector&) = delete;
	NaiveVector& operator*=(NaiveVector&) = delete;
	NaiveVector& operator/=(NaiveVector&) = delete;
	NaiveVector& operator%=(NaiveVector&) = delete;

	bool operator==(NaiveVector& rhs) {
		if (m_size != rhs.m_size || m_lastFilledIndex != rhs.m_lastFilledIndex)
			return false;
		for (int i = 0; i < m_size; i++)
		{
			if (m_data[i] != rhs.m_data[i])
				return false;
		}
		return true;
	}
	bool operator!=(NaiveVector& rhs) {
		if (m_size != rhs.m_size || m_lastFilledIndex != rhs.m_lastFilledIndex)
			return true;
		for (int i = 0; i < m_size; i++)
		{
			if (m_data[i] != rhs.m_data[i])
				return true;
		}
		return false;
	}
	bool operator<(NaiveVector& rhs) = delete;
	bool operator>(NaiveVector& rhs) = delete;
	bool operator<=(NaiveVector& rhs) = delete;
	bool operator>=(NaiveVector& rhs) = delete;

	T* begin()
	{
		return m_data;
	}
	T* end()
	{
		return m_data + m_lastFilledIndex + 1;
	}

	const T* begin() const
	{
		return m_data;
	}
	const T* end() const
	{
		return m_data + m_lastFilledIndex + 1;
	}
	~NaiveVector()
	{
		delete[] m_data;
	}
};