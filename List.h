#pragma once
#include<iostream>
#include"Element.h"
template <class T>
class List {

	Element<T>* head;
	Element<T>* q;
	int size;

public:

	List();
	List(T val);
	List(T* array, int size);
	~List();
	int getSize();
	
	T& operator[](const int index);
	void append(T val);
        //void save();
        //void push(T val);
        //T& pop();
        //void pop();
	//friend std::istream& operator>>(std::istream& in,List<T>&other);
	template<class T>
	friend std::ostream& operator<<(std::ostream& out, const List<T>& other);


};

#include"List.inl"
