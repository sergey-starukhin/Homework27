#include "MyString.h"

MyString& MyString::operator=(const MyString& other)
{
	if (this == &other)
	{
		return *this;
	}
	assign(other.data);
	return *this;
}

MyString& MyString::operator+=(const MyString& other)
{
	int newLength = length + other.length + 1;
	char* newData = new char[newLength];
	strcpy_s(newData, newLength, data);
	strcat_s(newData, newLength, other.data);
	delete[] data;
	data = newData;
	length = newLength - 1;
	return *this;
}

MyString MyString::operator+(const MyString& other) const
{
	MyString result = *this;
	result += other;
	return result;
}

MyString& MyString::operator=(MyString&& other)
{
	if (this == &other)
	{
		return *this;
	}
	delete[] data;
	data = other.data;
	length = other.length;
	other.data = nullptr;
	other.length = 0;
	return *this;
}