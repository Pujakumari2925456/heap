//link=>https://www.geeksforgeeks.org/problems/bst-to-max-heap/1?page=1&difficulty%5B%5D=1&category%5B%5D=Heap&sortBy=submissions
//bst to max heap
//jo diya h uska inorder nikal k array m daalo phir us array ka postorder is the answer

class Solution {
    void inorder(Node* root,vector<int>&ans1){
        if(!root)return;
        inorder(root->left,ans1);
        ans1.push_back(root->data);
        inorder(root->right,ans1);
        
    }
    void postorder(Node* root,vector<int>&ans1,int &index){
        if(!root)return;
        postorder(root->left,ans1,index);
        postorder(root->right,ans1,index);
        root->data=ans1[index++];
      
    }
  public:
    void convertToMaxHeapUtil(Node* root) {
        // Your code goes here
        vector<int>ans1;
        inorder(root,ans1);
        int index=0;
        postorder(root,ans1,index);
    }
};
