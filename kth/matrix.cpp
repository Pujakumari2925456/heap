//link=>https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1?page=1&difficulty%5B%5D=1&category%5B%5D=Heap&sortBy=submissions
// Kth element in Matrix
// Difficulty: MediumAccuracy: 61.42%Submissions: 61K+Points: 4Average Time: 35m
// Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

// Example 1:
// Input:
// N = 4
// mat[][] =     {{16, 28, 60, 64},
//                    {22, 41, 63, 91},
//                    {27, 50, 87, 93},
//                    {36, 78, 87, 94 }}
// K = 3
// Output: 27
// Explanation: 27 is the 3rd smallest element.
//nlogn+n
int kthSmallest(int mat[MAX][MAX], int n, int k) {
    // Your code here
    //1)make a priority queue with element of first column with not O(NLOGN) but
    //in O(N) only 
     //2)while(k--) pop and  and push the popped element j++ column ,return kth elemet
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
     while(--k){
         auto element=p.top();
         int number=element.first;
         int new_i=element.second.first;
         int new_j=element.second.second;
         p.pop();
         if(new_j+1<n)
         p.push({mat[new_i][new_j+1],{new_i,new_j+1}});
     }
     return p.top().first;
}