#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

class Node{
    public:
    unordered_map<char,Node*>children;
    bool endOfWord;
    Node(){
        endOfWord = false;
    }
};

class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
    }

    //insertion
    void insert(string key){
        Node* temp = root;
        for(int i = 0; i<key.size(); i++){
            if(temp->children[key[i]] == 0){
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->endOfWord = false;
    }
};

int main(){
    vector<string>words = {"the","a","there","any","thee"};
    Trie trie;

    return 0;
}