#pragma once
#include<iostream>
#include<string>
#include"Main_window.h"

using namespace std;
#include "Cloths_info_Linkedlist.h"
#include "Customer_Info_Linkedlist.h"
#include "Administrator.h"
#include "Orders_queue.h"

int Add_Bill(int Price,int Quantity)
{
	int amount;
	amount = Price * Quantity;
	return amount;
	
}

int Customer_Login(Customer_List& newcustomerlist)
{
	Customer newcustomer;

	cout << "\t\t\t\t\tEnter the Username:\t";
	cin >> newcustomer.Username;
	cout << "\t\t\t\t\tEnter the Password:\t";
	cin >> newcustomer.Password;
	
	int var1 = newcustomerlist.searchCustomerBypassword(newcustomer.Password);
	int var2 = newcustomerlist.searchCustomerByusername(newcustomer.Username);

	if (var1 != -1 && var2 != -1 && var1 == var2)
	{
		return -1;
	}

	cout << "Invalid username or password...!" << endl;
	return Customer_Login(newcustomerlist);
}

int Customer_Signup(Customer_List& newcustomerlist)
{
	Customer newcustomer;
	cout << "\t\t\t\t\tEnter the name\t\t  :\t" ;
	cin >> newcustomer.Name;
	cout << "\t\t\t\t\tEnter the username\t  :\t" ;
	cin >> newcustomer.Username;
	cout << "\t\t\t\t\tEnter the Password\t  :\t";
	cin >> newcustomer.Password;
	cout << "\t\t\t\t\tEnter the E-mail Address  :\t" ;
	cin >> newcustomer.Email;
	cout << "\t\t\t\t\tEnter the Mobile Number   :\t" ;
	cin >> newcustomer.Mobile_Number;



	int var2 = newcustomerlist.searchCustomerByusername(newcustomer.Username);
	if (var2 == -1)
	{
		newcustomerlist.Add_Customer(newcustomer);
		
		return -1;
	}
	cout << "Password is already exist...!" << endl;
	return Customer_Signup(newcustomerlist);
}


