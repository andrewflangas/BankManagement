#include "BST_Node.h"

BST_Node::BST_Node()
{
    left = nullptr;
    right = nullptr;
    name = "";
    address = "";
    account_number = 0;
    password = 0;
    balance = 0;
}

BST_Node::BST_Node(string name, string address, int accountno, int password, int balance)
{
    left = nullptr;
    right = nullptr;
    this->name = name;
    this->account_number = accountno;
    this->address = address;
    this->balance = balance;
    this->password = password;
}