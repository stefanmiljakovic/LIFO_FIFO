
template <class T>
LIFO<T>::LIFO() {
	this->maxSize = 100;
	this->stack.reserve(100);

	this->top = 0;

	this->printEntry = [](T entry) {
		std::cout << entry;
	};
}

template <class T>
LIFO<T>::LIFO(int size) {
	this->maxSize = size;
	this->stack.reserve(size);

	this->top = 0;

	this->printEntry = [](T entry) {
		std::cout << entry;
	};
}

template <class T>
LIFO<T>::LIFO(void(*callback)(T entry)) {
	this->maxSize = 100;
	this->stack.reserve(100);

	this->top = 0;

	this->printEntry = callback;
}

template <class T>
LIFO<T>::LIFO(void(*callback)(T entry), int size) {
	this->maxSize = size;
	this->stack.reserve(size);

	this->top = 0;

	this->printEntry = callback;
}

template <class T>
LIFO<T>::~LIFO() {

}

template <class T>
void LIFO<T>::push(T data) {
	if (top < maxSize) {
		stack.insert(stack.begin() + top, data);
		top++;
	}
	else
		std::cout << "Error! Limits of stack have been breached." << std::endl;
}

template <class T>
T LIFO<T>::pop() {

	if (top > 0) {
		top--;
		T tempData = stack.at(top);

		stack.erase(stack.begin() + top);
		
		return tempData;
	}
	else {
		std::cout << "Stack appears to be empty ? Push data into stack in order to pop it." << std::endl; 
		return nullObj;
	}

}

template <class T>
int LIFO<T>::getMaxSize() {
	return maxSize;
}

template <class T>
void LIFO<T>::setMaxSize(int size) {
	int minSize = top;

	if (size > minSize) {
		maxSize = size;
		stack.reserve(size);
	}
	else {
		std::cout << "Error! You would lose data if you made stack smaller. Aborting!" << std::endl;
	}
}


template <class T>
void LIFO<T>::defineNullObject(T obj) {
	this->nullObj = obj;
}

template <class T>
void LIFO<T>::printData() {

	for (int i = 0; i < top; i++) {
		this->printEntry(stack.at(i));
		std::cout << std::endl;
	}

	std::cout << std::endl;
}