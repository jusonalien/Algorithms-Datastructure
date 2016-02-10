int myAtoi(char* str) {
    if (str == NULL)
        return 0;
    while(*str == ' ') { // skip the whitespace;
        str++;
    }
    int sign = 0;
    
    if (*str == '-') {
        sign = 1;
        str++;
    } else if (*str == '+') {
        str++;
    }
    
    int ans = 0;
    
    while((*str >= '0') && (*str <= '9') && (*str != '\0')) {
        if (sign == 0) {
            if (ans > (INT_MAX - (*str - '0')) / 10) {
                ans =  INT_MAX;
                break;
            }
        } else {
            if (-ans < (INT_MIN + (*str - '0')) / 10) {
                ans = -INT_MIN;
                break;
            }
        }
        ans = ans * 10 + (*str - '0');
        str++;
    }
    
    if (sign == 1) {
        ans = -ans;
    }
/*
    if (ans == 2147483647 )
        ans = 2147483647;
    if (ans < -2147483648)
        ans = -2147483648;
*/
    return ans;
    
}
