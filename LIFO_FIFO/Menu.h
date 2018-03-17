#pragma once

#include "FIFO.h"
#include "LIFO.h"

#include <iostream>
#include <stdlib.h>
#include <string>


template <class T>
class Menu
{
public:
	Menu();
	~Menu();

	void start();
	

private:
	FIFO<T> * fifo;
	LIFO<T> * lifo;

	void generateMenu();
	
	void clear();
	void pause();

	// choices 1-7
	void dataPushFIFO();
	void dataPopFIFO();
	void dataPrintFIFO();

	void dataPushLIFO();
	void dataPopLIFO();
	void dataPrintLIFO();
};

#include "Menu.tcc"