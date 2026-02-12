class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        long long subarrays = 0;
        int left = 0;
        int count = 0;
        int max_ele = *max_element(nums.begin(),nums.end());

        for(int right = 0;right < nums.size();right++){

            if (nums[right] == max_ele) count++;

            while(count >= k){
                subarrays += (nums.size() - right);
                
                if (nums[left] == max_ele){
                    count--;
                }
                left++;
            }
        }

        return subarrays;
    }
};