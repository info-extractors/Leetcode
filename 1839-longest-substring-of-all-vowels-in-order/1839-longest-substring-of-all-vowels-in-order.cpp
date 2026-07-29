class Solution {
public:
    int longestBeautifulSubstring(string word) {

        int max_length = 0;
        int left = 0;
        int right = 0;


        unordered_set<char> set;

        while(right < word.size()){

            if (right > 0 && word[right] < word[right - 1]){

                if (set.size() == 5){
                    max_length = max(max_length,right - left);
                }

                set.clear();
                left = right;
            }

            set.insert(word[right]);

            right++;
        }

        if (set.size() == 5){
                    max_length = max(max_length,right - left);
        }

        return max_length;
    }
};