#include "stdafx.h"
#include "Menu.h"

using namespace std;

template <class T>
Menu<T>::Menu()
{
}

template <class T>
Menu<T>::~Menu()
{
}


template <class T>
void Menu<T>::start() {
	int size;

	cout << "Enter size for LIFO stack: ";
	cin >> size;

	lifo = new LIFO<T>(size);

	cout << "Enter size for FIFO stack: ";
	cin >> size;

	fifo = new FIFO<T>(size);

	generateMenu();
}


template <class T>
void Menu<T>::clear() {
	system("cls");
}

template <class T>
void Menu<T>::pause() {
	system("pause");
}



template <class T>
void Menu<T>::dataPushFIFO() {
	T data;

	clear();

	cout << "Enter data to push into FIFO: ";
	cin >> data;

	fifo->push(data);

	generateMenu();
}

template <class T>
void Menu<T>::dataPushLIFO() {
	T data;

	clear();

	cout << "Enter data to push into LIFO: ";
	cin >> data;

	lifo->push(data);

	generateMenu();
}

template <class T>
void Menu<T>::dataPopFIFO() {
	
	clear();
	cout << "Data popped from FIFO: " << fifo->pop() << endl << endl;
	pause();

	generateMenu();
}


template <class T>
void Menu<T>::dataPopLIFO() {

	clear();
	cout << "Data popped from LIFO: " << lifo->pop() << endl << endl;
	pause();

	generateMenu();
}

template <class T>
void Menu<T>::dataPrintFIFO() {
	clear();

	cout << "Data in FIFO:\n\n";
	fifo->printData();
	cout << "\n\n";

	pause();
	generateMenu();
}

template <class T>
void Menu<T>::dataPrintLIFO() {
	clear();

	cout << "Data in LIFO:\n\n";
	lifo->printData();
	cout << "\n\n";

	pause();
	generateMenu();
}


template <class T>
void Menu<T>::generateMenu() {
	clear();

	cout << "LIFO - Choices:\n"
		<< "1) Push entry\n"
		<< "2) Pop and get entry\n"
		<< "3) Print all data\n\n"
		<< "FIFO - Choices:\n"
		<< "4) Push entry\n"
		<< "5) Pop and get entry\n"
		<< "6) Print all data\n\n"
		<< "7) End\n\n"
		<< "Choice: ";

	string select;
	do {

		if (!getline(cin, select)) {
			generateMenu();
		}

	} while (select.length() != 1);

	switch (select[0]) {
	case '1':
		dataPushLIFO();
		break;
	case '2':
		dataPopLIFO();
		break;
	case '3':
		dataPrintLIFO();
		break;
	case '4':
		dataPushFIFO();
		break;
	case '5':
		dataPopFIFO();
		break;
	case '6':
		dataPrintFIFO();
		break;
	case '7':
		return;
	default:
		generateMenu();
	}
}

