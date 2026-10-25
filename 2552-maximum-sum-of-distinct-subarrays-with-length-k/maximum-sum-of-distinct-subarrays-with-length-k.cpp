class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;

        long long windowSum = 0;
        long long maxWindowSum = 0;

        for(int i = 0; i < k; i++) {
            windowSum += nums[i];
            freq[nums[i]]++;
        }

        if(freq.size() == k) {
            maxWindowSum = windowSum;
        }

        for(int i = k; i < n; i++) {
            windowSum += nums[i];
            freq[nums[i]]++;

            windowSum -= nums[i-k];
            freq[nums[i-k]]--;

            if(freq[nums[i-k]] == 0) {
                freq.erase(nums[i-k]);
            }

            if(freq.size() == k) {
                maxWindowSum = max(maxWindowSum, windowSum);
            }
        }

        return maxWindowSum;
    }
};