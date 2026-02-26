class Solution {
public:

    vector<int> leftMax(vector<int> &height){

        int n = height.size();
        vector<int> left_max(n,height[0]);

        for(int i = 1;i < n;i++){
            left_max[i] = max(left_max[i - 1],height[i]);
        }

        return left_max;
    }

    vector<int> rightMax(vector<int> &height){

        int n = height.size();
        vector<int> right_max(n,height.back());

        for(int i = n - 2;i >= 0;i--){
            right_max[i] = max(right_max[i + 1],height[i]);
        }

        return right_max;
    }

    int trap(vector<int>& height) {
        
        int trapped_water = 0;

        int n = height.size();

        vector<int> left_max = leftMax(height);
        vector<int> right_max = rightMax(height);

        for(int i = 0;i < n;i++){
            trapped_water += max(height[i],min(left_max[i],right_max[i])) - height[i];
        }

        return trapped_water;
    }
};