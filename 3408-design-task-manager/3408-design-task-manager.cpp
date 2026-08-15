class TaskManager {

    struct CustomCompare{
        bool operator()(vector<int> &a,vector<int> &b){
            if (a[2] == b[2]){
                return a[1] < b[1];
            }

            return a[2] < b[2];
        }
    };

    unordered_map<int,pair<int,int>> task_map;
    priority_queue<vector<int>,vector<vector<int>>,CustomCompare> pq;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto it : tasks){
            pq.push(it);
            task_map[it[1]] = {it[0],it[2]};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.push({userId,taskId,priority});
        task_map[taskId] = {userId,priority};
    }
    
    void edit(int taskId, int newPriority) {
        task_map[taskId].second = newPriority;
        pq.push({task_map[taskId].first,taskId,newPriority});
    }
    
    void rmv(int taskId) {
        task_map.erase(taskId);
    }
    
    int execTop() {
        
        while(!pq.empty() && (!task_map.count(pq.top()[1]) || task_map[pq.top()[1]].second != pq.top()[2] || task_map[pq.top()[1]].first != pq.top()[0])) pq.pop();

        if (pq.empty()) return -1;

        int userId = pq.top()[0];
        int taskId = pq.top()[1];
        pq.pop();

        task_map.erase(taskId);

        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */