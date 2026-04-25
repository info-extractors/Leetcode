class Solution {
public:


    int getPower(int n){

        if (n == 1) return 0;

        if (n & 1){
            return 1 + getPower(3 * n + 1);
        }

        return 1 + getPower(n / 2);
    }

    int getKth(int lo, int hi, int k) {

        vector<pair<int,int>> powers;

        for(int i = lo;i <= hi;i++){
            powers.push_back({getPower(i),i});
        }

        for(auto i : powers) cout << i.first <<" "<<i.second << endl;

        sort(powers.begin(),powers.end());

        return powers[k - 1].second;
    }
};