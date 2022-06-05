#pragma once
#include "BST_Tree.h"
#include "Hashtable.h"

void Customer()
{
    BST_Tree t;
    Hashtable h;
    int condition = 0;

    while(condition != 3) {
        cout << "Welcome CUSTOMER" << endl;
        cout << "Choose the following please" << endl;
        cout << "Press 1 to see account details" << endl;
        cout << "Press 2 to see transaction history" << endl;
        cout << "Press 3 to exit" << endl;
        cin >> condition;

        if (condition == 1) {
            int accountNo;

            cout << "Please enter account number" << endl;
            cin >> accountNo;

            BST_Node *temp = t.Search(t.root, accountNo);

            cout << "Account details are: \t\t\t\t\t\t" << endl << endl;
            cout << "NAME: " << temp->name << endl;
            cout << "ADDRESS: " << temp->address << endl;
            cout << "ACCOUNT NUMBER: " << temp->account_number << endl;
            cout << "PASSWORD: " << temp->password << endl;
            cout << "BALANCE: " << temp->balance << endl;
        }

        if (condition == 2) {

        }

        if (condition == 3) {
            condition = 3;
        }
    }
}