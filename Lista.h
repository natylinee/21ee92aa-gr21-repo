#pragma once
#include<iostream>
#include<memory>
#include<fstream>
#include<sstream>
#include "Node.h"
#include "Osoby.h"
#include "Pojazdy.h"
using namespace std;
template<class T>
class LinkedList{
private:
	int counter;
public:
	shared_ptr<Node<T>> head = make_shared <Node<T>>();
	shared_ptr<Node<T>> tail = make_shared <Node<T>>();

	LinkedList(); //Konstruktor jednoargumentowy
	~LinkedList(); //Destruktor
	
	shared_ptr<Node<T>> get(int index) const;

	void insert_head(const T& value);
	void insert_tail(const T& value);
	void insert(int index, const T& value);

	void remove_head();
	void remove_tail();
	void remove(int index);

	int search(const T& value);
	int size() const;
	void show() const;
	//int getSize();
	
	void sortUp(int counter);
	void sortDown(int counter);
	void getData(string nameFile);
	void throwData(string nameFile);
};


template <typename T>
LinkedList<T>::LinkedList() {
	head = nullptr;
	tail = nullptr;
}
template <typename T>
LinkedList<T>::~LinkedList() {
	cout << "Destruktor" << endl;
}
template <class T>
shared_ptr<Node<T>> LinkedList<T>::get(int index) const
{
	if (index < 0 || index> counter)
		return nullptr;
	shared_ptr<Node<T>> temp_node = head;
	for (int i = 0; i < index; ++i)
	{
		temp_node = temp_node->next;
	}
	return temp_node;
}

template<class T>
void LinkedList<T>::insert_head(const T& value)
{
	shared_ptr<Node<T>> temp_node = make_shared<Node<T>>(value);
	temp_node->next = head;
	head = temp_node;
	if (counter == 0)
		tail = head;
	counter++;
}

template<class T>
void LinkedList<T>::insert_tail(const T& value)
{
	if (counter == 0)
	{
		insert_head(value);
		return;
	}
	shared_ptr<Node<T>> temp_node = make_shared<Node<T>>(value);
	tail->next = temp_node;
	tail = temp_node;
	counter++;
}

template<class T>
void LinkedList<T>::insert(int index, const T& value)
{
	if (index<0 || index>counter)
		return;
	if (index == 0)
	{
		insert_head(value);
		return;
	}
	else if (index == counter)
	{
		insert_tail(value);
		return;
	}
	shared_ptr<Node<T>> prev_node = head; 
	//szukamy elementu na pozycji przed ta na ktora chcemy wstawic element
	for (int i = 0; i < index - 1 ; ++i)
	{
		prev_node = prev_node->next;
	}
	//wskaznik na element, ktory bedzie kolejnym po wstawianym
	shared_ptr<Node<T>> next_node = prev_node->next;
	//tworzenie nowego elementu i wstawienie go w wybranej pozycji
	shared_ptr<Node<T>> new_node = make_shared<Node<T>>(value);
	prev_node->next = new_node;
	new_node->next = next_node;

	counter++;
}

template<class T>
void LinkedList<T>::remove_head()
{
	if (counter == 0)
		return;
	head = head->next; 
	counter--;
}

template<class T>
void LinkedList<T>::remove_tail()
{
	if (counter == 0)
		return;
	if (counter == 1)
	{
		remove_head();
		return;
	}
	shared_ptr<Node<T>> prev_node = head;
	shared_ptr<Node<T>> temp_node = head->next;

	while (temp_node->next)
	{
		prev_node = prev_node->next;
		temp_node = temp_node->next;
	}
	prev_node->next = nullptr;
	tail = prev_node;
	temp_node = nullptr; 
	counter--;
}

template<class T>
void LinkedList<T>::remove(int index)
{
	if (counter == 0)
		return;
	if (index < 0 || index >= counter) //wybrany z³y indeks
		return;
	if (index == 0)
	{
		remove_head();
		return;
	}
	else if (index == counter - 1)
	{
		remove_tail();
		return;
	}
	shared_ptr<Node<T>> prev_node = head;
	for (int i = 0; i < index - 1; ++i)
	{
		prev_node = prev_node->next;
	}
	shared_ptr<Node<T>> temp_node= prev_node->next;
	shared_ptr<Node<T>> next_node = temp_node->next;
	prev_node->next = next_node;
	temp_node = nullptr;
	counter--;
}

