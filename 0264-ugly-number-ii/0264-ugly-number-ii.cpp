class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<long long> dp;

        dp.push_back(1);

        int prime2 = 0;
        int prime3 = 0;
        int prime5 = 0;

        for(int i = 1;i < n;i++){

            long long to_push = min({
                dp[prime2] * 2,
                dp[prime3] * 3,
                dp[prime5] * 5
            });

            if (to_push == dp[prime2] * 2) prime2++;
            if (to_push == dp[prime3] * 3) prime3++;
            if (to_push == dp[prime5] * 5) prime5++;

            dp.push_back(to_push);
        }

        return dp.back();
    }
};
