class Solution {
public:

    long long sq(int x){
        return 1ll * x * x;
    }

    bool inRange(vector<int> &one,vector<int> &two){

        int x1 = one[0];
        int y1 = one[1];
        int r1 = one[2];

        int x2 = two[0];
        int y2 = two[1];
        int r2 = two[2];

        double dist = sqrt(sq(x2 - x1) + sq(y2 - y1));

        return (dist <= r1);
    }

    vector<vector<int>> graphConstruction(vector<vector<int>> &bombs){

        vector<vector<int>> graph(bombs.size());

        for(int i = 0;i < bombs.size() - 1;i++){
            for(int j = i + 1;j < bombs.size();j++){

                auto u = bombs[i];
                auto v = bombs[j];

                if (inRange(u,v)) graph[i].push_back(j);
                if (inRange(v,u)) graph[j].push_back(i);
            }
        }

        return graph;
    }

    int size(vector<vector<int>> &graph,vector<bool> &detonated,int start){

        int size_ = 0;
        detonated[start] = true;

        for(int neighbor : graph[start]){
            if (!detonated[neighbor]){
                size_ += 1 + size(graph,detonated,neighbor);
            }
        }


        return size_;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {

        vector<vector<int>> graph = graphConstruction(bombs);

        for(int i = 0;i < graph.size();i++){
            cout << i <<":";
            for(int j : graph[i]){
                cout << j <<" ";
            }
            cout << endl;
        }

        int max_detonation = 0;
        for(int start = 0;start < graph.size();start++){
            vector<bool> detonated = vector<bool>(graph.size(),false);
            max_detonation = max(max_detonation,size(graph,detonated,start));
        }

        return max_detonation + 1;
    }
};