class Spreadsheet {
    unordered_map<string,int> sheet;
public:
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        sheet[cell] = value;
    }
    
    void resetCell(string cell) {
        sheet[cell] = 0;
    }
    
    int getValue(string formula) {
        pair<string,string> token = {"",""};

        int left = 1;
        while(left < formula.size() && formula[left] != '+'){
            token.first += formula[left];
            left++;
        }
        
        left++;
        while(left < formula.size()){
            token.second += formula[left];
            left++;
        }

        int first_val = (isdigit(token.first[0]) ? stoi(token.first) : sheet[token.first]);
        int second_val = (isdigit(token.second[0]) ? stoi(token.second) : sheet[token.second]);

        return first_val + second_val;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */