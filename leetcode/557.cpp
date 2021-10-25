class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                for (j = i; j < n && s[j] != ' '; j++) {
                    // j가 공백을 만날때까지 ++됨.
                }
                reverse(s.begin() + i, s.begin() + j);
                i = j; // for문 증감식에서 다음 i가 +1이됨.
            }
        }


        return s;
    }
};