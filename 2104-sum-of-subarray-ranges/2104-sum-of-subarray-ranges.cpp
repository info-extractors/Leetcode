class Solution {
public:

    vector<int> nextSmaller(vector<int> &nums){

        stack<int> st;
        vector<int> ans(nums.size(),nums.size());

        for(int i = nums.size() - 1;i >= 0;i--){

            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();

            if (!st.empty()){
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    vector<int> prevSmaller(vector<int> &nums){

        stack<int> st;
        vector<int> ans(nums.size(),-1);

        for(int i = 0;i < nums.size();i++){

            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();

            if (!st.empty()){
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    vector<int> nextGreater(vector<int> &nums){
        stack<int> st;
        vector<int> ans(nums.size(),nums.size());

        for(int i = nums.size() - 1;i >= 0;i--){

            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();

            if (!st.empty()){
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    vector<int> prevGreater(vector<int> &nums){
        stack<int> st;
        vector<int> ans(nums.size(),-1);

        for(int i = 0;i < nums.size();i++){

            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();

            if (!st.empty()){
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        
        long long total = 0;

        vector<int> nextSmallerEq = nextSmaller(nums);
        vector<int> prevSmaller_ = prevSmaller(nums);
        vector<int> nextGreaterEq = nextGreater(nums);
        vector<int> prevGreator = prevGreater(nums);

        for(int i = 0;i < nums.size();i++){

            long long max_expansion = 1ll * (nextGreaterEq[i] - i) * (i - prevGreator[i]);
            long long min_expansion = 1ll * (nextSmallerEq[i] - i) * (i - prevSmaller_[i]);

            total += ((max_expansion - min_expansion)) * nums[i];
        }

        return total;
    }
};