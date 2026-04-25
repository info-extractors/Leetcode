class Solution {
public:

    int maximum_sum(vector<int> &nums){

        int curr_sum = nums[0];
        int max_sum = nums[0];

        for(int i = 1;i < nums.size();i++){
            
            curr_sum = max(nums[i],curr_sum + nums[i]);
            max_sum = max(max_sum,curr_sum);
        }

        return max_sum;
    }

    int minimum_sum(vector<int> &nums){

        int curr_sum = nums[0];
        int max_sum = nums[0];

        for(int i = 1;i < nums.size();i++){
            
            curr_sum = min(nums[i],curr_sum + nums[i]);
            max_sum = min(max_sum,curr_sum);
        }

        return max_sum;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        cout << maximum_sum(nums) << endl;
        cout << abs(minimum_sum(nums));
        return max(maximum_sum(nums),abs(minimum_sum(nums)));
    }
};