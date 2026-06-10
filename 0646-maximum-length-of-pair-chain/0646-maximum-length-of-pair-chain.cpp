class Solution {
public:

    int memo(vector<vector<int>> &pairs,int prev,int curr,vector<vector<int>> &dp){

        if (curr == pairs.size()) return 0;

        if (dp[prev + 1][curr] != -1) return dp[prev + 1][curr];
        //skip 
        int skip = memo(pairs,prev,curr + 1,dp);

        //take if valid
        int take = 0;
        if (prev == -1 || pairs[prev][1] < pairs[curr][0]){
            take = 1 + memo(pairs,curr,curr + 1,dp);
        }

        return dp[prev + 1][curr] = max(skip,take);
    }

    int findLongestChain(vector<vector<int>>& pairs) {

        sort(pairs.begin(),pairs.end());
        vector<vector<int>> dp(pairs.size() + 1,vector<int>(pairs.size(),-1));
        return memo(pairs,-1,0,dp);
    }
};