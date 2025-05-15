
// User function Template for C++

class Solution {
  public:
    int heapHeight(int N, int arr[]) {
        // code here
        // 2^height=n
        int height=0;
        if(N==1)return 1;
       while(N>1){
           height++;
           N/=2;
       }
        return height;
        
    }
};