class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        vector<int> max_array(prices.size());

        max_array[prices.size() - 1] = prices[prices.size() - 1];

        for(int i = prices.size() - 2;i >= 0;i--){
            max_array[i] = max(prices[i],max_array[i + 1]);
        }

        int max_profit = 0;

        for(int i = 0;i < prices.size();i++){
            max_profit = max(max_profit,max_array[i] - prices[i]);
        }

        return max_profit;
    }
};


/*


 lets say we have this array [7,1,5,3,6,7]

Create an array 


*/