class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        if(n==0) return 0;

        int count = 1; 
        int longest = 1;

        for(int i=1; i<n; i++){
            if(nums[i-1] == nums[i]) continue;

            if(nums[i-1] + 1 == nums[i]){
                count++;
            }
            else{
                count = 1;
            }

            longest = max(longest, count);
        }

        return longest;
    }
};
