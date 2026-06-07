class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ans = 0;

        for(int shifts = 0;shifts < 32;shifts++){

            int set_bits = 0;

            for(int num : nums){

                if ((num >> shifts) & 1){
                    set_bits++;
                }
            }

            ans |= ((set_bits % 3) << shifts);
        }

        return ans;
    }
};