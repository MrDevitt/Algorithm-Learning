#include<bits/stdc++.h>
using namespace std;

class Trie {
private:
    Trie* next[26];
    bool end;
public:
    /** Initialize your data structure here. */
    Trie() {
        for (int i = 0; i < 26;i++)
            next[i] = NULL;
        end = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node=this;
        for(char c:word){
            if(node->next[c-'a']==NULL){
                node->next[c-'a']=new Trie;
            }
            node=node->next[c-'a'];
        }
        node->end=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node = this;
        for(char c:word){
            if(node->next[c-'a']==NULL)
                return false;
            node = node->next[c - 'a'];
        }
        return node->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *node = this;
        for(char c:word){
            if(node->next[c-'a']==NULL)
                return false;
            node = node->next[c - 'a'];
        }
        return true;
    }
};

int main(){
    Trie t;
    t.insert("seu");
    t.search("seu");
    return 0;
}