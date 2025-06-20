//Program to implement Online shopping management

#include <bits/stdc++.h>// include all the header file 

using namespace std;// make all the c++ standard library componments accesible without  the "std:" prefix

using namespace std::this_thread;//provide direct access to thread -related function like sleep_for(), sleep_until

using namespace std::chrono;//This makes all the time related types available
 
map<string,map<string,double>>items;// map is used to store product and brand as key and their price as value

map<pair<int, int>, string> names;//maps s numeric key like(1,2) to a model  name for user friendly selection
 
 
void fillItems()//filling the items with predefined categories and models with prices

{

/*We have chosen category 1 as mobile

                 category 2 as laptop

                 category 3 as course

similarly 1,2,3 in the second part of the key is represent their model                 

*/

    items["Mobile"]["Samsung"] = 15000;

    items["Mobile"]["Redmi"] = 12000;

    items["Mobile"]["Apple"] = 100000;

    items["Laptop"]["HP"] = 40000;

    items["Laptop"]["Lenovo"] = 35000;

    items["Laptop"]["Macbook"] = 250000;

    items["Course"]["C"] = 1000;

    items["Course"]["C++"] = 3000;

    items["Course"]["Java"] = 4000;

    items["Course"]["Python"] = 3500;
 
    names[{ 1, 1 }] = "Apple";

    names[{ 1, 2 }] = "Redmi";

    names[{ 1, 3 }] = "Samsung";

    names[{ 2, 1 }] = "HP";

    names[{ 2, 2 }] = "Lenovo";

    names[{ 2, 3 }] = "Macbook";

    names[{ 3, 1 }] = "C";

    names[{ 3, 2 }] = "C++";

    names[{ 3, 3 }] = "Java";

    names[{ 3, 4 }] = "Python";
 
}
 
 
class customer {

    map<string, map<string, int> > selected_items;// Map to store product-brand as key and their price as value

    string name;//captures customer names

public:

    // constructor

    customer()

    {

        cout << "Enter your name: ";

        string customer_name;

        getline(cin, customer_name);// getline is used to because cin stops reading after 1st white space or tab                                 encountered. It captures full names like " AMAN RAJ".

        name = customer_name;//stores the entered name into the private memeber variable so it can be used at time of                  billing

        cout << "HI "; // personalized greeting

        for (int i = 0; i < customer_name.length(); i++) {// converts each character of the name to uppercase using toupper() and displays it. this is just a visual formatting text.

            cout << char(toupper(customer_name[i]));

        }

        cout << "\n\n\n";

    }


    void addToCart(string a, string b){// function to insert item in the data structure alloted to customer

        selected_items[a][b]++;//selected items is  a map<string, int>> i.e this line increments the quantity 

                                // of selected items by 1for the given category.

    }


    void printBill(){ // function to print the bill during check-out

        int total_amount = 0;// initializes total bill to zero.

        cout << "Category\t"// '\t' is an escape sequence in c++ that represents a horizontal tab.
<< "Item\t"
<< "Quantity\t"
<< "Cost\n";

        map<string, map<string, int> >::iterator itr;// iterators to traverse over respective maps

        map<string, int>::iterator ptr;//ptr iterates through the inner map of models and their quantity
 
        for (itr = selected_items.begin();itr != selected_items.end(); itr++) {//outer loop goes through each category                                                                     (like Mobile, Laptop).

            for (ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {// Inner loop goes through each model                                                                   within that category(eg.,Redmi,                                                                        Macbook).

                string category = itr->first;

                string model = ptr->first;

                int quantity = ptr->second;

                int temp

                    = quantity * items[category][model];

                cout << category << "\t\t" << model << "\t"<< quantity << "\t\t" << temp << endl;//print details of 

                                                                                                 // each item in bill.

                total_amount += temp;//add each item cost in total amount.

            }

        }

        cout << "-------------------------------"<< "-------------\n";

        cout << "Total amount:             \t\t"<< total_amount << endl;

        cout << "-------------------------------"<< "-------------\n";

        cout << "*****THANK YOU && HAPPY"<< " ONLINE SHOPPING*****";

    }

};

// class shop to represent a real world entity - in our case a shop
 
 
//Serve as base class for all product categories

class shop {

public:

    shop() {}//displays available item.

    virtual void show()

    {

        // this will be overridden
 
    }

    virtual void select(customer& obj)

    {

        // this will be overridden

    }

    void showMenu()

