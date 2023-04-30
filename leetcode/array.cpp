#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class ArraySolutions {
   public:
    // 217. Contains Duplicate
    bool containsDuplicate(vector<int>& nums, int algorithm = 3) {
        // 1. O(n^2)
        if (algorithm == 1) {
            for (int i = 0; i < nums.size(); i++) {
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[i] == nums[j]) {
                        return true;
                    }
                }
            }
            return false;
        }
        // 2. O(nlogn)
        if (algorithm == 2) {
            std::sort(nums.begin(), nums.end());  //  Introsort algorithm - O(nlogn)
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] == nums[i + 1]) {
                    return true;
                }
            }
            return false;
        }
        // 3. O(n)
        if (algorithm == 3) {
            std::unordered_set<int> set;
            for (int num : nums) {
                if (set.count(num)) {
                    return true;
                }
                set.insert(num);
            }
            return false;
        }
    }

    // 53. Maximum Subarray
    int maxSubArray(vector<int>& nums, int algorithm = 4) {
        // 1. O(n^3) Brute force
        if (algorithm == 1) {
            int maxSum = INT_MIN;
            for (int i = 0; i < nums.size(); i++) {
                for (int j = i; j < nums.size(); j++) {
                    int sum = 0;
                    for (int k = i; k <= j; k++) {
                        sum += nums[k];
                    }
                    maxSum = max(maxSum, sum);
                }
            }
            return maxSum;
        }
        // O(n^2) Dynamic programming, (time limit exceeded)
        if (algorithm == 2) {
            int maxSum = INT_MIN;
            for (int i = 0; i < nums.size(); i++) {
                int sum = 0;
                for (int j = i; j < nums.size(); j++) {
                    sum += nums[j];
                    maxSum = max(maxSum, sum);
                }
            }
            return maxSum;
        }
        // O(nlogn) Divide and conquer
        if (algorithm == 3) {
            // TODO
        }
        // O(n) Kadane's algorithm
        if (algorithm == 4) {
            int maxSum = nums[0], currSum = nums[0];
            for (int i = 1; i < nums.size(); i++) { 
                currSum = max(nums[i], currSum + nums[i]); // (currSum + next number) vs next number,  max is better choice!
                maxSum = max(maxSum, currSum);
            }
            return maxSum;
        }
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    ArraySolutions s;
    cout << s.maxSubArray(nums);
    return 0;
}