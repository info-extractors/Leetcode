class FreqStack {
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> freqStack;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        freqStack[freq[val]].push(val);
    }
    
    int pop() {

        int max_freq = freqStack.size();
        int value = freqStack[max_freq].top();
        freqStack[max_freq].pop();

        freq[value]--;

        if (freqStack[max_freq].empty()){
            freqStack.erase(max_freq);
        }

        return value;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */