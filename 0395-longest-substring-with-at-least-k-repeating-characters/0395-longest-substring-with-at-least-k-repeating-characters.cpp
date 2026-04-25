class Solution {
public:

    int recursion(string &s,int l,int r,int k){

        vector<int> count(26,0);

        for(int i = l;i <= r;i++){
            char c = s[i];
            count[c - 'a']++;
        }

        for(int i = l;i <= r;i++){

            if (count[s[i] - 'a'] < k){

                int left = recursion(s,l,i - 1,k);
                int right = recursion(s,i + 1,r,k);

                int max_length = std::max(left,right);

                return max_length;
            }
        }

        return r - l + 1;
    }

    int longestSubstring(string s, int k) {
        return recursion(s,0,s.size() - 1,k);
    }
};


/*


a a a b b 

a a c c a a b b b

 k == 2

*/