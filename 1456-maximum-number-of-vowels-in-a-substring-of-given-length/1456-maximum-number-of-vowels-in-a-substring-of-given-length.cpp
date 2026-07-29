class Solution {
public:

    bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    int maxVowels(string s, int k) {
        
        int max_ = 0;

        int curr_count = 0;

        for(int i = 0;i < k;i++) curr_count += isVowel(s[i]);

        max_ = max(max_,curr_count);

        int left = 1;
        int right = k;

        while(right < s.size()){

            curr_count += isVowel(s[right]);
            curr_count -= isVowel(s[left - 1]);
            
            max_ = max(max_,curr_count);

            left++;
            right++;
        }

        return max_;
    }
};