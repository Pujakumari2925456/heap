//qn=>https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1?page=1&difficulty%5B%5D=1&category%5B%5D=Heap&sortBy=submissions
// Is Binary Tree Heap
// Difficulty: MediumAccuracy: 34.41%Submissions: 130K+Points: 4
// You are given a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.

// A binary tree is considered a max-heap if it satisfies the following conditions:

// Completeness: Every level of the tree, except possibly the last, is completely filled, and all nodes are as far left as possible.
// Max-Heap Property: The value of each node is greater than or equal to the values of its children.
// Examples:

// Input: root[] = [97, 46, 37, 12, 3, 7, 31, 6, 9]
 
// Output: true
// Explanation: The tree is complete and satisfies the max-heap property.
// Input: root[] = [97, 46, 37, 12, 3, 7, 31, N, 2, 4] 
 
// Output: false
// Explanation: The tree is not complete and does not follow the Max-Heap Property, hence it is not a max-heap.
// Constraints:
// 1 ≤ number of nodes ≤ 103
// 1 ≤ node->data ≤ 103

// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
    int count(Node*temp){
        if(!temp)return 0;
        return 1+count(temp->left)+count(temp->right);
    }
    // bool cbt(Node*temp,int total,int index){
    //   if(index>=total)return false;
    //   cbt(temp->left,total,2*index+1);
    //   cbt(temp->right,total,2*index+2);
    //   return true;
    // }
     bool cbt(Node* temp, int total, int index){
        if (!temp) return true; // NULL is valid in CBT check
        if (index >= total) return false;
        return cbt(temp->left, total, 2 * index + 1) &&
               cbt(temp->right, total, 2 * index + 2);
    }
    // bool check(Node* temp){
    //   if(temp->left && temp->data<temp->left->data || temp->right && temp->data<temp->right->data){
    //       return false;
    //   }
      
    //   return(check(temp->left) && check(temp->right));
    //   return true;
    // }
    bool check(Node* temp) {
    if (!temp) return true;

    if (temp->left && temp->data < temp->left->data) return false;
    if (temp->right && temp->data < temp->right->data) return false;

    return check(temp->left) && check(temp->right);
}

  public:
    bool isHeap(Node* tree) {
        // code here
        Node* temp=tree;
        int total=count(temp);
        if(!cbt(temp,total,0))return false;
        if(!check(temp))return false;
        else{
            return true;
        }
        
    }
};