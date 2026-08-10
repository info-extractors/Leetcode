class Solution {
public:

    int intSqrt(int n){
        if (n == 0) return 0;
        if (n <= 3) return 1;

        int left = 2;
        int right = n / 2;
        
        int ans = right + 1;
        while(left <= right){

            int mid = left + ((right - left) / 2);
            long long midSquare = (1ll * mid * mid);

            if (midSquare == n) return mid;
            else if (midSquare < n) {left = mid + 1; ans = mid;}
            else right = mid - 1;
        }
        
        return ans;
    }

    int bulbSwitch(int n) {
        return intSqrt(n);
    }
};

/*

 n <= n^2 / 4

 4n <= n^2

 4 <= n 
 
*/