class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int max_substring = 0;

        unordered_set<char> set;

        int left = 0;
        for(int right = 0;right < s.size();right++){

            while(set.count(s[right])){
                set.erase(s[left]);
                left++;
            }

            set.insert(s[right]);
            max_substring = max(max_substring,right - left + 1);
        }

        return max_substring;
    }
};