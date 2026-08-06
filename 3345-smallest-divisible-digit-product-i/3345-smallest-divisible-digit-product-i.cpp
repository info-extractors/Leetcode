class Solution {
public:

    bool isProductDiv(int n,int t){
        int product = 1;
        int length = log10(n) + 1;
        while(length){
            product *= (n % 10);
            n /= 10;
            length--;
        }

        cout << product << endl << endl;
        return !(product % t);
    }

    int smallestNumber(int n, int t) {
        
        int curr = n;
        while(!isProductDiv(curr,t)){
            curr++;
        }

        return curr;
    }
};