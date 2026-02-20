class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        
        unordered_map<int,int> numFreq;
        unordered_map<int,int> freqFreq;

        for(int i : nums) numFreq[i]++;
        for(auto [num,freq] : numFreq) freqFreq[freq]++;

        
        for(int i = 0;i < nums.size();i++){

            int freqCount = freqFreq[numFreq[nums[i]]];

            if (freqCount == 1) return nums[i];
        }

        return -1;
    }
};

/*

make frequency table of the frequency also 

*/