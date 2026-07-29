class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int max_length = 0;
        int left = 0;

        vector<int> count(2,0);

        for(int right = 0;right < nums.size();right++){

            count[nums[right]]++;

            while(count[0] > 1){
                count[nums[left]]--;
                left++;
            }

            max_length = max(max_length,right - left + 1);
        }

        return max_length - 1;
    }
};

/*


[0,1,0,1]

this is sure that 

if ans is nums.size() then return nums.size() - 1

0 1 0 1

*/