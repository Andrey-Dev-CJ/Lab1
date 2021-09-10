#pragma once
#include"List.h"
#include<iostream>

template<class T>
inline List<T>::List()
{
	head = q = nullptr;
	size = 0;
	
}

template<class T>
inline List<T>::List(T val)
{
	size = 0;
	head = nullptr;
	Element<T>* elptr = new(Element<T>);
	elptr->setVal(val);
	elptr->setAdr(elptr);
	head = q = elptr;
	size++;
}

template<class T>
inline List<T>::List(T* arr, int size)
{
	this->size = 0;
	q = nullptr;
	for (int i = 0; i < size; i++) {
		Element<T>* elptr = new (Element<T>), * qptr = head;
		if (this->size == 0) {
			elptr->setVal(arr[i]);
			elptr->setAdr(elptr);
			head = q = elptr;
		}
		else {
			elptr->setVal(arr[i]);
			while (qptr->getAdr() != head) //проходимся до последнего 
				qptr = qptr->getAdr();
			qptr->setAdr(elptr);
			elptr->setAdr(head);
		}
		size++;
	}

}

template<class T>
inline List<T>::~List()
{
	try {
		if (head == nullptr)
			throw "error";
		Element<T>* ptr = q;
		for (int i = 0; i < size; i++) {
			ptr = ptr->getAdr();
			delete head;
			head = ptr;

		}
		size = 0;
	}
	catch (...) {
		std::cout << " ";
	}
}

template<class T>
inline int List<T>::getSize()
{
	return this->size;
}

template<class T>
inline T& List<T>::operator[](const int index)
{
	Element<T>*qptr = this->head;
	for (int i = 0; i < index; i++) {
		qptr = qptr->getAdr();
	}
	
	return qptr->getVal();
}

template <class T>
std::ostream& operator<<(std::ostream& out, const List<T>& other) {
	for (int i = 0; i < size; i++) {
		out << other[i];
	}
	return out;
}