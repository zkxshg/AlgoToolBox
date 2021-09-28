// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// dfs + preorder traversal

class Codec {
public:
    
    // Encodes a tree to a single string.
    string enc;
    
    void encode(TreeNode* root) {
        if (!root) {
           enc += "#,"; return;
        }
        
        enc += to_string(root->val); enc += ',';
        
        encode(root->left);
        encode(root->right);
    }
    
    
    string serialize(TreeNode* root) {
        enc = "";
        if (!root) return "";
        
        encode(root);
        
        // cout << enc << endl;
        return enc;
    }
    
    // Decodes your encoded data to tree.
    string dec;
    int pos;
    
    bool decode(TreeNode* root) {
        if (pos >= dec.size()) return false;
        
        if (dec[pos] == '#') {
             pos += 2; return false;
        }
        
        int value = 0; bool neg = false;
        
        if (dec[pos] == '-') {
            neg = true; pos++;
        }
         
        while (pos < dec.size() && dec[pos] != ',') {
            value = value * 10 + (dec[pos] - '0'); pos++;
        }
        
        if (neg) value *= -1;
        
        root->val = value; pos++;
        
        TreeNode* ln = new TreeNode(0);
        if (decode(ln)) root->left = ln;
        
        TreeNode* rn = new TreeNode(0);
        if (decode(rn)) root->right = rn;
        
        return true;
    }
    
    TreeNode* deserialize(string data) {
        dec = data; pos = 0;
        
        if (dec.empty()) return NULL;
        
        TreeNode* root = new TreeNode(0);
        
        bool res = decode(root);
        
        return root;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
