int lengthOfLongestSubstring(char* s) {
    int hashtable[300];
    int ans = 0;
    int temp = 0;
    int i,j;
    for (i = 0;s[i] != '\0';++i) {
        memset(hashtable, 0, sizeof(hashtable));
        temp = 0;
        for (j = i;s[j] != '\0';++j) {
            if (hashtable[s[j]] == 0) {
                ++temp;
                hashtable[s[j]] = 1;
            } else {
                break;
            }
        }
        ans = ans > temp ? ans : temp;
    }
    return ans;
}
