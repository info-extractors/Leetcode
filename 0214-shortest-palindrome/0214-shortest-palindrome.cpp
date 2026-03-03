class Solution {
public:

    vector<int> buildLPS(string &s){

        int n = s.length();
        vector<int> lps(n,0);

        int len = 0;
        int i = 1;

        while(i < n){
            if (s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if (len != 0){
                    len = lps[len - 1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    string shortestPalindrome(string s) {

        string temp = s;
        reverse(temp.begin(),temp.end());

        string new_string = s + "#" + temp;
        cout << new_string << endl;
        vector<int> lps = buildLPS(new_string);
        int len = lps.back();

        string back = s.substr(len,s.length() - len);
        reverse(back.begin(),back.end());
        return back + s;
    }
};


/*

  0 1 2 3 4
  a b a d d

  len , s.length() - len
*/
