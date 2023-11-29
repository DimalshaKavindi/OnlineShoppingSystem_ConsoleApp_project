#pragma once
#include <iostream>
#include <cstddef>
#include <string.h>
#include <cstdlib>
#include <stdio.h>

using namespace std;
#include "Customer_Info_Linkedlist.h"
#include "Cloths_info_Linkedlist.h"
#include"Administrator.h"
#include "Customer.h"



void Mainwindow(Customer_List &newcustomerlist,ClothsList &Skirt_list, ClothsList &Frock_list, ClothsList &Trouser_list, ClothsList& Blouse_list, OrdersQueue& orderslist)
{
	
	int choice;
	cout << "\t\t\t\t\t\t1.Administrator" << endl;
	cout << "\t\t\t\t\t\t2.Customer" << endl;
	cout << "\t\t\t\t\t\t3.Quit" << endl;
	
	cin >> choice;

	if (choice == 1) {
		int y;
		cout << "-> Press (1) to Log in to the Administrator" << endl;
		cout << "-> Press (2) to go to the Back" << endl;
		cin >> y;
		if (y == 1) {
			int a = Owner_Login();
			if (a == -1)
			{   
				system("cls");
				Ownerwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
				system("cls");
				cout << endl;
				return Mainwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
			}
		}
		else if (y == 2) {
			system("cls");
			return Mainwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
		}
		
	}
	
	else if (choice == 2) {
		int choice01;
		system("cls");
		cout << endl;
		cout << "\t\t\t\t\t\t1. Login" << endl;
		cout << "\t\t\t\t\t\t2. Sign Up" << endl;
		cout << "\t\t\t\t\t\t3. Back" << endl;

		cin >> choice01;

		if (choice01 == 1)
		{

			int b = Customer_Login(newcustomerlist);
			if (b == -1)
			{
				system("cls");
				Customer_Window(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
				system("cls");
				cout << endl;
				return Mainwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
			}

			int choice02;
			cout << "-> Press (1) go to the Back" << endl;

			cin >> choice02;
			if (choice02 == 1)
			{
				cout << endl;
				return Mainwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
			}

			else
			{
				cout << "Invalid choice...!!!" << endl;
				return Mainwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
			}

			
		}
		else if (choice01 == 2) {
			int k = Customer_Signup(newcustomerlist);

			if (k == -1)
			{
				cout << "Successfully SignedUp..." << endl;
				cout << "-> press (1) to go to the Main Menu" << endl;
				int c;
				cin >> c;
				if (c == 1)
				{
					system("cls");
					Mainwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
				}
			}
		}

		else if (choice01 == 3) {
			Mainwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
		}
		else
		{
			cout << "Invalid choice...!!!" << endl;
			Mainwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
		}

	}
	else if (choice == 3) {
		system("cls");
		exit(0);
	}

}
	


	