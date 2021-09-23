#pragma once
#include"List.h"
#include<iostream>
#include<string>
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
	Element<T>* elptr = new (Element<T>);
	elptr->setVal(val);
	elptr->setAdr(elptr);
	head = q = elptr;
	size++;
}

template<class T>
inline List<T>::List(T* arr, int size)
{
	this->size = 0;
	head = nullptr;
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
			while (qptr->getAdr() != head) //���������� �� ���������� 
				qptr = qptr->getAdr();
			qptr->setAdr(elptr);
			elptr->setAdr(head);
		}
		this->size++;
	}
	
}

template<class T>
inline List<T>::List(const List<T>& obj)
{
	this->head = nullptr;
	this->q = this->head;
	this->size = obj.size;

	Element<T>* elptrObj = obj.head;
	for (int i = 0; i < this->size; i++) {
		Element<T>* elptr = new (Element<T>);
		if (i == 0) {
			elptr->setVal(elptrObj->getVal());
			elptr->setAdr(elptr);
			this->head = this->q = elptr;
		}
		else {
			Element<T>* hptr = head;
			elptr->setVal(elptrObj->getVal());
			while (hptr->getAdr() != this->head) //���������� �� ���������� 
				hptr = hptr->getAdr();
			hptr->setAdr(elptr);
			elptr->setAdr(this->head);
		}
		elptrObj = elptrObj->getAdr();
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
inline List<T>& List<T>::operator=(const List<T>& obj)
{
	// TODO: �������� ����� �������� return
	this->head = nullptr;
	this->q = this->head;
	this->size = obj.size;

	Element<T>* elptrObj = obj.head;//������ �� ������ ������� �������� �������


	for (int i = 0; i < this->size; i++) {

		Element<T>* elptr = new (Element<T>);
		if (i == 0) {
			elptr->setVal(elptrObj->getVal());
			elptr->setAdr(elptr);
			this->head = this->q = elptr;
		}
		else {
			Element<T>* hptr = head;
			elptr->setVal(elptrObj->getVal());
			while (hptr->getAdr() != this->head) //���������� �� ���������� 
				hptr = hptr->getAdr();
			hptr->setAdr(elptr);
			elptr->setAdr(this->head);
		}
		elptrObj = elptrObj->getAdr();

		return *this;
	}


}

template<class T>
inline T List<T>::operator[](const int index)
{
	Element<T>*qptr = this->head;
	for (int i = 0; i < index; i++) {
		qptr = qptr->getAdr();
	}
	//T myObj = qptr->getVal();
	return T(qptr->getVal());//why i can't get object????
}

template<class T>
inline void List<T>::append(T val)
{

	Element<T>* elptr = new (Element<T>), * qptr = head;
	if (this->size == 0) {
		
		elptr->setVal(val);
		elptr->setAdr(elptr);
		head = q = elptr;
	}
	else {
		elptr->setVal(val);
		while (qptr->getAdr() != head) //���������� �� ���������� 
			qptr = qptr->getAdr();
		qptr->setAdr(elptr);
		elptr->setAdr(head);
	}
	this->size++;
}

template<class T>
inline auto List<T>::pop()
{
	try
	{
		Element<T>* qptr = head, val;
		if (this->size == 0) {
			throw "Empty list"
		}
		else {
			while (qptr->getAdr()->getAdr()!= head) //���������� �� �������������� 
				qptr = qptr->getAdr();
			val = q->getVal();
			delete q;
			q = qptr->getAdr();
			qptr->setAdr(head);
		}
		this->size--;
		return val;
	}
	catch (const std::exception&)
	{

	}
	
	
}

template<class T>
inline void List<T>::save(T& Obj)
{
	for (int i = 0; i < other.size; i++) {
		Element<T>* qptr = other.head;
		T val;
		while (qptr->getAdr() != other.head) { //���������� �� ���������� 
			val = qptr->getVal();
			val.save();
			qptr = qptr->getAdr();//��������� � ����������

		}
		val = qptr->getVal();
		val.save();

	}
	
}


//template<class T>
//inline std::istream& operator>>(std::istream& in, List<T>& other)
//{
//	
//}

template<class T>
inline std::ostream& operator<<(std::ostream& out, const List<T>& other)
{
	for (int i = 0; i < other.size; i++) {
		Element<T> *qptr = other.head;
	
		
		while (qptr->getAdr() != other.head) { //���������� �� ���������� 
			out << qptr->getVal()<<" ";
			qptr = qptr->getAdr();

		}
		out<<qptr->getVal()<<"\n";
		
		return out;
	}
	
}
