class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                for (j = i; j < n && s[j] != ' '; j++) {
                    // j�� ������ ���������� ++��.
                }
                reverse(s.begin() + i, s.begin() + j);
                i = j; // for�� �����Ŀ��� ���� i�� +1�̵�.
            }
        }


        return s;
    }
};