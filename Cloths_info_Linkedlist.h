#pragma once
#include <iostream>
#include <string>
#include "Main_window.h"
using namespace std;

struct Cloths
{
	int Id;
	string cloth_name;
	string colour;
	string size_of_cloth;
	int stock;
	float price;
};

struct Node1 {
	Cloths cloths;
	Node1* next;
};

class ClothsList
{
private:
	Node1* head;
	int size;

public:
	ClothsList() 
	{
		head = NULL;
		size = 0;
	}

	void addCloths(Cloths cloths)
	{
		Node1* newNode = new Node1;
		newNode->cloths = cloths;
		newNode->next = head;
		head = newNode;
		size++;
	}

	int searchClothsByID(int Id)
	{
		Node1* current = head;
		for (int i = 0; i < size; i++)
		{
			if (current->cloths.Id == Id)
			{
				return i;
			}
			current = current->next;
		}
		return -1;
	}
	
	int searchClothsByColour(string colour)
	{
		Node1* current = head;
		for (int i = 0; i < size; i++)
		{
			if (current->cloths.colour == colour)
			{
				return i;
			}
			current = current->next;
		}
		return -1;
	}

	int searchClothsBySize(string cloths_size)
	{
		Node1* current = head;
		for (int i = 0; i < size; i++)
		{
			if (current->cloths.size_of_cloth == cloths_size)
			{
				return i;
			}
			current = current->next;
		}
		return -1;
	}

	int get_price(int index) {
		Node1* current = head;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		return current->cloths.price;
	}

	void updateStock(int index, int stock)
	{
		Node1* current = head;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		current->cloths.stock = stock;
	}

	void printCloths()
	{
		cout << "________________________________________________________________________________________________________________________" << endl;
		cout << "Id\t\tColour\t\t\tSize\t\t\tStock\t\t\tPrice" << endl;
		cout << "________________________________________________________________________________________________________________________" << endl;
		Node1* temp = head;
		while (temp != NULL) 
		{
			cout << temp->cloths.Id << "\t\t" << temp->cloths.colour << "\t\t\t" << temp->cloths.size_of_cloth << "\t\t\t" << temp->cloths.stock << "\t\t\tRs." << temp->cloths.price << endl;
			temp = temp->next;
		}
		cout << "              " << endl;
		cout << "              " << endl;
	}


	void Remove_First()
	{
		if (head == NULL)
		{
			cout << "Empty List" << endl;
		}
		else
		{
			Node1* temp = head;
			if (size == 1)
			{
				delete temp;
				head = NULL;
				size = 0;
			}
			else
			{
				head = head->next;
				delete temp;
				size--;
			}
		}
	}

	void Remove_Last()
	{
		if (head == NULL)
		{
			cout << "List is Empty" << endl;
		}
		else
		{
			
			if (size == 1)
			{
				Node1* temp = head;
				delete temp;
				head = NULL;
				size = 0;
			}
			else
			{
				Node1* current = head;
				for (int i = 0; i < size - 1; i++) {
					current = current->next;
				}
				current->next = NULL;
				delete current;
				size--;
			}
		}
	}

	void Remove_Item(int pos)
	{
		if (pos < 0 || pos >= size)
		{
			cout << "Invalid Position" << endl;
		}
		else if (pos == 0)
		{
			cout << "Removed Item successfully..." << endl;
			Remove_First();
			
		}
		else if (pos == size-1)
		{
			cout << "Removed Item successfully..." << endl;
			Remove_Last();
		}
		else
		{
			Node1* current = head;
			for (int i = 0; i < pos; i++)
			{
				current = current->next;
			}
			Node1* temp = current ->next;
			current->next= temp->next;
			cout << "Removed Item successfully..." << endl;
			delete temp;
			size--;
		}
	}
};
