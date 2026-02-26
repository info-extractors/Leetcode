class Solution {
public:

    vector<int> nextSmallerEqual(vector<int>& nums){

        vector<int> nextSmallerEq(nums.size(),nums.size());
        stack<int> st;

        for(int i = nums.size() - 1;i >= 0;i--){

            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }

            if (!st.empty()){
                nextSmallerEq[i] = st.top();
            }

            st.push(i);
        }

        return nextSmallerEq;
    }

    vector<int> prevSmaller(vector<int> &nums){

        vector<int> prevSmaller_(nums.size(),-1);
        stack<int> st;

        for(int i = 0;i < nums.size();i++){

            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }

            if (!st.empty()){
                prevSmaller_[i] = st.top();
            }

            st.push(i);
        }

        return prevSmaller_;
    }

    vector<int> nextGreaterEqual(vector<int> &nums){
        vector<int> nextGreaterEq(nums.size(),nums.size());
        stack<int> st;

        for(int i = nums.size() - 1;i >= 0;i--){

            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }

            if (!st.empty()){
                nextGreaterEq[i] = st.top();
            }

            st.push(i);
        }

        return nextGreaterEq;
    }

    vector<int> prevGreater(vector<int> &nums){

        vector<int> prevGreater_(nums.size(),-1);
        stack<int> st;

        for(int i = 0;i < nums.size();i++){

            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop(); 
            }

            if (!st.empty()){
                prevGreater_[i] = st.top();
            }

            st.push(i);
        }

        return prevGreater_;
    }

    long long subArrayRanges(vector<int>& nums) {
        
        long long total = 0;

        vector<int> nextG = nextGreaterEqual(nums);
        vector<int> prevG = prevGreater(nums);
        vector<int> nextS = nextSmallerEqual(nums);
        vector<int> prevS = prevSmaller(nums);

        for(int i = 0;i < nums.size();i++){

            long long max_sum = 1ll * (nextG[i] - i) * (i - prevG[i]);
            long long min_sum = 1ll * (nextS[i] - i) * (i - prevS[i]);

            total += (max_sum - min_sum) * nums[i];
        }

        return total;
    }
};