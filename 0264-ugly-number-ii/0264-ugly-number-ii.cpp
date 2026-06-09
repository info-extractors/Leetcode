class Solution {
public:

    struct CustomCompare{
        bool operator()(long long a,long long b){
            return (a > b);
        }
    };

    int nthUglyNumber(int n) {
        

        priority_queue<long long,vector<long long>,CustomCompare> pq;
        unordered_set<long long> uset;

        int index = 1;
        uset.insert(1);
        pq.push(1);

        while(index != n){

            long long top = pq.top();pq.pop();

            if (!uset.count(top * 2)){
                pq.push(top * 2);
                uset.insert(top * 2);
            }

            if (!uset.count(top * 3)){
                pq.push(top * 3);
                uset.insert(top * 3);
            }

            if (!uset.count(top * 5)){
                pq.push(top * 5);
                uset.insert(top * 5);
            }

            index++;
        }

        return pq.top();
    }
};