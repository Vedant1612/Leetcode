class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.size();
        int mod=1e9+7;
        vector<long long> frq(26,0);
        vector<int> dp(n);
        dp[n-1]=1;
        frq[s[n-1]-'a']++;
        for(int i=n-2;i>=0;--i){
            if(!frq[s[i]-'a']){
                dp[i]=(1+2LL*dp[i+1])%mod;
            }
            else{
                dp[i]=(1+2LL*dp[i+1] - frq[s[i]-'a'] + mod)%mod;
            }
            frq[s[i]-'a']=(frq[s[i]-'a'] + dp[i]-dp[i+1] + mod)%mod;
        }
        return dp[0];
    }
};