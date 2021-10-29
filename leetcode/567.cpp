class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n2 = s2.length();
        int n1 = s1.length();

        if (n1 > n2) return false;

        vector<int> alpha(26, 0);
        bool res = false;
        int cnt = 0;


        for (int i = 0; i < n1; i++) {
            alpha[s1[i] - 'a']++;
            alpha[s2[i] - 'a']--;
        }

        if (checkZero(alpha)) return true;

        for (int i = n1; i < n2; i++) {
            alpha[s2[i] - 'a']--;
            alpha[s2[i - n1] - 'a']++;

            if (checkZero(alpha)) return true;
        }

        return false;
    }

    int checkZero(vector<int>& alpha) {
        for (int i = 0; i < alpha.size(); i++) {
            if (alpha[i] != 0) {
                return false;
            }
        }
        return true;
    }
};