class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        int cnt = 0;
        int targetNum = nums[0];
        int curr = 0;
        int tmp;

        int start = 0;

        while (cnt < n) {
            do {
                cnt++;
                tmp = nums[(curr + k) % n];
                nums[(curr + k) % n] = targetNum;
                targetNum = tmp;
                curr = (curr + k) % n;
            } while (start != curr);
            start++;
            curr = start;
            targetNum = nums[curr];
        }

    }
};