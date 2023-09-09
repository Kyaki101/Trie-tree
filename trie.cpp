#include <bits/stdc++.h>

#include "trie.h"

using namespace std;


void trie::insertAux(string word, int index, Node * current){
    if(word[index] == '\0') return;
    if(current->array[word[index]-'a'] == NULL){
        Node * newNode = new Node(word[index]);
        current->array[word[index]-'a'] = newNode;
        if(word[index + 1] == '\0') newNode->end = true;
        insertAux(word, index + 1, newNode);
    }
    insertAux(word, index + 1, current->array[word[index]-'a']);
}

void trie::insert(string word){
    insertAux(word, 0, head);
}

void trie::show(Node * current, string word){
    if(current->end)cout << word << endl;

    for(int i = 0; i < 26; i ++){
        if (current->array[i] != NULL){
            show(current->array[i], word + current->array[i]->data);
        }
    }
}

int main(){
    trie test = trie();

    test.insert("travis");
    test.insert("trap");
    test.insert("apple");
    test.insert("appear");

    test.show(test.head, "");

    return 0;
}