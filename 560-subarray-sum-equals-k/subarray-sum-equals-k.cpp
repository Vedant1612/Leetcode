class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0]++;
        int n = nums.size();
        int cnt = 0;
        int prefixSum = 0;
        for(int i=0; i<n; i++){
            prefixSum += nums[i];
            int target = prefixSum - k;
            if(mp.find(target)!=mp.end()){
                cnt += mp[target];
            }
            mp[prefixSum]++;
        }
        return cnt;
    }
};