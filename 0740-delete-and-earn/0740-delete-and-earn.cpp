class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.empty()) return 0;   

        int maxValue = 0;   //max value 
        for(int num:nums){
            maxValue = max(maxValue,num); 
        }
        vector<int> arr(maxValue+1,0); //max value array 
        for(int num : nums){
            arr[num] = arr[num]+num;
        }

        int rob1 =0;
        int rob2=0;

        for(int i =0;i<=maxValue;i++){
            int current = max(rob2,rob1+arr[i]);
            rob1 = rob2;
            rob2 = current;
        }
        return rob2;
    }
};