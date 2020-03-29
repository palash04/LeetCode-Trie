#include <bits/stdc++.h>
using namespace std;
#define alpha 26

class Solution {
    struct TrieNode{
        TrieNode *children[alpha];
        bool isEndOfWord;
    };
    string max_res = "";
public:
    
    TrieNode *getNode(){
        TrieNode *node = new TrieNode;
        for (int i=0;i<alpha;i++){
            node->children[i] = NULL;
        }
        node->isEndOfWord = false;
        return node;
    }
    
    void insert(TrieNode *root, string word){
        int n = (int)word.size();
        TrieNode *tnode = root;
        if (n == 1){
            int index = word[0] - 'a';
            if (!tnode->children[index]){
                tnode->children[index] = getNode();
            }
            tnode = tnode->children[index];
            tnode->isEndOfWord = true;
            return;
        }
        for (int i=0;i<n-1;i++){
            int index = word[i] - 'a';
            if (!tnode->children[index]){
                return;
            }
            tnode = tnode->children[index];
        }
        int index = word[n-1] - 'a';
        tnode->children[index] = getNode();
        tnode = tnode->children[index];
        tnode->isEndOfWord = true;
    }
    
    void findLongestWord(TrieNode *root,string res){
        
        if (root->isEndOfWord){
            if (res.size() > max_res.size()){
                max_res = res;
            }
        }
        
        for (int i=0;i<alpha;i++){
            if (root->children[i]){
                res += i+'a';
                findLongestWord(root->children[i], res);
                res.pop_back();
            }
        }
    }
    
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        TrieNode *root = getNode();
        for (int i=0;i<words.size();i++){
            string word = words[i];
            insert(root, word);
        }
        
        findLongestWord(root, "");
        return max_res;
    }
};
