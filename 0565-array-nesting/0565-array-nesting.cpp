class Solution {
public:

    vector<vector<int>> createGraph(vector<int> &nums){

        vector<vector<int>> graph(nums.size());

        for(int i = 0;i < nums.size();i++){
            graph[nums[i]].push_back(nums[nums[i]]);
            graph[nums[nums[i]]].push_back(nums[i]);
        }

        return graph;
    }

    int count(int src,vector<bool> &visited,vector<vector<int>> &graph){

        visited[src] = true;

        int curr_count = 1;

        for(int neigh : graph[src]){
            if (!visited[neigh]){
                curr_count += count(neigh,visited,graph);
            }
        }

        return curr_count;
    }

    int max_size(vector<int> &nums){

        vector<vector<int>> graph = createGraph(nums);
        vector<bool> visited(nums.size(),false);

        int max_size = 0;
        for(int i = 0;i < nums.size();i++){
            if (!visited[i]){
                max_size = max(max_size,count(i,visited,graph));
            }
        }

        return max_size;
    }

    int arrayNesting(vector<int>& nums) {
        return max_size(nums);
    }
};


/*

5   4   1   3   0   6   2



     5 -> 6 -> 2 -> 1 -> 4 -> 0 -> 5

     
     5,4,0,3,1,6,2


     5 -> 6 -> 2 -> 0 -> 5

     4 -> 1 

     so we can conver this into direct graph

*/