template<class T>
int LinkedList<T>::search(const T& value) {
	if (counter == 0)
	{
		return -1; //nie znaleziono
	}
	int index = 0;
	shared_ptr<Node<T>> temp_node = head;
	while (temp_node->value != value)
	{
		index++;
		temp_node = temp_node->next;
		if (!temp_node) //jesli skonczyly sie elementy do przeszukiwania
		{
			return -1; //nie znaleziono
		}

	}
	return index;
}

template<class T>
int LinkedList<T>::size() const
{
	return counter;
}

template <class T>
void LinkedList<T>::show() const {
	shared_ptr<Node<T>> temp_node = head;

	while (temp_node) {
		cout << temp_node->value << endl;
		temp_node = temp_node->next;
	}
	cout << endl;
}


//template<class T>
//int LinkedList<T>::getSize()
//{
//	return counter;
//}

template<class T>
void LinkedList<T>::sortUp(int counter)
{

	shared_ptr<Node<T>> temp_node = head;
	shared_ptr<Node<T>> next_node = head->next;
	for (int i = 0; i < counter - 1; i++)
	{
		for (int j = 0; j < counter - i - 1; j++)
		{
			if (temp_node->value > next_node->value) 
			{
				shared_ptr<Node<T>> t = make_shared <Node<T>>(temp_node->value);
				temp_node->value = next_node->value;
				next_node->value = t->value;
			}//swap
			temp_node = next_node;	//if (arr[j] > arr[j+1])
			next_node = next_node->next;
		}
		temp_node = head;
		next_node = head->next;
	}

}

template<class T>
void LinkedList<T>::sortDown(int counter)
{
	shared_ptr<Node<T>> temp_node = head;
	shared_ptr<Node<T>> next_node = head->next;
	for (int i = 0; i < counter - 1; i++)
	{
		for (int j = 0; j < counter - i - 1; j++)
		{
			if (temp_node->value < next_node->value)
			{
				shared_ptr<Node<T>> t = make_shared <Node<T>>(temp_node->value);
				temp_node->value = next_node->value;
				next_node->value = t->value;
			}//swap
			temp_node = next_node;	//if (arr[j] > arr[j+1])
			next_node = next_node->next;
		}
		temp_node = head;
		next_node = head->next;
	}
}

template<class T>
void LinkedList<T>::getData(string nameFile)
{
	ifstream file(nameFile, ios::binary);
	head = nullptr; //wyczyszczenie listy
	tail = nullptr;
	counter = 0;
	T value_tmp_node;

	while (file.good())
	{
		string line;
		while (getline(file, line))
		{
			istringstream stream(line);
			stream  >> value_tmp_node;
			this->insert_tail(value_tmp_node);
		}
	}
	file.close();
}

//template<class T>
//void LinkedList<T>::throwData(string nameFile)
//{
//	ofstream outfile(nameFile, ios::binary);
//	shared_ptr<Node<T>> tmp_node = head;
//	for (int i = 0; i < counter; i++)
//	{
//		T value_tmp = tmp_node->value;
//		outfile.write((const char*)&value_tmp, sizeof value_tmp);
//		tmp_node = tmp_node->next;
//	}
//	outfile.close();
//}
//template<class T>
//void LinkedList<T>::getData(string nameFile)
//{
//	ifstream file(nameFile, ios::binary);
//	head = nullptr; //wyczyszczenie listy
//	tail = nullptr;
//	counter = 0;
//	T value_tmp_node;
//	file.read((char*)&value_tmp_node, sizeof value_tmp_node);
//
//	while (file.good())
//	{
//
//		this->insert_head(value_tmp_node);
//		file.read((char*)&value_tmp_node, sizeof value_tmp_node);
//
//	}
//	file.close();
//
//}
template<class T>
void LinkedList<T>::throwData(string nameFile)
{
	ofstream outfile(nameFile, ios::binary);
		shared_ptr<Node<T>> tmp_node = head;
		for (int i = 0; i < counter; i++)
		{
			T value_tmp = tmp_node->value;
			outfile << value_tmp << endl;
			tmp_node = tmp_node->next;
		}
		outfile.close();
}