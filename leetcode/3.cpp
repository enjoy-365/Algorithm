class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;

        vector<int> alphabet(128, -1);
        int n = s.length();
        int start = 0;

        for (int i = 0; i < n; i++) {

            if (alphabet[s[i]] != -1) {
                start = max(alphabet[s[i]] + 1, start);
            }
            alphabet[s[i]] = i;
            ans = max(ans, i - start + 1);
            //cout << "ans = " << ans << " = " << i << "-" << start << "+1" << endl;
        }

        return ans;
    }
};