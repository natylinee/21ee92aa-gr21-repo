#pragma once
#include<iostream>
#include<memory>
using namespace std;
template<class T>
struct Node
{
	T value;
	
	shared_ptr<Node<T>> next;
	Node(T d) {			// Konstruktor jednoargumentowy
		value = d;		// Przypisanie wartosci podczas konstrukcji
		next = nullptr;
	}
	Node() { //Konstruktor bezargumentowy
		//value = NULL;
		next = nullptr;
	}
	Node(const Node& a) //Konstruktor kopjujacy (konieczna referencja aby nie powstawaly obiekty tymczasowe)
	{
		value = a.value;
	}
	Node(Node&& a) :value(a.value) //konstruktor przenoszacy
	{
		a.value = -1; //wolno modyfikowac argument kontruktora
	}
	Node& operator =(const T& a) //operator przypisania
	{
		if (this == &a) //przypisanie do samego siebie?
			return *this;
		value = a.value;
		return *this; //zwroc obiekt po przypisaniu
	}
	
};

