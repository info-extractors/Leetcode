class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        int max_length = 0;

        unordered_map<int,int> umap;
        int left = 0;

        for(int right = 0;right < nums.size();right++){

            umap[nums[right]]++;

            while(umap[nums[right]] > k){
                umap[nums[left]]--;
                left++;
            }

            max_length = max(max_length,right - left + 1);
        }

        return max_length;
    }
};
