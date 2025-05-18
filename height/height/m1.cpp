
// User function Template for C++
//by video
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


//by other
class Solution {
  public:
    int heapHeight(int N, int arr[]) {
        // code here
        if(N==1) return 1;
        return (int)log2(N);
    }
};
