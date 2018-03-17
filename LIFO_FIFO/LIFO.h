#pragma once

#include <vector>
#include <iostream>


template <class T>
class LIFO
{

public:
	// for primitive data types
	LIFO();
	LIFO(int);

	// for structures / objects
	LIFO(void(*callback)(T entry));
	LIFO(void(*callback)(T entry), int);

	~LIFO();

	void push(T);
	T pop();

	void setMaxSize(int);
	int getMaxSize();

	void defineNullObject(T);

	void printData();

private:
	int maxSize;
	int top;

	void(*printEntry)(T entry);

	T nullObj;

	std::vector<T> stack;

};


#include "LIFO.tcc"