class Solution {
public:

    bool allDistinct(vector<int> &count){

        int temp = -1;
        for(int i = 0;i < 26;i++){
            if (count[i] != 0){
                if (temp == -1){
                    temp = count[i];
                }
                else if (temp != count[i]) return false;
            }
        }

        return true;
    }

    int longestBalanced(string s) {

        vector<int> count(26,0);
        int max_length = INT_MIN;

        for(int i = 0;i < s.size();i++){

            for(int j = i;j < s.size();j++){

                count[s[j] - 'a']++;

                if (allDistinct(count)){
                    max_length = max(max_length,j - i + 1);
                }
            }

            for(int i = 0;i < 26;i++){
                count[i] = 0;
            }
        }

        return max_length;
    }
};