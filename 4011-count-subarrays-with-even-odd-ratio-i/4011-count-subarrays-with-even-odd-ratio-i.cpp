class Solution {
public:

    bool isSmall(int x,int y,int a,int b){
        return (1ll * b * x) <= (1ll * a * y);
    }
    
    int countRatioSubarrays(vector<int>& nums, int a, int b) {

        int validSubArrays = 0;
        
        for(int i = 0;i < nums.size();i++){

            int even = 0;
            int odd = 0;
            for(int j = i;j < nums.size();j++){

                even += (nums[j] % 2 == 0);
                odd += (nums[j] % 2 == 1);

                if (odd > 0) validSubArrays += isSmall(even,odd,a,b);
            }
        }

        return validSubArrays;
    }
};