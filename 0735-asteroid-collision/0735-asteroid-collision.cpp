class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;

        int i = 0;

        while(i < n){

            if (ans.empty()){
                ans.push_back(asteroids[i]);
                i++;
            }else if (ans.back() > 0 && asteroids[i] < 0){

                int top = ans.back();
                int curr = asteroids[i];

                if (abs(top) == abs(curr)){
                    ans.pop_back();
                    i++;
                }else if (abs(top) > abs(curr)){
                    i++;
                }else{
                    ans.pop_back();
                }
            }
            else{
                ans.push_back(asteroids[i]);i++;
            }
        }

        return ans;
    }
};