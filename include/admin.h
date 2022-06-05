#pragma once
#include "BST_Tree.h"
#include "Hashtable.h"

void Admin()
{
    BST_Tree t;
    Hashtable h;
    int condition = 0;

    while(condition != 6)
    {
        cout << "Welcome ADMIN" << endl;
        cout << "Choose the following please" << endl;
        cout << "Press 1 to add account " << endl;
        cout << "Press 2 to delete account " << endl;
        cout << "Press 3 to check all accounts " << endl;
        cout << "Press 4 to see password of account " << endl;
        cout << "Press 5 to edit account " << endl;
        cout << "Press 6 to exit" << endl;
        cin >> condition;

        if(condition == 1)
        {
            string n = "", a = "";
            int acc, p, b;

            cout << "Enter name" << endl;
            cin >> n;
            cout << "Enter address" << endl;
            cin >> a;
            cout << "Enter account number" << endl;
            cin >> acc;
            cout << "Enter password" << endl;
            cin >> p;
            cout << "Enter balance" << endl;
            cin >> b;
            t.Add_Account(n, a, acc, p, b);
        }

        if(condition == 2)
        {
            int acc;

            cout << "Enter account number" << endl;
            cin >> acc;

            t.LoadServer();
            t.root = t.Delete_Account(t.root, acc);

            cout << "Delete password" << endl;

            h.DeletePassword(acc);
            t.UpdateServer(t.root);

            cout << "Update" << endl;
        }

        if(condition == 3)
        {
            t.LoadServer();
            t.PrintInfo(t.root);
        }

        if(condition == 4)
        {
            h.DisplayPasswords();
        }

        if(condition == 5)
        {

        }

        if(condition == 6)
        {
            condition = 6;
        }
    }
}