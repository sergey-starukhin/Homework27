#include <cstring>
#include <iostream>
#pragma once

using namespace std;

class MyString
{
private:
	char* data;
	int length;

	void assign(const char* text)
    {
        int newLength = (int)strlen(text);
        char* newData = new char[newLength + 1];
        strcpy_s(newData, newLength + 1, text);
        delete[] data;
        data = newData;
        length = newLength;
    }

public:

	MyString(const char* text) : data(nullptr), length(0)
	{
		if (text == nullptr)
		{
			text = "";
		}
		assign(text);
	}

	MyString() : MyString("") {}

	MyString(const MyString& other) : data(nullptr), length(0)
	{
		assign(other.data);
	}

	MyString(MyString&& other) : data(other.data), length(other.length)
	{
		other.data = nullptr;
		other.length = 0;
	}

	~MyString()
	{
		delete[] data;
	}

	//getters
	int getLength() const;

	//operators
	bool operator==(const MyString& other) const;
	bool operator!=(const MyString& other) const;
	bool operator<(const MyString& other) const;
	MyString& operator=(const MyString& other);
	MyString& operator+=(const MyString& other);
	MyString operator+(const MyString& other) const;
	MyString& operator=(MyString&& other);

	char& operator[](int index)
	{
		return data[index];
	}

	char operator[](int index) const
	{
		return data[index];
	}

	//friend operators
	friend ostream& operator<<(ostream& os, const MyString& str);

	// other methods
	void print() const;
};

inline int MyString::getLength() const
{
	return length;
}

inline bool MyString::operator==(const MyString& other) const
{
	return strcmp(data, other.data) == 0;
}

inline bool MyString::operator!=(const MyString& other) const
{
	return strcmp(data, other.data) != 0;
}

inline void MyString::print() const
{
	cout << "[" << data << "] длина: " << getLength() << endl;
}

inline bool MyString::operator<(const MyString& other) const
{
	return strcmp(data, other.data) < 0;
}
