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
        temp->endOfWord = true;
    }

    //search 
    bool search(string key){
        Node* temp = root;
        for(int i = 0; i<key.size(); i++){
            if(temp->children.count(key[i])){
                temp = temp->children[key[i]];
            }else{
                return false;//not found 
            }
        }

        return temp->endOfWord;
    }
};

string isPresent(bool x){
    return x==true?"yes, it is present in the trie.":"No, it isn't present in the trie";
}

int main(){
    vector<string>words = {"the","a","there","any","thee"};
    Trie trie;

     //insertion 
    for(int i = 0; i<words.size(); i++){
        trie.insert(words[i]);
    }

    //search -> return true/false
    cout<<"'there' is present in the trie ?  :\n -> " <<isPresent(trie.search("there"));
    cout<<"\n'thin' is present in the trie ?  \n: -> "<<isPresent(trie.search("thin"));

    return 0;
}