class Solution {
public:

    int rightSum(vector<int> &code,int k,int index){

        int sum = 0;
        int inc = 0;
        int start = (index + 1) % code.size();

        while(inc < k){

            sum += code[start];

            start = (start + 1) % code.size();
            inc++;
        }

        return sum;
    }

    int leftSum(vector<int> &code,int k,int index){
        int start = (index - 1 + code.size()) % code.size();
        int dec = 0;
        int sum = 0;

        while(dec < abs(k)){

            sum += code[start];
            start = (start + code.size() - 1) % code.size();
            dec++;
        }

        return sum;
    }

    vector<int> decrypt(vector<int>& code, int k) {
        
        vector<int> decryptedArray(code.size(),0);
        if (k == 0) return decryptedArray;


        for(int i = 0;i < code.size();i++){
            if (k > 0) decryptedArray[i] = rightSum(code,k,i);
            if (k < 0) decryptedArray[i] = leftSum(code,k,i);
        }

        return decryptedArray;
    }
};

/*

    
*/