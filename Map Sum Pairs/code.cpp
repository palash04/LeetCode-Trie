#include <bits/stdc++.h>
using namespace std;
#define alpha 26

class MapSum {
    struct TrieNode{
        TrieNode *children[alpha];
        int val;
        bool isEndOfWord;
    };
    TrieNode *root;
    unordered_set<string> st;
public:
    TrieNode *getNode(){
        TrieNode *node = new TrieNode;
        for (int i=0;i<alpha;i++){
            node->children[i] = NULL;
        }
        node->isEndOfWord = false;
        node->val = 0;
        return node;
    }
    MapSum() {
        root = getNode();
    }
    
    void insert(string key, int val) {
        TrieNode *tnode = root;
        bool key_exist = false;
        if (st.find(key) != st.end()){
            key_exist = true;
        }
        st.insert(key);
        for (int i=0;i<key.size();i++){
            int index = key[i] - 'a';
            if (!tnode->children[index]){
                tnode->children[index] = getNode();
            }
            tnode = tnode->children[index];
            if (key_exist){
                tnode->val = val;
            }else{
                tnode->val += val;
            }
        }
        tnode->isEndOfWord = true;
    }
    
    int sum(string prefix) {
        int sum = 0;
        TrieNode *tnode = root;
        bool found = true;
        for (int i=0;i<prefix.size();i++){
            int index = prefix[i] - 'a';
            if (tnode->children[index]){
                tnode = tnode->children[index];
            }else{
                found = false;
                break;
            }
        }
        if (found) sum = tnode->val;
        return sum;
    }
};
