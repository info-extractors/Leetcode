class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int,int> sum_index;
        sum_index[0] = 1;
        int curr_sum = 0;
        int count = 0;

        for(int i = 0;i < n;i++){

            curr_sum += nums[i];

            if (sum_index.find(curr_sum - k) != sum_index.end()){
                count += sum_index[curr_sum - k];
            }

            sum_index[curr_sum]++;
        }

        return count;
    }
};