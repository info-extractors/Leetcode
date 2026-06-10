class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        

        vector<long long> dp;
        dp.push_back(1);

        vector<int> pointers = vector<int>(primes.size(),0);

        for(int i = 1;i < n;i++){

            // cout << "For i :" << end;
            long long to_push = LLONG_MAX;

            for(int j = 0;j < primes.size();j++){
                to_push = min(to_push,1ll * primes[j] * dp[pointers[j]]); 
                // c
            }

            //once we find minimum 
            dp.push_back(to_push);

            for(int j = 0;j < primes.size();j++){
                if (1ll * primes[j] * dp[pointers[j]] == to_push) pointers[j]++;
            }

            // cout << "------------------------------------------"<<endl << endl;

        }

        return dp.back();
    }
};