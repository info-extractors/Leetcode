class Solution {
public:

    void merge_parts(vector<int> &arr,int l,int m,int r){

        vector<int> arr1(m - l + 1);
        vector<int> arr2(r - m);
        copy(arr.begin() + l,arr.begin() + m + 1,arr1.begin());
        copy(arr.begin() + m + 1,arr.begin() + r + 1,arr2.begin());
        merge(arr1.begin(),arr1.end(),arr2.begin(),arr2.end(),arr.begin() + l);
    }

    void merge_sort(vector<int> &nums,int l,int r){

        if (l < r){

            int mid = l + (r - l) / 2;

            merge_sort(nums,l,mid);
            merge_sort(nums,mid + 1,r);
            merge_parts(nums,l,mid,r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        
        merge_sort(nums,0,nums.size() - 1);
        return nums;
    }
};