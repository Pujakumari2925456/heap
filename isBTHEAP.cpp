//is binary traa heap?
//link=>https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1?page=1&difficulty%5B%5D=1&category%5B%5D=Heap&sortBy=submissions

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