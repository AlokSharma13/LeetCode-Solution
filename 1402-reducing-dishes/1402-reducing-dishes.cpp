class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());

        int n = satisfaction.size();
        int max = 0;
        int curr_sum = 0;

        for(int i = n-1; i>=0; i--){
            curr_sum = curr_sum+satisfaction[i];
            if(curr_sum<0) break;
            max = max+curr_sum;
        }

        return max;
    }
};