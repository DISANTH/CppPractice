#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Codec {

    private:
    std::vector<std::string> split(const std::string str,
                               const std::string regex_str) {
        std::regex regexz(regex_str);
        return {std::sregex_token_iterator(str.begin(), str.end(), regexz, -1),
                std::sregex_token_iterator()};
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string output = "";
        if(root == nullptr)
        {
            return "null";
        }
        q.push(root);
        
        while(!q.empty())
        {
            int processItems = q.size();
            while(processItems > 0)
            {
                if(output.size() > 0)
                {
                    output += ",";
                }
                TreeNode* node = q.front();
                q.pop();
                
                if(node == nullptr)
                {
                    output += "null";
                }
                else{
                    output += std::to_string(node->val);
                    q.push(node->left);
                    q.push(root->right);
                }
                processItems--;
            }
        }
        return output;
    }

    // Decodes your encoded data to tree.
    TreeNode* buildTree(int index, int totalSize, std::vector<std::string> &nodeData)
    {
        
        if(index >= totalSize)
        {
            return nullptr;
        }
        string data = nodeData[index];
        if(data == "null")
        {
            cout << "data is null";
            return nullptr;
        }
        TreeNode* leftNode = buildTree(2*index+1,totalSize, nodeData);
        TreeNode* rightNode = buildTree(2*index+2,totalSize, nodeData);
        TreeNode* root = new TreeNode(stoi(data));
        root->left = leftNode;
        root->right = rightNode;
        return root;
    }
    TreeNode* deserialize(string data) {
        std::vector<std::string> nodeData = split(data,",");
        for(string node:nodeData)
        {
            cout << node << " ";
        }
        return buildTree(0,nodeData.size(),nodeData);
    }

    void inOrder(TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }
        inOrder(root->left);
        cout << " " << root->val;
        inOrder(root->right);
    }
};

int main()
{
    Codec codec;
    TreeNode* root = codec.deserialize("1,2,3,null,null,4,5");
    cout << "deserialize returned :: " << root << endl;
    //codec.inOrder(root);
    cout << codec.serialize(root);
    return 0;
}