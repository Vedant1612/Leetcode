class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> mapp;
        int cnt = 0;
        int prefixSum = 0;

        mapp[0] = 1;

        for(int i = 0; i < n; i++){
            prefixSum += nums[i];

            int rem = ((prefixSum % k) + k) % k;

            if(mapp.find(rem) != mapp.end()){
                cnt += mapp[rem];
            }

            mapp[rem]++;
        }

        return cnt;
    }
};