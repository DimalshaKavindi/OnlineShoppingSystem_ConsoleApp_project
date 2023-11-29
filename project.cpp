#include <iostream>
#include <cstddef>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
#include "Main_window.h"

using namespace std;
#include "Customer_Info_Linkedlist.h"
#include "Cloths_info_Linkedlist.h"
#include "Administrator.h"
#include "Orders_queue.h"


int main()
{
    Customer_List newcustomerlist;
    ClothsList Frock_list;
    ClothsList Trouser_list;
    ClothsList Skirt_list;
    ClothsList Blouse_list;
    OrdersQueue orderslist(1000);
    
    
    cout << endl;
    cout << "------------------------------------------------ASB Shopping Centre------------------------------------------\n\n";
    cout << "                                                +-----------------+                                          \n";
    cout << "                                                |   Welcome to    |                                          \n";
    cout << "                                                | Online Shopping |                                          \n";
    cout << "                                                |     Centre      |                                          \n";
    cout << "                                                +-----------------+                                          \n\n";

    Cloths cloth1;
    cloth1.Id = 1000;
    cloth1.cloth_name = "Frock";
    cloth1.colour = "pink";
    cloth1.size_of_cloth = "xs";
    cloth1.stock = 100;
    cloth1.price = 1950;

    Cloths cloth2;
    cloth2.Id = 1001;
    cloth2.cloth_name = "Frock";
    cloth2.colour = "red";
    cloth2.size_of_cloth = "M";
    cloth2.stock = 150;
    cloth2.price = 900;

    Cloths cloth3;
    cloth3.Id = 1002;
    cloth3.cloth_name = "Trouser";
    cloth3.colour = "gray";
    cloth3.size_of_cloth = "xs";
    cloth3.stock = 450;
    cloth3.price = 4000;

    Cloths cloth4;
    cloth4.Id = 1003;
    cloth4.cloth_name = "Skirt";
    cloth4.colour = "pink";
    cloth4.size_of_cloth = "s";
    cloth4.stock = 200;
    cloth4.price = 1100;

    Cloths cloth5;
    cloth5.Id = 1004;
    cloth5.cloth_name = "Blouse";
    cloth5.colour = "blue";
    cloth5.size_of_cloth = "s";
    cloth5.stock = 150;
    cloth5.price = 900;

    Cloths cloth6;
    cloth6.Id = 1005;
    cloth6.cloth_name = "Trouser";
    cloth6.colour = "black";
    cloth6.size_of_cloth = "M";
    cloth6.stock = 350;
    cloth6.price = 1150;

    Cloths cloth7;
    cloth7.Id = 1006;
    cloth7.cloth_name = "Frock";
    cloth7.colour = "yellow";
    cloth7.size_of_cloth = "s";
    cloth7.stock = 200;
    cloth7.price = 2900;

    Cloths cloth8;
    cloth8.Id = 1007;
    cloth8.cloth_name = "Blouse";
    cloth8.colour = "white";
    cloth8.size_of_cloth = "xs";
    cloth8.stock = 150;
    cloth8.price = 900;

    Cloths cloth9;
    cloth9.Id = 1008;
    cloth9.cloth_name = "Skirt";
    cloth9.colour = "pink";
    cloth9.size_of_cloth = "s";
    cloth9.stock = 250;
    cloth9.price = 2000;


    Frock_list.addCloths(cloth1);
    Frock_list.addCloths(cloth2);
    Frock_list.addCloths(cloth7);
    Trouser_list.addCloths(cloth2);
    Trouser_list.addCloths(cloth3);
    Trouser_list.addCloths(cloth6);
    Skirt_list.addCloths(cloth4);
    Skirt_list.addCloths(cloth9);
    Blouse_list.addCloths(cloth5);
    Blouse_list.addCloths(cloth8);

    Customer customer1;
    customer1.Name = "kasuni";
    customer1.Username = "kasuni123";
    customer1.Password = "k123";
    

    Customer customer2;
    customer2.Name = "prasadi";
    customer2.Username = "prasadi123";
    customer2.Password = "p123";

    Customer customer3;
    customer3.Name = "amandi";
    customer3.Username = "ama123";
    customer3.Password = "a123";

    newcustomerlist.Add_Customer(customer1);
    newcustomerlist.Add_Customer(customer2);
    newcustomerlist.Add_Customer(customer3);

    Mainwindow(newcustomerlist , Skirt_list,  Frock_list, Trouser_list, Blouse_list, orderslist);
}
