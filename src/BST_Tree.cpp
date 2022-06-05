#include "BST_Tree.h"
#include "Hashtable.h"

BST_Tree::BST_Tree(){

}

void BST_Tree::Add_Account(string name, string address, int accountno, int password, int balance)
{
    h.Add(accountno, password);
    ofstream write;
    write.open("../src/server.txt", ios::app);
    write << name << endl << address << endl << accountno << endl << password << endl << balance << endl;
    write.close();
    BST_Node* temp = new BST_Node(name, address, accountno, password, balance);

    BST_Node* current = root;
    if(root == nullptr){
        root = temp;
    }
    else{
        while(true){
            if(accountno < current->account_number){
                if(current->left == nullptr){
                    current->left = temp;
                    break;
                }
                current = current->left;
            }
            if(accountno > current->account_number){
                if(current->right == nullptr){
                    current->right = temp;
                    break;
                }
                current = current->right;
            }
        }
    }
}

BST_Node* BST_Tree::Delete_Account(BST_Node* root, int accountno)
{
    if(root == nullptr){
        cout << "The tree is empty or you have entered the wrong data." << endl;
    }
    else if(accountno < root->account_number){
        root->left = Delete_Account(root->right, accountno);
    }
    else{
        if(root->left && root->right){
            FindMax(root->left);
            root->account_number = v.back();
            root->left = Delete_Account(root->left, root->account_number);
        }
        else{
            cout << "aya" << endl;
            BST_Node* temp = root;
            if(root->left == nullptr){
                root = root->right;
            }
            else if(root->right == nullptr){
                root = root->left;
            }
            delete temp;
        }
    }
    return(root);
}

void BST_Tree::Withdraw(int accountno, int amount)
{
    LoadServer();
    BST_Node *temp = Search(root, accountno);
    temp->balance = temp->balance-amount;
    vector <int> data;
    ifstream read;
    read.open("../src/transaction.txt", ios::app);

    int line = 0;
    while(!read.eof()){
        read >> line;
        if(line == accountno){
            data.push_back(line);
            line = (amount*-1);
            data.push_back(line);
            continue;
        }
        data.push_back(line);
    }
    read.close();

    ofstream write;
    write.open("../src/temp.txt", ios::app);
    for(int i = 0; i < data.size(); i++){
        write << data[i] << endl;
    }
    write.close();
    remove("../src/transaction.txt");
    rename("../src/temp.txt", "../src/transaction.txt");

    UpdateServer(root);
}

void BST_Tree::Deposit(int accountno, int amount)
{
    LoadServer();
    BST_Node *temp = Search(root, accountno);
    temp->balance = temp->balance + amount;

    vector<int> data;
    ifstream read;
    read.open("../src/transaction.txt", ios::app);

    int line = 0;
    while(!read.eof()){
        read >> line;
        if(line == accountno){
            data.push_back(line);
            line = amount;
            data.push_back(line);
            continue;
        }
        data.push_back(line);
    }
    read.close();

    ofstream write;
    write.open("../src/temp.txt", ios::app);
    for(int i = 0; i < data.size(); i++){
        write << data[i] << endl;
    }
    write.close();
    remove("../src/transaction.txt");
    rename("../src/temp.txt", "../src/transaction.txt");

    UpdateServer(root);
}

void BST_Tree::EditAccountByAdmin()
{

}

void BST_Tree::Transfer(int sender_accountno, int reciever_accountno, int sender_amount)
{
    BST_Node *sender = Search(root, sender_accountno);
    sender->balance = sender->balance - sender_amount;
    BST_Node *reciever = Search(root, reciever_accountno);
    reciever->balance = reciever->balance + sender_amount;
    UpdateServer(root);

    vector <int> data;
    ifstream read;
    read.open("../src/transaction.txt", ios::app);

    int line = 0;
    while(!read.eof()){
        read >> line;
        if(line == sender_accountno){
            data.push_back(line);
            line = (sender_amount* - 1);
            data.push_back(line);
            continue;
        }
        data.push_back(line);
    }
    read.close();

    ofstream write;
    write.open("../src/temp.txt", ios::app);
    for(int i = 0; i < data.size(); i++){
        write << data[i] << endl;
    }
    write.close();
    remove("../src/transaction.txt");
    rename("../src/temp.txt", "../src/transaction.txt");

    vector<int> data_reciever;
    ifstream read_reciever;
    read_reciever.open("../src/transaction.txt", ios::app);
    int line_reciever = 0;
    while(!read_reciever.eof()){
        read_reciever >> line_reciever;
        if(line_reciever == reciever_accountno){
            data_reciever.push_back(line_reciever);
            line_reciever = sender_amount;
            data_reciever.push_back(line_reciever);
            continue;
        }
        data_reciever.push_back(line_reciever);
    }
    read.close();

    ofstream write_reciever;
    write_reciever.open("../src/temp.txt", ios::app);
    for(int i = 0; i < data_reciever.size(); i++){
        write_reciever << data_reciever[i] << endl;
    }
    write_reciever.close();
    remove("../src/transaction.txt");
    rename("../src/temp.txt", "../src/transaction.txt");
}

void BST_Tree::TransactionHistory()
{

}

void BST_Tree::FindMax(BST_Node * r)
{
    if(r){
        FindMax(r->left);
        v.push_back(r->account_number);
        FindMax(r->right);
    }
}

void BST_Tree::LoadServer()
{
    ifstream read;
    read.open("../src/server.txt", ios::app);

    string name = "";
    string address = "";
    int accountno = 0;
    int password = 0;
    int balance = 0;

    while(!read.eof()){
        getline(read, name);
        getline(read, address);
        read >> accountno;
        read >> password;
        read >> balance;
        read.ignore();
        read.ignore();

        if(name != "" && address != "" && accountno != 0 && password != 0){
            BST_Node *temp = new BST_Node(name, address, accountno, password, balance);
            BST_Node *current = root;
            if(root = nullptr){
                root = temp;
            }
            else{
                while(true){
                    if(accountno < current->account_number){
                        if(current->left == nullptr){
                            current->left = temp;
                            break;
                        }
                        current = current->left;
                    }
                    if(accountno > current->account_number){
                        if(current->right == nullptr){
                            current->right = temp;
                            break;
                        }
                        current = current->right;
                    }
                    if(accountno == current->account_number){
                        break;
                    }
                }
            }
        }
    }
    read.close();
}

void BST_Tree::UpdateServer(BST_Node *r)
{
    static int i = 0;
    if(i == 0){
        i++;
        remove("../src/server.txt");
    }
    ofstream write;
    write.open("../src/server.txt");
    if(r){
        UpdateServer(r->left);
        write << r->name << endl;
        write << r->address << endl;
        write << r->account_number<< endl;
        write << r->password << endl;
        write << r->balance << endl;
        UpdateServer(r->right);
    }
    write.close();
}

BST_Node* BST_Tree::Search(BST_Node* r, int accountno)
{
    if(r == nullptr)
        return (nullptr);
    else if (accountno < r->account_number)
        return (Search(r->left, accountno));
    else if (accountno > r->account_number)
        return (Search(r->right, accountno));
    return (r);
}

void BST_Tree::PrintInfo(BST_Node *r)
{
    if(r){
        PrintInfo(r->left);
        cout << r->name << endl;
        cout << r->address << endl;
        cout << r->account_number << endl;
        cout << r->password << endl;
        cout << r->balance << endl;
        PrintInfo(r->right);
    }
}