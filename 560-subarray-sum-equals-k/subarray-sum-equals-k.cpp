class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        for(int left = 0; left<nums.size(); left++){
            int sum = 0;
            for(int right = left; right<nums.size(); right++){
                sum+=nums[right];
                if(sum == k)cnt++;
            }
        }
        return cnt;
    }
};