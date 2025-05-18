//link=>https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1?page=1&difficulty%5B%5D=2&category%5B%5D=Heap&sortBy=submissions
// Find median in a stream
class Solution {
    priority_queue<int>LeftMaxHeap;
    priority_queue<int,vector<int>,greater<int>>RightMinHeap;
    void insertHeap(int &x){
        if(LeftMaxHeap.empty()){
            LeftMaxHeap.push(x);
        }
        else{
            if(x>LeftMaxHeap.top()){
                RightMinHeap.push(x);
            }
            else{
                LeftMaxHeap.push(x);
            }
        }
        balanaceHeap();
        
    }
    void balanaceHeap(){
        if(RightMinHeap.size() > LeftMaxHeap.size()){
            LeftMaxHeap.push(RightMinHeap.top());
            RightMinHeap.pop();
        }
        else{
            if(RightMinHeap.size()<LeftMaxHeap.size()-1){
                RightMinHeap.push(LeftMaxHeap.top());
                LeftMaxHeap.pop();
            }
        }
    }
    
  public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double>ans;
        for(int i=0;i<arr.size();i++){
            insertHeap(arr[i]);
        
        if(LeftMaxHeap.size()>RightMinHeap.size()){
            ans.push_back(double(LeftMaxHeap.top()));
        }
        else{
            double m=LeftMaxHeap.top()+RightMinHeap.top();
            m/=2;
            ans.push_back(double(m));
           
        }
    }    
         return ans;
        
    }
};
