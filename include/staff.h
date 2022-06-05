#pragma once
#include "BST_Tree.h"
#include "Hashtable.h"

void Staff()
{
    BST_Tree t;
    Hashtable h;
    int condition = 0;

    while(condition != 5)
    {
        cout << "Welcome STAFF" << endl;
        cout << "Choose the following please" << endl;
        cout << "Press 1 to see transaction history " << endl;
        cout << "Press 2 to transfer " << endl;
        cout << "Press 3 to withdraw" << endl;
        cout << "Press 4 to deposit" << endl;
        cout << "Press 5 to exit" << endl;
        cin >> condition;

        if(condition == 1)
        {

        }

        if(condition == 2)
        {
            int sendAccNo = 0, amount = 0, recAccNo = 0;

            cout << "Please enter sender account number" << endl;
            cin >> sendAccNo;
            cout << "Please enter receiver account number" << endl;
            cin >> recAccNo;
            cout << "Please enter amount" << endl;
            cin >> amount;

            t.Transfer(sendAccNo, amount, recAccNo);
        }

        if(condition == 3)
        {
            int accountNo = 0, amount = 0;

            cout << "Please enter account number" << endl;
            cin >> accountNo;
            cout << "Please enter amount" << endl;
            cin >> amount;

            t.Withdraw(accountNo, amount);
        }

        if(condition == 4)
        {
            int accountNo = 0, amount = 0;

            cout << "Please enter account number" << endl;
            cin >> accountNo;
            cout << "Please enter amount" << endl;
            cin  >> amount;

            t.Deposit(accountNo, amount);
        }

        if(condition == 5)
        {
            condition = 5;
        }
    }
}