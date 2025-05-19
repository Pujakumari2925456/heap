//merge two binary heap
//link=>https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1?page=1&difficulty%5B%5D=0&category%5B%5D=Heap&sortBy=submissions
class Solution {
    void heapify(vector<int>&arr,int n,int i){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left>0 && left<n && arr[largest]<arr[left])largest=left;
        if(right>0 && right<n && arr[largest]<arr[right])largest=right;
        if(largest!=i){
            swap(arr[i],arr[largest]);
            heapify(arr,n,largest);
        }
    }
  public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        //dono array ko jodod normally ek k piche ek
        //heapsort kardo uska=>heapsort has 2 steps=>
        //1)convert in maxheap2) than heapify it
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(a[i]);
        }
        for(int i=0;i<m;i++){
            ans.push_back(b[i]);
        }
        int k=ans.size();
        for(int i=k/2-1;i>=0;i--){
            heapify(ans,k,i);
        }
        //  for(int i=k-1;i;i++){
        //     swap(ans[0],ans[i]);
        //     heapify(ans,0,i);
        // }
        return ans;
    }
};