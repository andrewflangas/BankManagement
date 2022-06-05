#pragma once
#include "BST_Node.h"
#include "Hashtable.h"
#include <stdio.h>

class BST_Tree
{
    vector <int> v;
public:
    BST_Tree();
    BST_Node *Search(BST_Node*, int);
    BST_Node* Delete_Account(BST_Node*, int);
    void Add_Account(string, string, int, int, int);
    void Withdraw(int,int);
    void Deposit(int, int);
    void EditAccountByAdmin();
    void Transfer(int, int, int);
    void TransactionHistory();
    void FindMax(BST_Node*);
    void LoadServer();
    void UpdateServer(BST_Node*);
    void PrintInfo(BST_Node*);

    Hashtable h;
    BST_Node *root;
};