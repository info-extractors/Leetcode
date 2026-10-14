class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> sumCount;
        sumCount[0] = 1;
        int cummulativeSum = 0;
        int count = 0;

        for(int num : nums){
            cummulativeSum += num;
            count += sumCount[cummulativeSum - k];
            sumCount[cummulativeSum]++;
        }

        return count;
    }
};