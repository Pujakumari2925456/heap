//link=>https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

// You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

// We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

// Example 1:

// Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
// Output: [20,24]
// Explanation: 
// List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
// List 2: [0, 9, 12, 20], 20 is in range [20,24].
// List 3: [5, 18, 22, 30], 22 is in range [20,24].
// Example 2:

// Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
// Output: [1,1]





class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int maximum = INT_MIN, minimum = INT_MAX;

        // Min-heap with (value, (row, col))
        priority_queue< pair<int, pair<int, int>>, 
                        vector< pair<int, pair<int, int>>>, 
                        greater< pair<int, pair<int, int>>> > p;

        // Push the first element of each list
        for (int i = 0; i < nums.size(); i++) {
            p.push({nums[i][0], {i, 0}});
            maximum = max(maximum, nums[i][0]);
        }

        // Initialize answer range
        vector<int> ans = {p.top().first, maximum};

        while (p.size() == nums.size()) {
            auto [val, pos] = p.top(); p.pop();
            int row = pos.first;
            int col = pos.second;

            // Update current range
            if (maximum - val < ans[1] - ans[0]) {
                ans = {val, maximum};
            }

            // Move to next element in the same row
            if (col + 1 < nums[row].size()) {
                int nextVal = nums[row][col + 1];
                p.push({nextVal, {row, col + 1}});
                maximum = max(maximum, nextVal);
            }
        }

        return ans;
    }
};
