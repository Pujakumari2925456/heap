//merge k sorted array
//just like kth =>matrix
//link=>http://geeksforgeeks.org/problems/merge-k-sorted-arrays/1
class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> mat, int K) {
        int n=K;
        vector<int>ans;
        vector< pair<int,pair<int,int>>>v;
         for(int i=0;i<n;i++){
             v.push_back({mat[i][0],{i,0}});
         }
        //  pair<int,pair<int,int>> number,i,j
         priority_queue< 
         pair<int,pair<int,int>>,
         vector< pair<int,pair<int,int>>>,
         greater< pair<int,pair<int,int>>>
         >p(v.begin(),v.end());
         while(!p.empty()){
             auto element=p.top();
             int number=element.first;
             int new_i=element.second.first;
             int new_j=element.second.second;
             ans.push_back(number);
             p.pop();
             if(new_j+1<n)
             p.push({mat[new_i][new_j+1],{new_i,new_j+1}});
     }
        // code here
        return ans;
        
    }
};