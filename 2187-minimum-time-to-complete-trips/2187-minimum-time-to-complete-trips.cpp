class Solution {
public:


    bool checkValidity(vector<int> &time,int totalTrips,long long candidate){

        long long tripCount = 0;

        for(int i = 0;i < time.size();i++){

            long long temp = candidate / (1ll * time[i]);

            tripCount += temp;
            if (tripCount >= totalTrips) return true;
        }

        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long left = 0;
        long long minimumHour = *min_element(time.begin(), time.end());
        long long right = minimumHour * totalTrips;

        long long ans = right;

        while(left <= right){

            long long mid = left + ((right - left) / 2);

            bool isValid = checkValidity(time,totalTrips,mid);

            if (isValid){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return ans;
    }
};

/*

 [ 1   1    1    1, 1 , 1, 1]

 0   LLONG_MAX


 (LLONG_MAX/2) / 1 +  (LLONG_MAX/2) / 1 +

 low = l 
 high = h 

 mid = (low,high)

 INT_MAX   long long

  
  (mid / time[0] + mid / time[1] + ... + mid / time[n -1 ])

  < totalTrips 

  low = mid + 1

  ans = mid;
low - high  INT_MAX
  int hight = INT_MAX;











  
*/