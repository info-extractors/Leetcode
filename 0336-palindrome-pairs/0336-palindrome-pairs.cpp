class Solution {
public:

    bool isPalindrome(string &s){

        int left = 0;
        int right = s.size() - 1;

        while(left <= right){

            if (s[left] != s[right]) return false;
            left++;
            right--;
        }

        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        

        //store the string in a hashmap 
        set<vector<int>> ans;
        unordered_map<string,int> map;
        

        for(int i = 0;i < words.size();i++){
            map[words[i]] = i;
        }

        for(int i = 0;i < words.size();i++){

            for(int j = 0;j <= words[i].size();j++){

                string left_part = words[i].substr(0,j);
                string right_part = words[i].substr(j);

                reverse(left_part.begin(),left_part.end());
                if (isPalindrome(right_part) && map.find(left_part) != map.end()){
                    if (map[left_part] != i) ans.insert({i,map[left_part]});
                }

                reverse(right_part.begin(),right_part.end());
                if (isPalindrome(left_part) && map.find(right_part) != map.end()){
                    
                    if (map[right_part] != i) ans.insert({map[right_part],i});
                }
            }
        }

        return vector<vector<int>>(ans.begin(),ans.end());
    }
};

/*



*/