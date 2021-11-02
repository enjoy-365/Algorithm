class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        int mid = 0;

        if (nums[hi] < target) return hi + 1;

        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (nums[mid] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        if (nums[mid] == target) return mid;
        mid = (lo + hi) >> 1;

        return mid;
        //return nums[mid] < target? mid+1: mid -1;
    }
};