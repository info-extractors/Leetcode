class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());
        
        int max_length = 0;
        int left = 0;
        for(int right = 0;right < nums.size();right++){

            while((nums[right] - nums[left]) > (2*k)){
                left++;
            }

            max_length = max(max_length,right - left + 1);
        }

        return max_length;
    }
};

