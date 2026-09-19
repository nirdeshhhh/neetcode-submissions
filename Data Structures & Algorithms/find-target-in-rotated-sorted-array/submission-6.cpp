class Solution {
public:

    int bs(vector<int>& nums, int &target, int start, int end){
        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid] == target) return mid;

            else if(nums[mid] > target)  end = mid - 1;
            else  start = mid + 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;

        while(l < r){
            int m = l + (r-l)/2;
            if(nums[m] > nums[r]) l = m + 1;

            else r = m;
        }

        int pivot = l;

        if(pivot == 0) {
            return bs(nums, target, 0, nums.size() - 1);
        }

        if(nums[0] <= target && target <= nums[pivot-1]) 
            return bs(nums, target, 0, pivot-1);
        
        else
            return bs(nums, target, pivot, nums.size()-1);
    }
};
