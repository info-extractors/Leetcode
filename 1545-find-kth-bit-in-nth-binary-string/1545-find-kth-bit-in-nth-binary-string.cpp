class Solution {
public:

    string invert(string &s){

        string ans = "";

        for(char c : s){
            if (c == '1') ans += '0';
            else ans += '1';
        }

        return ans;
    }

    string Sn(int n){

        if (n == 1){
            return "0";
        }

        string Sn_1 = Sn(n - 1);
        string inverted_Sn_1 = invert(Sn_1);
        reverse(inverted_Sn_1.begin(),inverted_Sn_1.end());

        return Sn_1 + "1" + inverted_Sn_1;
    }

    char findKthBit(int n, int k) {
        return Sn(n)[k-1];
    }
};