void Customer_Window(Customer_List& newcustomerlist, ClothsList& Skirt_list, ClothsList& Frock_list, ClothsList& Trouser_list, ClothsList& Blouse_list, OrdersQueue& orderslist)
{
	system("cls");

	cout << "\n\t\t\t\t\t\t ----------" << endl;
	cout << "\t\t\t\t\t\t  CUSTOMER" << endl;
	cout << "\t\t\t\t\t\t ----------" << endl;
	cout << endl;

	cout << "\t\t\t\t\t1. View All Lists" << endl;
	cout << "\t\t\t\t\t2. Buy items" << endl;
	cout << "\t\t\t\t\t3. Back to the Main Menu" << endl;

	//1.View All Lists
	int c1;
	cin >> c1;

	if (c1 == 1) {
		system("cls");

		cout << "\n\t\t\t\t\t\t-------------" << endl;
		cout << "\t\t\t\t\t\t  ALL ITEMS" << endl;
		cout << "\t\t\t\t\t\t-------------" << endl;
		cout << endl;


		cout << "----------------------------------------------- |Frock List| --------------------------------------------------------" ;
		cout << endl;
		Frock_list.printCloths();
		cout << endl;

		cout << "---------------------------------------------- |Trouser List| --------------------------------------------------------" ;
		cout << endl;
		Trouser_list.printCloths();
		cout << endl;

		cout << "----------------------------------------------- |Skirt List| --------------------------------------------------------" ;
		cout << endl;
		Skirt_list.printCloths();
		cout << endl;

		cout << "----------------------------------------------- |Blouse List| --------------------------------------------------------" ;
		cout << endl;
		Blouse_list.printCloths();
		cout << endl;


		cout << "-> Press (0) go to Back" << endl;
		int k;
		cin >> k;
		if (k == 0) {
			system("cls");
			return Customer_Window(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
		}
		else {
			system("cls");
			return Customer_Window(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
		}
	}
		
	//Buy items
	else if (c1 == 2) 
	{
		system("cls");
		cout << endl;
		cout << "These are available Items..." << endl;

		cout << "----------------------------------------------- |Frock List| --------------------------------------------------------" ;
		cout << endl;
		Frock_list.printCloths();
		cout << endl;

		cout << "---------------------------------------------- |Trouser List| --------------------------------------------------------" ;
		cout << endl;
		Trouser_list.printCloths();
		cout << endl;

		cout << "----------------------------------------------- |Skirt List| --------------------------------------------------------" ;
		cout << endl;
		Skirt_list.printCloths();
		cout << endl;

		cout << "----------------------------------------------- |Blouse List| --------------------------------------------------------" ;
		cout << endl;
		Blouse_list.printCloths();
		cout << endl;

		cout << "Here you can get additional discounts:" << endl;
		cout << "\t\t\t\t\tTotal" << "\t\t" << "Discount" << endl;
		cout << "\t\t\t\t________________________________________" << endl;
		cout << "\t\t\t\t\t>5000" << "\t\t" << "5%" << endl;
		cout << "\t\t\t\t\t>8000" << "\t\t" << "10%" << endl;
		cout << "\t\t\t\t\t>10000" << "\t\t" << "12%" << endl;
		cout << endl;

		int* a_Id = new int[100];
		int* b_Price = new int[100];
		int* c_Quantity = new int[100];
		int* d_Amount = new int[100];
		
		bool x = true;
		int total = 0;
		int j=0;
		while (x)
		{
			Cloths cloths;
			cout << "Please enter the cloth Id you wish want to buy? :\t" ;
			cin >> cloths.Id;
			int c_quentity;
			cout << "Please enter the Quantity\t\t\t:\t" ;
			cin >> c_quentity;
			int index;
			int price;
			int index1 = Frock_list.searchClothsByID(cloths.Id);
			int index2 = Trouser_list.searchClothsByID(cloths.Id);
			int index3 = Skirt_list.searchClothsByID(cloths.Id);
			int index4 = Blouse_list.searchClothsByID(cloths.Id);
			if (index1 != -1) {
				index = index1;
				price = Frock_list.get_price(index);
			}
			else if (index2 != -1) {
				index = index2;
				price = Trouser_list.get_price(index);
			}
			else if (index3 != -1) {
				index = index3;
				price = Skirt_list.get_price(index);
			}
			else if (index4 != -1) {
				index = index4;
				price = Blouse_list.get_price(index);
			}
			int Amount = Add_Bill( price, c_quentity);
			a_Id[j] = cloths.Id;
			b_Price[j] = price;
			c_Quantity[j] = c_quentity;
			d_Amount[j] = Amount;
			j++;

			total = total + Amount;
			cout << endl;
			cout << "-> Do you buy any otherthing?" << endl;;
			cout << "\t\t\t(1) Yes" << endl;
			cout << "\t\t\t(2) No " << endl;
			int var;
			cin >> var;
			if (var == 1) {
				x = true;
			}
			else {
				x = false;
			}
		}
		cout << "-> Place Order?" << endl;
		cout << "\t\t\t(1) Conform" << endl;
		cout << "\t\t\t(2) No" << endl;

		int c2;
		cin >> c2;
		if (c2 == 1) {

			system("cls");

			cout << "\n\t\t\t\t\t******** CART ********" << endl;
			cout << "__________________________________________________________________________________________" << endl;
			cout << "Cloth Id\t\t" << "Price\t\t\t" << "Quantity\t\t\t" << "Amount" << endl;
			cout << "__________________________________________________________________________________________" << endl;
			for (int k = 0; k < j; k++) {
				cout << a_Id[k] << "\t\t\t" << b_Price[k] << "\t\t\t" << c_Quantity[k] << "\t\t\t\tRs:" << d_Amount[k] << endl;
			}

			cout << endl;
			cout << "Your Calculated Bill...\n" << endl;

			int total_price;
			if (total >= 5000 && total < 8000) {
				total_price = total - ((total * 5 )/ 100);
				cout << "\t\t\tTotal Price with Discount = " << total <<" - (" << total << " * 5%)" << endl;
				cout << "\t\t\t\t\t\t  = Rs." << total_price << endl;
			}
			else if (total >= 8000 && total < 10000) {
				total_price = total - ((total * 10) / 100);
				cout << "\t\t\tTotal Price with Discount = " << total << " - (" << total << " * 10%)" << endl;
				cout << "\t\t\t\t\t\t  = Rs." << total_price << endl;
			}
			else if (total >= 10000) {
				total_price = total - ((total * 12 )/ 100);
				cout << "\t\t\tTotal Price with Discount = " << total << " - (" << total << " * 12%)" << endl;
				cout << "\t\t\t\t\t\t  = Rs." << total_price << endl;
			}
			else {
				cout << "\t\t\tTotal Price = Rs." << total << endl;
				
			}
			cout << "\nHow do you pay the bill?" << endl;
			cout << "\t(1) Cash on delivery" << endl;
			cout << "\t(2) Card payment" << endl;
			cout << endl;

			
			string Homeaddress;
			string Mobileno;
			string name;

			int z;
			cin >> z;
			if (z == 1) {
				cout << "  Enter the Name\t:\t";
				cin >> name;

				cout << "  Enter the Home Address  :\t";
				cin >> Homeaddress;

				cout << "  Enter the Mobile Number :\t";
				cin >> Mobileno;
			
				
					for (int k = 0; k < j; k++) {
						orderslist.Add_orderCOD(a_Id[k], c_Quantity[k], name, Homeaddress, Mobileno);
					}

					cout << endl;
					cout << "  We will deliver your order within 3 days..."<< endl;
			}
			else if (z == 2) {

				cout << "  Enter the Name\t:\t";
				cin >> name;
				
				cout << "  Enter the Home Address    :\t";
				cin >> Homeaddress;
				
				cout << "  Enter the Mobile Number   :\t";
				cin >> Mobileno;
				
				string Cardnumber;
				cout << "  Enter the Card Number     :\t";
				cin >> Cardnumber;
				
				string CVV;
				cout << "  Enter the CVV  \t:\t";
				cin >> CVV;

				string Holder_name;
				cout << "  Enter the Card Holder Name :\t";
				cin >> Holder_name;
				
				for (int k = 0; k < j; k++) {
					orderslist.Add_orderCP(a_Id[k], c_Quantity[k], name, Homeaddress, Mobileno, Cardnumber , Holder_name, CVV);
				}

				cout << endl;
				cout << "  Payment Successfully..." << endl;
				cout << "  We will deliver your order within 3 days..." << endl;
			}
			cout << endl;
			cout << "\t\t\t\t\t\tThank you...!" << endl;
			
		}
		cout << "-> Press (0) go to Back" << endl;
		int k;
		cin >> k;
		if (k == 0) {
			system("cls");
			return Customer_Window(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
		}
		else {
			system("cls");
			return Customer_Window(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
		}

	}
	//3. Back to the Main Menu
	else if (c1 == 3) {
		return;
	}
	return;

}