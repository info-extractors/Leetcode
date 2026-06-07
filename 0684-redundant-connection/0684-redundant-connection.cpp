class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]); // path compression
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return false;

        // union by rank
        if (rank[px] < rank[py]) {
            parent[px] = py;
        }
        else if (rank[px] > rank[py]) {
            parent[py] = px;
        }
        else {
            parent[py] = px;
            rank[px]++;
        }

        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        DSU dsu(1001);
        vector<int> ans = {};

        for(auto edge : edges){

            int u = edge[0];
            int v = edge[1];

            if (!dsu.unite(u,v)) ans = {u,v};
        }

        return ans;
    }
};