class Solution {
public:

    int calc_waviness(int n){
        if (n <= 99) return 0;

        string num = to_string(n);

        int count = 0;

        for(int i = 1;i <= num.size() - 2;i++){

            cout << num << endl;
            
            int prev = num[i - 1] - '0';
            int curr = num[i] - '0';
            int next = num[i + 1] - '0';

            if ((curr > prev && curr > next) || (curr < prev && curr < next))  count++;
        }

        return count;
    }

    int totalWaviness(int num1, int num2) {

        int total_waviness = 0;
        for(int i = num1;i <= num2;i++){
            total_waviness += calc_waviness(i);
        }

        return total_waviness;
    }
};

/*

Calculate the waviness of a number 


*/