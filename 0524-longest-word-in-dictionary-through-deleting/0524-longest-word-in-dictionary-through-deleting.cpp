class Solution {
public:

    bool isSubSeq(string &pattern,string &text){

        if (pattern.size() > text.size()) return false;
        int first = 0;
        int second = 0;

        while(second < text.size()){
            if (pattern[first] == text[second]){
                first++;
            }
            second++;
        }

        return (first == pattern.size());
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";

        for(int i = 0;i < dictionary.size();i++){

            string pattern = dictionary[i];
            if (isSubSeq(pattern,s)){

                if (ans == ""){
                    ans = pattern;
                }else{

                    if (pattern.size() > ans.size()){
                        ans = pattern;
                    }else if (pattern.size() == ans.size()){
                        if (pattern < ans){
                            ans = pattern;
                        }
                    }
                }
            }
        }

        return ans;
    }
};

/*

for example we have 

  a  b  p  c  p  l  e  a

  a     p     p  l  e

  we have to make sure that the given number is present 
  in the s

  we can do that easily 

*/