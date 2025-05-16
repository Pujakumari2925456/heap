//https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
// Kth Smallest
// Difficulty: MediumAccuracy: 35.17%Submissions: 688K+Points: 4Average Time: 25m
// Given an array arr[] and an integer k where k is smaller than the size of the array, your task is to find the kth smallest element in the given array.

// Follow up: Don't solve it using the inbuilt sort function.

// Examples :

// Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
// Output: 7
// Explanation: 3rd smallest element in the given array is 7.
// Input: arr[] = [2, 3, 1, 20, 15], k = 4 
// Output: 15
// Explanation: 4th smallest element in the given array is 15.
// Constraints:
// 1 <= arr.size <= 106
// 1<= arr[i] <= 106
// 1 <= k <= n

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
         priority_queue<long long> p;

        for(int i=0;i<k;i++){
            p.push(arr[i]);
        }
        ///hamesha utne size ka priority queue banao jitna k h ,ab socho...
        for(int i=k;i<arr.size();i++){
            if(p.top()>arr[i]){
                p.pop();
                p.push(arr[i]);
            }
        }
        return p.top();
    }
};
