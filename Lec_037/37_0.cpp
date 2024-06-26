// Question Link :- https://leetcode.com/problems/subsets/
// Subsets (Power Set, i.e., subsequence)

// Approach - 1 (Bit manipulation)
// T.C = O(2^n * n)
// S.C = O(1)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0; i<(1<<n); i++) {   // 1<<n = 2^n
            vector<int> output;
            for(int bit=0; bit<n; bit++){
                if(i & (1<<bit)){
                    output.push_back(nums[bit]);
                }
            }
            ans.push_back(output);
        }
        return ans;
    }
};




// Approach - 2 (Using Recursion)
// T.C = O(2^n)
// S.C = O(n)
// The recursion stack space complexity is O(N) , the maximum depth of the recursion is N
class Solution {
    private:
    void solve(vector<int>& nums, int i, vector<vector<int>>& ans, vector<int> output) {
        // base case
        if(i>=nums.size()) {
            ans.push_back(output);
            return;
        }
        // exclude
        solve(nums, i+1, ans, output);

        // include
        output.push_back(nums[i]);
        solve(nums, i+1, ans, output);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(nums, 0, ans, output);
        return ans;
    }
};




// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]


// Input: nums = [0]
// Output: [[],[0]]
