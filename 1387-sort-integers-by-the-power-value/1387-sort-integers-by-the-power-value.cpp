class Solution {
public:


    int getPower(int n,unordered_map<int,int> &dp){

        if (n == 1) return 0;

        if (dp.count(n)) return dp[n];

        if (n & 1){
            return dp[n] = 1 + getPower(3 * n + 1,dp);
        }

        return dp[n] = 1 + getPower(n / 2,dp);
    }

    int getKth(int lo, int hi, int k) {

        unordered_map<int,int> dp;

        vector<pair<int,int>> powers;

        for(int i = lo;i <= hi;i++){
            powers.push_back({getPower(i,dp),i});
        }

        for(auto i : powers) cout << i.first <<" "<<i.second << endl;

        sort(powers.begin(),powers.end());

        return powers[k - 1].second;
    }
};