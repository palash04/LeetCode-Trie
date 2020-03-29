#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct TrieNode{
        TrieNode *left;
        TrieNode *right;
    };
public:
    void insert(TrieNode *root,int n){
        TrieNode *tnode = root;
        for (int i=31;i>=0;i--){
            int b = (n>>i)&1;
            
            if (b == 0){
                if (!tnode->left){
                    tnode->left = new TrieNode();
                }
                tnode = tnode->left;
            }else{
                if (!tnode->right){
                    tnode->right = new TrieNode();
                }
                tnode = tnode->right;
            }
        }
    }

    int findMaxXor(TrieNode *root,vector<int> &nums,int n){
        int max_xor = INT_MIN;
        for (int i=0;i<n;i++){
            TrieNode *tnode =  root;
            int val = nums[i];
            int xor_val = 0;
            for (int j=31;j>=0;j--){
                int b = (val>>j)&1;
                if (b == 0){
                    if (tnode->right){
                        tnode = tnode->right;
                        xor_val += pow(2,j);
                    }else{
                        tnode = tnode->left;
                    }
                }else{
                    if (tnode->left){
                        tnode = tnode->left;
                        xor_val += pow(2,j);
                    }else{
                        tnode = tnode->right;
                    }
                }
            }
            if (xor_val > max_xor) max_xor = xor_val;
        }
        return max_xor;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        TrieNode *root = new TrieNode();
        int n = (int)nums.size();
        for (int i=0;i<n;i++){
            insert(root, nums[i]);
        }
        return findMaxXor(root, nums, n);
    }
};
