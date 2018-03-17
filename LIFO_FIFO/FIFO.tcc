
template<class T>
FIFO<T>::FIFO() {
	this->maxSize = 100 + 1; // extra room for tail
	stack.reserve(maxSize);

	this->tail = 0;
	this->head = 0;

	this->printEntry = [](T entry) {
		std::cout << entry;
	};
}

template<class T>
FIFO<T>::FIFO(int size) {
	this->maxSize = size + 1;
	stack.reserve(maxSize);

	this->tail = 0;
	this->head = 0;

	this->printEntry = [](T entry) {
		std::cout << entry;
	};
}

template<class T>
FIFO<T>::FIFO(void(*callback)(T entry)) {
	this->maxSize = 100 + 1;
	stack.reserve(maxSize);

	this->tail = 0;
	this->head = 0;

	this->printEntry = callback;
}

template<class T>
FIFO<T>::FIFO(void(*callback)(T entry), int size) {
	this->maxSize = size + 1;

	this->tail = 0;
	this->head = 0;

	this->printEntry = callback;
}

template<class T>
FIFO<T>::~FIFO() {

}

template <class T>
void FIFO<T>::push(T data) {

	if ((tail + 1) % maxSize == head) {
		std::cout << "Error, limit has been breached" << std::endl;
	}
	else {
		stack.insert(stack.begin() + tail, data);
		tail++;
	}
}

template <class T>
T FIFO<T>::pop() {

	if (head % maxSize == tail) {
		std::cout << "Error, there's nothing to delete" << std::endl;
		return nullObj;
	}
	else {
		T tempData = stack.at(head);
		
		head = (head + 1) % maxSize;
		return tempData;
	}
}

template <class T>
void FIFO<T>::setMaxSize(int size) {
	
	if (head < tail && tail < size) {
		maxSize = size + 1;
	}
	else if (abs(head - tail) > size) {
		std::cout << "Change of size impossible. Loss of data would be innevitable." << std::endl;
	}
	else {
		rearrange();
		maxSize = size + 1;
	}

}

template <class T>
void FIFO<T>::rearrange() {
	std::vector<T> newVect;

	if(tail >= head)
		newVect.assign(stack.begin() + head, stack.begin() + tail);
	else {
		newVect.assign(stack.begin() + head, stack.begin() + maxSize - 1);
		newVect.insert(newVect.end(), stack.begin(), stack.begin() + tail);
	}

	stack = newVect;

	int diff = abs(head - tail);

	head = 0;
	tail = head + diff;
}

template <class T>
int FIFO<T>::getMaxSize() {
	return maxSize;
}

template <class T>
void FIFO<T>::defineNullObject(T obj) {
	this->nullObj = obj;
}

template <class T>
void FIFO<T>::printData() {

	if (tail >= head) {

		for (int i = head; i < tail; i++) {
			printEntry(stack.at(i));
			std::cout << std::endl;
		}
	}

	else {

		// First pass from head to end
		for (int i = head; i < maxSize; i++) {
			printEntry(stack.at(i));
			std::cout << std::endl;
		}

		// Second pass from start to tail
		for (int i = 0; i < tail; i++) {
			printEntry(stack.at(i));
			std::cout << std::endl;
		}

	}

	std::cout << std::endl;

}