#pragma once

#include <vector>
#include <iostream>

template<class T>
class FIFO {

public:
	// for primitive data types
	FIFO();
	FIFO(int);

	// for structures / objects
	FIFO(void(*callback)(T entry));
	FIFO(void(*callback)(T entry), int);

	~FIFO();

	void push(T);
	T pop();

	void setMaxSize(int);
	int getMaxSize();

	void defineNullObject(T obj);

	void printData();

private:
	int maxSize;

	int tail;
	int head;

	void(*printEntry)(T entry);

	std::vector<T> stack;

	T nullObj;

	void rearrange();

};

#include "FIFO.tcc"