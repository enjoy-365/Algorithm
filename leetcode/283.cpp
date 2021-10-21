class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroPos = 0; // NonZero�� ������ ����� ��.
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroPos++] = nums[i];
            }
        }

        for (int i = lastNonZeroPos; i < n; i++) {
            nums[i] = 0;
        }


    }
};