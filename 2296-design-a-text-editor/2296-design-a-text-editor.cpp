class TextEditor {

    stack<char> left;
    stack<char> right;

    string lastString(stack<char> &st,int len){

        string ans = "";
        while(len){
            ans += st.top();
            st.pop();
            len--;
        }

        reverse(ans.begin(),ans.end());

        for(char c : ans) st.push(c);

        return ans;
    }

public:
    TextEditor() {
        
    }
    
    void addText(string text) {
        for(char c : text) left.push(c);
    }
    
    int deleteText(int k) {
        int toBeRemoved = min((int)left.size(),k);
        int counter = toBeRemoved;

        while(counter){
            left.pop();counter--;
        }

        return toBeRemoved; 
    }
    
    string cursorLeft(int k) {
        
        int move = min((int)left.size(),k);
        while(move){
            right.push(left.top());
            left.pop();
            move--;
        }

        int len = left.size();
        int popCount = min(10,len);

        return lastString(left,popCount);
    }
    
    string cursorRight(int k) {
        
        int move = min(k,(int)right.size());
        while(move){
            left.push(right.top());
            right.pop();
            move--;
        }

        int len = left.size();
        int popCount = min(10,len);

        return lastString(left,popCount);
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */