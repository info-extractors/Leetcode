class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> uset(nums.begin(),nums.end());

        for(int i = 1;i <= nums.size() + 1;i++){
            if (uset.find(i) == uset.end()) return i;
        }

        return -1;
    }
};