#pragma once
#include <iostream>
#include <string>
#include "Administrator.h"
using namespace std;

struct Orders
{
	int cloth_ID;
	int quantity;
	string name;
	string Address;
	string Mobile_number;
	string cardnum;
	string cvv;
	string holdername;

};

class OrdersQueue
{
private:

	int front;
	int rear;
	int capacity;
	int size;
	Orders* data;

public:

	OrdersQueue(int cap)
	{
		front = 0;
		rear = 0;
		capacity = cap;
		size = 0;
		data = new Orders[capacity];
	}

	void Add_orderCOD(int ID, int quan, string name, string address, string Mobile_no)
	{

		Orders order;
		order.cloth_ID = ID;
		order.quantity = quan;
		order.name = name;
		order.Address = address;
		order.Mobile_number = Mobile_no;

		data[rear] = order;
		rear = (rear + 1) % capacity;
		size++;

	}

	void Add_orderCP(int ID, int quan, string name, string address, string Mobile_no,string cardno, string cvv, string holname)
	{

		Orders order;
		order.cloth_ID = ID;
		order.quantity = quan;
		order.name = name;
		order.Address = address;
		order.Mobile_number = Mobile_no;
		order.cardnum = cardno;
		order.cvv = cvv;
		order.holdername = holname;

		data[rear] = order;
		rear = (rear + 1) % capacity;
		size++;

	}

	int printCOD()
	{
		cout << "\t\t\t\t\tCash on Delivary Orders" << endl;
		cout << endl;

		cout << "_________________________________________________________________" << endl; 
		cout << "Name\t" << "Cloth Id\t" << "Quantity\t" << "Address\t\t" << "Mobile No" << endl;
		cout << "_________________________________________________________________" << endl;


		if (size == 0)
		{
			cout << "Queue is empty" << endl;
			return -1;
		}
		else
		{
			int index = front;
			for (int i = 0; i < size; i++)
			{
				cout << data[index].name << " " << "\t" << data[index].cloth_ID << " " << "\t\t" << data[index].quantity << "\t\t" << data[index].Address << "\t\t" << data[index].Mobile_number << endl;
				index = (index + 1) % capacity;
				
			}
			cout << endl;
		}
	}

	int printCP()
	{
		cout << "\t\t\t\t\tCard Payment Orders" << endl;
		cout << endl;
		cout << "____________________________________________________________________________________________________________" << endl;
		cout << "Name\t" << "Cloth Id\t" << "Quantity\t" << "Address\t\t" << "Mobile No\t" << "Card No\t\t" << "CVV\t" << "Holder Name" << endl;
		cout << "____________________________________________________________________________________________________________" << endl;


		if (size == 0)
		{
			cout << "Queue is empty" << endl;
			return -1;
		}
		else
		{
			int index = front;
			for (int i = 0; i < size; i++)
			{
				cout << data[index].name << " " << "\t" << data[index].cloth_ID << " " << "\t\t" << data[index].quantity << "\t\t" << data[index].Address << "\t\t" << data[index].Mobile_number << "\t" << data[index].cardnum << "\t\t" << data[index].holdername << "\t" << data[index].cvv << endl;
				index = (index + 1) % capacity;

			}
			cout << endl;
		}
	}
};