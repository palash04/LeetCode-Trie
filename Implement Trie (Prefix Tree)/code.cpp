#include <bits/stdc++.h>
using namespace std;
#define alpha 26

class Trie{
    struct TrieNode{
        TrieNode *children[alpha];
        bool isEndWord;
    };
    TrieNode *root;
public:
    TrieNode *getNode(){
        TrieNode *node = new TrieNode;
        for (int i=0;i<alpha;i++){
            node->children[i] = NULL;
        }
        node->isEndWord = false;
        return node;
    }
    Trie(){
        root = getNode();
    }
    void insert(string word){
        TrieNode *node = root;
        for (int i=0;i<word.size();i++){
            int index = word[i] - 'a';
            if (!node->children[index]){
                node->children[index] = getNode();
            }
            node = node->children[index];
        }
        node->isEndWord = true;
    }
    bool search(string word){
        TrieNode *node = root;
        for (int i=0;i<word.size();i++){
            int index = word[i] - 'a';
            if (!node->children[index]){
                return false;
            }
            node = node->children[index];
        }
        return (node!=NULL && node->isEndWord);
    }
    bool startsWith(string prefix){
        TrieNode *node = root;
        for (int i=0;i<prefix.size();i++){
            int index = prefix[i] - 'a';
            if (!node->children[index]){
                return false;
            }
            node = node->children[index];
        }
        return true;
    }
};
