#pragma once
#include "Node.h"
#include "Node_1.h"

class Hashtable
{
    public:
        Hashtable();
        void Starthash();
        void Loadhashtable();
        void Add(int,int);
        bool Match(int,int);
        void Display();
        void DisplayPasswords();
        void DeletePassword(int);

        Node* start;
};