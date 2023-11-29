#pragma once
#include<iostream>
#include<string>
#include"Main_window.h"

using namespace std;
#include "Cloths_info_Linkedlist.h"
#include "Customer_Info_Linkedlist.h"
#include "Customer.h" 


int Owner_Login()
{
	string username = "shop123";
	string passwd = "123";
	string usercode;
	string passcode;
	cout << "\t\t\t\t\tEnter the Usercode:\t";
	cin >>usercode;
	cout << "\t\t\t\t\tEnter the Passcode:\t" ;
	cin >> passcode;

	if (usercode == username && passcode == passwd)
	{
		return -1;
	}
	cout << "Invalid Usercode and Passcode...!!!" << endl;
	return Owner_Login();
}



void Ownerwindow(Customer_List& newcustomerlist, ClothsList& Skirt_list, ClothsList& Frock_list, ClothsList& Trouser_list, ClothsList& Blouse_list, OrdersQueue& orderslist)
{
	cout << "\n\t\t\t\t\t\t-------------" << endl;
	cout << "\t\t\t\t\t\tADMINISTRATOR" << endl;
	cout << "\t\t\t\t\t\t-------------" << endl;

	cout << "\t\t\t\t\t01. Add new clothes" << endl;
	cout << "\t\t\t\t\t02. Remove clothes" << endl;
	cout << "\t\t\t\t\t03. Update clothes" << endl;
	cout << "\t\t\t\t\t04. Search clothes by Id" << endl;
	cout << "\t\t\t\t\t05. Search clothes by Colour" << endl;
	cout << "\t\t\t\t\t06. Search clothes by Size" << endl;
	cout << "\t\t\t\t\t07. View Available Items" << endl;
	cout << "\t\t\t\t\t08. View all customers" << endl;
	cout << "\t\t\t\t\t09. Search customer by Username" << endl;
	cout << "\t\t\t\t\t10. View orders" << endl;
	cout << "\t\t\t\t\t11. Main menu" << endl;

	// 1.Add clothes
	int choice03;
	cin >> choice03;
	if (choice03 == 1)
	{
			Cloths cloths;
			
			cout << "\t\t\t\t\tEnter the cloth Id:\t" ;
			cin >> cloths.Id;
			cout << "\t\t\t\t\tEnter the Colour:\t" ;
			cin >> cloths.colour;
			cout << "\t\t\t\t\tEnter the Size:\t\t" ;
			cin >> cloths.size_of_cloth;
			cout << "\t\t\t\t\tEnter the Stock:\t" ;
			cin >> cloths.stock;
			cout << "\t\t\t\t\tEnter the Price:\tRs." ;
			cin >> cloths.price;
			cout << "\t\t\t\t\tEnter the cloth category:\t" << endl;
			cout << "\t\t\t\t\t\t01. Frock" << endl;
			cout << "\t\t\t\t\t\t02. Trouser" << endl;
			cout << "\t\t\t\t\t\t03. Skirt" << endl;
			cout << "\t\t\t\t\t\t04.Blouse" << endl;

			int choice04;
			cin >> choice04;
			switch (choice04)
			{
			case 01:
				Frock_list.addCloths(cloths);
				cout << "Successfully Added Item..." << endl;
				break;
			case 02:
				Trouser_list.addCloths(cloths);
				cout << "Successfully Added Item..." << endl;
				break;
			case 03:
				Skirt_list.addCloths(cloths);
				cout << "Successfully Added Item..." << endl;
				break;
			case 04:
				Blouse_list.addCloths(cloths);
				cout << "Successfully Added Item..." << endl;
				break;
			}
			cout << "-> Press (0) go to Back" << endl;
			int k;
			cin >> k;
			if (k == 0) {
				system("cls");
				return Ownerwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
			}
			else {
				system("cls");
				return Ownerwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
			}
				


	}
	//2.Remove cloths
	else if (choice03 == 2) 
	{
		
		int id;
		cout << "\t\t\t\t\tEnter the cloth Id:";
		cin >> id;
		cout << "\t\t\t\t\tEnter the cloth category" << endl;
		cout << "\t\t\t\t\t\t01. Frock" << endl;
		cout << "\t\t\t\t\t\t02. Trouser" << endl;
		cout << "\t\t\t\t\t\t03. Skirt" << endl;
		cout << "\t\t\t\t\t\t04.Blouse" << endl;
		
		
		int choice05;
		cin >> choice05;
		switch (choice05)
		{
		case 01:
			int var1;
			var1= Frock_list.searchClothsByID(id);
			Frock_list.Remove_Item(var1);
			break;
		case 02:
			int var2;
			var2 = Trouser_list.searchClothsByID(id);
			Trouser_list.Remove_Item(var2);
			break;
		case 03:
			int var3;
			var3 = Skirt_list.searchClothsByID(id);
			Skirt_list.Remove_Item(var3);
			break;
		case 04:
			int var4;
			var4 = Blouse_list.searchClothsByID(id);
			Skirt_list.Remove_Item(var4);
			break;
		}
		cout << "-> Press (0) go to Back" << endl;
		int k;
		cin >> k;
		if (k == 0) {
			system("cls");
			return Ownerwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
		}
		else {
			system("cls");
			return Ownerwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
		}
	}

	//3.Update clothes stock
	else if (choice03 == 3)
	{
		int id;
		int stock;
		cout << "\t\t\t\t\tEnter the cloth Id:\t" ;
		cin >> id;
		cout << "\t\t\t\t\tEnter the new Stock:\t" ;
		cin >> stock;
		cout << "\t\t\t\t\tEnter the cloth category:" << endl;
		cout << "\t\t\t\t\t\t01. Frock" << endl;
		cout << "\t\t\t\t\t\t02. Trouser" << endl;
		cout << "\t\t\t\t\t\t03. Skirt" << endl;
		cout << "\t\t\t\t\t\t04. Blouse" << endl;

		int choice06;
		cin >> choice06;
		switch (choice06)
		{
		case 01:
			int var5;
			var5 = Frock_list.searchClothsByID(id);
			Frock_list.updateStock(var5, stock);
			cout << "Successfully Updated...\n" << endl;
			break;
		case 02:
			int var6;
			var6 = Trouser_list.searchClothsByID(id);
			Trouser_list.updateStock(var6, stock);
			cout << "Successfully Updated...\n" << endl;
			break;
		case 03:
			int var7;
			var7 = Skirt_list.searchClothsByID(id);
			Skirt_list.updateStock(var7, stock);
			cout << "Successfully Updated...\n" << endl;
			break;
		case 04:
			int var8;
			var8 = Blouse_list.searchClothsByID(id);
			Blouse_list.updateStock(var8, stock);
			cout << "Successfully Updated...\n" << endl;
			break;
		}
		cout << "-> Press (0) go to Back" << endl;
		int k;
		cin >> k;
		if (k == 0) {
			system("cls");
			return Ownerwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
		}
		else {
			system("cls");
			return Ownerwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
		}
	}

	// search by cloth id
	else if (choice03 == 4){
		int ID;
		cout << "\t\t\t\t\tEnter the clothes Id:\t" ;
		cin >> ID;
		int a = Frock_list.searchClothsByID(ID);
		int b = Trouser_list.searchClothsByID(ID);
		int c = Skirt_list.searchClothsByID(ID);
		int d = Blouse_list.searchClothsByID(ID);
		if (a != -1)
		{
			cout << "\t\t\t\t\tItem Available in the Frock List..." << endl;
		}
		else
		{
			cout << "\t\t\t\t\tItem is not Available in the Frock List...!" << endl;
		}
		
		if (b != -1)
		{
			cout << "\t\t\t\t\tItem Available in the Trouser List..." << endl;
		}
		else
		{
			cout << "\t\t\t\t\tItem is not Available in the Trouser List...!" << endl;
		}
		if (c != -1)
		{
			cout << "\t\t\t\t\tItem Available in the Skirt List..." << endl;
		}
		else
		{
			cout << "\t\t\t\t\tItem is not Available in the Skirt List...!" << endl;
		}
		if (d != -1)
		{
			cout << "\t\t\t\t\tItem Available in the Blouse List..." << endl;
		}
		else
		{
			cout << "\t\t\t\t\tItem is not Available in the Blouse List...!" << endl;
		}
		
		cout << "-> Press (0) go to Back" << endl;
		int k;
		cin >> k;
		if (k == 0) {
			system("cls");
			return Ownerwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
		}
		else {
			system("cls");
			return Ownerwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
		}
	}
	
	//search by colour
	else if (choice03 == 5) {
		string clr;
		cout << "\t\t\t\t\tEnter the Colour:\t";
		cin >> clr;
		int e = Frock_list.searchClothsByColour(clr);
		int f = Trouser_list.searchClothsByColour(clr);
		int g = Skirt_list.searchClothsByColour(clr);
		int h = Blouse_list.searchClothsByColour(clr);
		if (e != -1)
		{
			cout << "\t\t\t\t\tItem Available in the Frock List..." << endl;
		}
		else
		{
			cout << "\t\t\t\t\tItem is not Available in the Frock List...!" << endl;
		}

		if (f != -1)
		{
			cout << "\t\t\t\t\tItem Available in the Trouser List..." << endl;
		}
		else
		{
			cout << "\t\t\t\t\tItem is not Available in the Trouser List...!" << endl;
		}
		if (g != -1)
		{
			cout << "\t\t\t\t\tItem Available in the Skirt List..." << endl;
		}
		else
		{
			cout << "\t\t\t\t\tItem is not Available in the Skirt List...!" << endl;
		}
		if (h != -1)
		{
			cout << "\t\t\t\t\tItem Available in the Blouse List..." << endl;
		}
		else
		{
			cout << "\t\t\t\t\tItem is not Available in the Blouse List...!" << endl;
		}

		cout << "-> Press (0) go to Back" << endl;
		int k;
		cin >> k;
		if (k == 0 ) {
			system("cls");
			return Ownerwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
		}
		else {
			system("cls");
			return Ownerwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
		}
	}
	//search by size
	else if (choice03 == 6) {
		string size;
		cout << "\t\t\t\t\tEnter the cloth Size:" ;
		cin >> size;
		int i = Frock_list.searchClothsBySize(size);
		int j = Trouser_list.searchClothsBySize(size);
		int w = Skirt_list.searchClothsBySize(size);
		int l = Blouse_list.searchClothsBySize(size);
		if (i != -1)
		{
			cout << "\n\t\t\t\t\tItem Available in the Frock List..." << endl;
		}
		else
		{
			cout << "\t\t\t\t\tItem is not Available in the Frock List...!" << endl;
		}

		if (j != -1)
		{
			cout << "\t\t\t\t\tItem Available in the Trouser List..." << endl;
		}
		else
		{
			cout << "\t\t\t\t\tItem is not Available in the Trouser List...!" << endl;
		}
		if (w != -1)
		{
			cout << "\t\t\t\t\tItem Available in the Skirt List..." << endl;
		}
		else
		{
			cout << "\t\t\t\t\tItem is not Available in the Skirt List...!" << endl;
		}
		if (l != -1)
		{
			cout << "\t\t\t\t\tItem Available in the Blouse List..." << endl;
		}
		else
		{
			cout << "\t\t\t\t\tItem is not Available in the Blouse List...!" << endl;
		}

		cout << "-> Press (0) go to Back" << endl;
		int k;
		cin >> k;
		if (k == 0) {
			system("cls");
			return Ownerwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
		}
		else {
			system("cls");
			return Ownerwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
		}
	}
	//view all items
	else if (choice03 == 7) {
		system("cls");
		cout << "\n\t\t\t\t\t\t-------------" << endl;
		cout << "\t\t\t\t\t\t  ALL ITEMS" << endl;
		cout << "\t\t\t\t\t\t-------------" << endl;
		cout << endl;
		

			cout << "----------------------------------------------- |Frock List| --------------------------------------------------------" ;
			cout << endl;
			Frock_list.printCloths();
			cout << endl;

			cout << "---------------------------------------------- |Trouser List| --------------------------------------------------------";
			cout << endl;
			Trouser_list.printCloths();
			cout << endl;

			cout << "----------------------------------------------- |Skirt List| --------------------------------------------------------" ;
			cout << endl;
			Skirt_list.printCloths();
			cout << endl;

			cout << "----------------------------------------------- |Blouse List| --------------------------------------------------------";
			cout << endl;
			Blouse_list.printCloths();
			cout << endl;

		
		cout << "-> Press (0) go to Back" << endl;
		int k;
		cin >> k;
		if (k == 0 ) {
			system("cls");
			return Ownerwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
		}
		else {
			system("cls");
			return Ownerwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
		}
	}

	//view all customers
	else if (choice03 == 8) {
		newcustomerlist.printAllcustomer();
		
		int k;
		cout << "-> Press (0) go to Back" << endl;
		cin >> k;
		if (k == 0) {
			system("cls");
			return Ownerwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
		}
		else {
			system("cls");
			return Ownerwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
		}
	}

	//search customer by username
	else if (choice03 == 9) {
		cout << "\t\t\t\t\tEnter the Username:\t" ;
		string Name;
		cin >> Name;

		int n = newcustomerlist.searchCustomerByusername(Name);
		if (n != -1) {
			cout << "\t\t\t\t\tCustomer is Found..." << endl;
		}
		else {
			cout << "\t\t\t\t\tCustomer cannot Find...!" << endl;
		}
		cout << "-> Press (0) go to Back" << endl;
		int k;
		cin >> k;
		if (k == 0) {
			system("cls");
			return Ownerwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
		}
		else {
			system("cls");
			return Ownerwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
		}
	}
	else if (choice03 == 10) {
		
	
		orderslist.printCOD();
		orderslist.printCP();
		cout << "-> Press (0) go to Back" << endl;
		int k;
		cin >> k;
		if (k == 0) {
			system("cls");
			return Ownerwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
		}
		else {
			system("cls");
			return Ownerwindow(newcustomerlist, Skirt_list, Frock_list, Trouser_list, Blouse_list, orderslist);
		}

	}

	else if (choice03 == 11) {
	
		return;

	}
	return;
}
