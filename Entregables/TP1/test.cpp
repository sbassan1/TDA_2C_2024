#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to get all LIS subsequences
vector<vector<int>> findLIS(const vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return {};
    
    // dp[i] stores the length of LIS ending at index i
    vector<int> dp(n, 1);
    
    // subsequences[i] stores all LIS subsequences ending at index i
    vector<vector<vector<int>>> subsequences(n);

    // Initialize subsequences with single elements
    for (int i = 0; i < n; ++i) {
        subsequences[i].push_back({nums[i]});
    }

    int maxLength = 1;

    // Dynamic Programming to build dp array and subsequences
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                maxLength = max(maxLength, dp[i]);
                
                // Clear previous subsequences and update with new ones
                subsequences[i].clear();
                for (const auto& seq : subsequences[j]) {
                    vector<int> newSeq = seq;
                    newSeq.push_back(nums[i]);
                    subsequences[i].push_back(newSeq);
                }
            } else if (nums[i] > nums[j] && dp[i] == dp[j] + 1) {
                // Append subsequences from subsequences[j]
                for (const auto& seq : subsequences[j]) {
                    vector<int> newSeq = seq;
                    newSeq.push_back(nums[i]);
                    subsequences[i].push_back(newSeq);
                }
            }
        }
    }

    // Collect all the subsequences with maxLength
    vector<vector<int>> result;
    for (int i = 0; i < n; ++i) {
        if (dp[i] == maxLength) {
            for (const auto& seq : subsequences[i]) {
                result.push_back(seq);
            }
        }
    }

    return result;
}


int main() {
    vector<int> nums = {7,8,1,2,4,6,3,5,2,1,8,7};

    vector<vector<int>> lisSequences = findLIS(nums);



    cout << "All Longest Increasing Subsequences:" << endl;
    for (const auto& seq : lisSequences) {
        for (int num : seq) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}