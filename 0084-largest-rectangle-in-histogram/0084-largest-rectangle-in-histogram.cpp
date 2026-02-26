class Solution {
public:

    vector<int> prevSmaller(vector<int> &heights){

        vector<int> ans(heights.size(),-1);
        stack<int> st;

        for(int i = 0;i < heights.size();i++){

            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if (!st.empty()){
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    vector<int> nextSmaller(vector<int> &heights){

        vector<int> ans(heights.size(),heights.size());
        stack<int> st;

        for(int i = heights.size() - 1;i >= 0;i--){

            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if (!st.empty()){
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {

        int max_area = 0;

        vector<int> ps = prevSmaller(heights);
        vector<int> ns = nextSmaller(heights);
        
        for(int i = 0;i < heights.size();i++){

            int left = ps[i];
            int right = ns[i];

            max_area = max(max_area,heights[i] * (right - left - 1));
        }

        return max_area;
    }
};