#include <iostream>
#include "Hashtable.h"
#include <vector>
using namespace std;

Hashtable::Hashtable()
{
    start = nullptr;
}

void Hashtable::Starthash()
{
    for(int i = 0; i<12; i++){

        Node *temp1 = new Node(i);
        if(start == nullptr){
            start = temp1;
        }
        else{
            Node *current = start;
            while(current->next != nullptr){
                current= current->next;
            }
            current->next = temp1;
        }
    }
    Loadhashtable();
}

void Hashtable::Add(int a, int p)
{
    static int i = 0;
    ofstream write;
    write.open("hashtable.txt", ios::app);
    if(i != 0){
        write << endl;
        write << a <<endl << p;
    }
    else{
        i++;
        write << endl << p;
    }

    write.close();
    Starthash();
}

bool Hashtable::Match(int a, int p)
{
    bool flag = false;
    int r = a %10;
    Node *c = start;
    while(c->data != r){
        c = c->next;
    }

    Node_1 *c1 = c->pre;
    while(c1 != nullptr){
        if(c1->accountNumber == a && c1->password == p){
            flag = true;
            break;
        }
        c1 = c1->next;
    }
    return flag;
}

void Hashtable::Display()
{
    Node *current = start;
    while(current != nullptr){
        cout << current->data << endl;
        current = current->next;
    }
}

void Hashtable::Loadhashtable()
{
    int acc = 0, r, pass;
    ifstream read;
    read.open("../src/hashtable.txt");
    while(!read.eof()){
        read >> acc;
        read >> pass;
        if(Match(acc,pass)){
            continue;
        }
        if(acc != -858993460 && pass != -858993460){
            r = acc % 10;

            Node *c = start;
            while(c->data != r){
                c = c->next;
            }

            Node_1 *temp = new Node_1(acc, pass);
            if(c->pre == nullptr){
                c->pre = temp;
            }
            else{
                Node_1 *root;
                root = c->pre;
                while(root->next != nullptr){
                    root = root->next;
                }
                root->next = temp;
            }
        }
        else{
            cout << "No password present" << endl;
        }
    }
    read.close();
}

void Hashtable::DisplayPasswords()
{
    Starthash();
    Node *c = start;
    while(c != nullptr){

        Node_1 *c1 = c->pre;
        while(c1 != nullptr){
            cout << c1->accountNumber << endl;
            cout << c1->password << endl << endl;
            c1 = c1->next;
        }
        c = c->next;
    }
}

void Hashtable::DeletePassword(int accountno)
{
    ifstream read;
    read.open("hashtable.txt");
    vector<int> v;
    int acc=0,pass=0;
    int j = 0;
    while(!read.eof()){
        j++;
        read >> acc;
        read >> pass;

        if(acc == accountno){
            continue;
        }
        v.push_back(acc);
        v.push_back(pass);
    }
    read.close();
    ofstream write;
    write.open("temp.txt", ios::app);
    for(int i = 0; i < v.size(); i++){
        if(v[i] != 0){
            write << v[i] << endl;
        }
    }
    write.close();
    remove("hashtable.txt");
    rename("temp.txt", "hashtable.txt");
}