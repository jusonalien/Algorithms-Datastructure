class Solution {
public:
    string longestPalindrome(string s) {
        int ansint = 1;
        string ansstring;
        int len = s.length();
        if (len == 1) return s;
        for (int i = 0;i < len;++i) {
            int start = i;
            int end   = i;
            int cnt = 0;
            while (start >= 0 && end < len) {
                if (s[start] == s[end]) {
                    cnt += 2;
                } else {
                    break;
                }
                start--;
                end++;
            }
            if (cnt - 1 > ansint) {
                ansint = cnt - 1;
                if ((end - start + 1) == ansint)
                    ansstring.assign(s,start, ansint);
                else 
                    ansstring.assign(s,start + 1, ansint);
            }
            
            start = i;
            end   = i + 1;
            cnt = 0;
            while (start >= 0 && end < len) {
                if (s[start] == s[end]) {
                    cnt += 2;
                } else {
                    break;
                }
                start--; end++;
            }
            if (cnt > ansint) {
                ansint = cnt;
                if ((end - start + 1) == ansint)
                    ansstring.assign(s, start, ansint);
                else 
                    ansstring.assign(s, start + 1, ansint);
            }
        }
        return ansstring;
    }
};
