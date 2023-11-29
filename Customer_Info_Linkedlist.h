#pragma once
#include <iostream>
#include <string>

#include "Main_window.h"
using namespace std;


struct Customer
{
	string Name;
	string Username;
	string Password;
	string Email;
	string Mobile_Number;
	
};

struct Node
{
	Customer customer;
	Node* next;
};

class Customer_List
{
private:
	Node* head;
	int size;
public:
	Customer_List()
	{
		head = NULL;
		size = 0;
	}
	void Add_Customer(Customer customer)
	{
		Node* NewNode = new Node;
		NewNode->customer = customer;
		NewNode->next = head;
		head = NewNode;
		size++;
		
	}

	int searchCustomerByusername(string username)
	{
		Node* current = head;
		for (int i = 0; i < size; i++)
		{
			if (current->customer.Username == username)
			{
				return i;
			}
			current = current->next;
		}
		return -1;
	}

	int searchCustomerBypassword(string password)
	{
		Node* current = head;
		for (int i = 0; i < size; i++)
		{
			if (current->customer.Password == password)
			{
				return i;
			}
			current = current->next;
		}
		return -1;
	}

	void printAllcustomer()
	{
		cout << "\t\t\t\t__________________________________________" << endl;
		cout << "\t\t\t\t    Name\t\t\tUsername" << endl;
		cout << "\t\t\t\t__________________________________________" << endl;
		Node* current = head;
		while (current != NULL)
		{
			cout << "\t\t\t\t   " << current->customer.Name << "\t\t\t" << current->customer.Username << endl;
			current = current->next;
		}
		cout << "              " << endl;
		cout << "              " << endl;
	}
};