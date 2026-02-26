class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int> ransomNote_count(26,0);
        vector<int> magazine_count(26,0);

        for(int i = 0;i < max(ransomNote.size(),magazine.size());i++){

            if (i < ransomNote.size()){
                ransomNote_count[ransomNote[i] - 'a']++;
            }
            if (i < magazine.size()){
                magazine_count[magazine[i] - 'a']++;
            }
        }

        for(int i = 0;i < 26;i++){
            if (ransomNote_count[i] > magazine_count[i]) return false;
        }
        
        return true;
    }
};