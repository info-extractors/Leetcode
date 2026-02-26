class Solution {
public:

    vector<int> nextGreater(vector<int> &nums){

        stack<int> st;

        vector<int> ans = vector<int>(nums.size(),-1);

        for(int i = nums.size() - 1;i >= 0;i--){

            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            if (!st.empty()) ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int,int> index;

        for(int i = 0;i < m;i++){
            index[nums2[i]] = i;
        }

        vector<int> next_greater = nextGreater(nums2);
        for(int i : next_greater) cout << i <<" ";

        vector<int> ans(n,-1);
        for(int i = 0;i < n;i++){
            int j = next_greater[index[nums1[i]]];
            if (j != -1){
                ans[i] = nums2[j];
            }
        }

        return ans;
    }
};