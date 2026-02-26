class Solution {
public:

    vector<int> nextSmaller(vector<int> &arr){

        vector<int> ans(arr.size(),arr.size());
        stack<int> st;

        for(int i = arr.size() - 1;i >= 0;i--){

            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            if (!st.empty()){
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    vector<int> prevSmaller(vector<int> &arr){

        vector<int> ans(arr.size(),-1);
        stack<int> st;

        for(int i = 0;i < arr.size();i++){

            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

            if (!st.empty()){
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        
        int total = 0;
        int MOD = 1e9 + 7;

        vector<int> nse = nextSmaller(arr);
        vector<int> pse = prevSmaller(arr);

        for(int i = 0;i < arr.size();i++){
            total = (total + (1ll * (nse[i] - i) * (i - pse[i]) * arr[i])) % MOD;
        }

        return total;
    }
};