    {

        cout << "                 Menu\n";

        cout << " -----------------------------------------"

                "\n";

        cout << "1.Mobile\n2.Laptop\n3"
<< ".Programming Courses\n4.Checkout\n\n";

        cout << " -----------------------------------------"
 
                "\n";

    }

};


// class mobile inheriting properties from class shop

class mobile : public shop {

public:

    void show()

    {

        cout << "- - - - - - - - - - -"
<< " - -\nItem    Cost\n";

        int cnt = 1;

        for (auto& it : items["Mobile"]) {

            cout << cnt++ << ". " << it.first << " --- Rs."<< it.second << "/-\n";

        }   

        cout<< "- - - - - - - - - - - - -\n\n";

    }

    void select(customer& obj)

    {

        cout << "These are the smartphone categories we "

                "have....\n";

        int num;

        cout << "Enter your selection\n";

        cin >> num;

        if (num < 1 || num > 3) {

            cout << "Wrong Input\n";

            return;

        }

        cout << "\n\nPURCHASE SUCCESSFULL!! ";

        cout << names[{ 1, num }]
<< " IS ADDED TO THE CART\n\n";

        obj.addToCart("Mobile", names[{ 1, num }]);

    }

};


// class laptop inheriting properties from class shop

class laptop : public shop {

public:

    void show()

    {

        cout << "- - - - - - - - - - -"<< " - -\nItem    Cost\n";

        int cnt = 1;

        for (auto& it : items["Laptop"]) {

            cout << cnt++ << ". " << it.first << " --- Rs."<< it.second << "/-\n";

        }

        cout << "- - - - - - - - - - - - -\n";

    }

    void select(customer& obj)

    {

        cout << "These are the laptop categories we "

                "have....\n";

        int num;

        cout << "Enter your selection\n";

        cin >> num;

        if (num < 1 || num > 3) {

            cout << "Wrong Input\n";

            return;

        }

        cout << "\n\nPURCHASE SUCCESSFULL!! ";

        cout << names[{ 2, num }]
<< " IS ADDED TO THE CART\n\n";

        obj.addToCart("Laptop", names[{ 2, num }]);

    }

};


// class courses inheriting properties from class shop

class courses : public shop {

public:

    void show()

    {

        cout << "- - - - - - - - - - "
<< " - -\nItem       Cost\n";

        int cnt = 1;

        for (auto& it : items["Course"]) {

            cout << cnt++ << ". " << it.first << " --- Rs."<< it.second << "/-\n";

        }

        cout << "- - - - - - - - - - - - -\n";

    }

    void select(customer& obj)

    {

        cout << "These are the courses categories we "

                "have....\n";

        int num;

        cout << "Enter your selection\n";

        cin >> num;

        if (num < 1 || num > 4) {

            cout << "Wrong Input\n";

            return;

        }

        cout << "\n\nPURCHASE SUCCESSFULL!! ";

        cout << names[{ 3, num }]
<< " IS ADDED TO THE CART\n\n";

        obj.addToCart("Course", names[{ 3, num }]);

    }

};
 
int main()

{

    // filling the hardcoded shop items in the data

    // structure

    fillItems();

    cout << "WELCOME TO OUR SHOP. WE ARE DELIGHTED THAT "

            "YOU ARE HERE. HOW CAN WE HELP YOU? WE DEAL IN "

            "ELECTRONIC GADGETS AND COURSES.\n";

    customer c;

    shop* s;

    while (1) {

        s->showMenu();

        cout
<< "Please select an option to proceed "
 
               "further. If you choose to checkout, "
 
               "shopping will end and bill will be "
 
               "generated for the items bought so far...\n";

        int val;

        cin >> val;

        if (val == 1) {

            mobile mb;

            s = &mb;

            s->show();

            s->select(c);

        }

        else if (val == 2) {

            laptop lp;

            s = &lp;

            s->show();

            s->select(c);

        }

        else if (val == 3) {

            courses cs;

            s = &cs;

            s->show();

            s->select(c);

        }

        else if (val == 4) {

            c.printBill();

            break;

        }

        else {

            cout << "Wrong Input. If you want to checkout, "

                    "you can press 4\n\n";

        }

        cout << "REDIRECTING TO THE MAIN MENU.....\n\n";

        // a function call to add a deliberate delay

        sleep_until(system_clock::now() + seconds(3));

        // clear screen

        system("cls");

    }

    return 0;
 
}

 
