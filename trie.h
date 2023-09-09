#include <bits/stdc++.h>

using namespace std;

class Node{
    public:

    char data;

    bool end;

    char getData(){
        return this->data;
    }

    Node * array[26] = {};

    Node(char data){
        this->data = data;
        this->end = false;
    }
    Node(){
        this->data = '\0';
        this->end = false;
    }

};

class trie{
    public:
    Node * head;

    trie(){
        head = new Node();
    }

    void insert(string);

    void insertAux(string, int, Node*);

    void show(Node *, string);

};