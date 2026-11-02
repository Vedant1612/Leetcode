class Solution {
public:
    int atMost(vector<int>& nums, int k){
        int n = nums.size();
        int left = 0;
        map<int, int>mapp;

        int ans = 0;
        for(int right = 0; right <n; right++){
            mapp[nums[right]]++;
            while(mapp.size() > k){
                mapp[nums[left]]--;
                if(mapp[nums[left]] == 0){
                    mapp.erase(nums[left]);
                }
                left++;
            }
            ans += right - left +1;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return atMost(nums, k) - atMost(nums,k-1);
    }
};