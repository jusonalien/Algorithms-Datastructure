class Solution {
public:
    std::string num_to_string;
    
    std::string numberToString(int num) {
        num_to_string = "";
        int cnt;
        int Length = 1;
        while(num != 0) {
            ++Length;
            cnt = num % 10;
            num /= 10;
            num_to_string += '0' + cnt;
        }
        return num_to_string;
    }
    
    bool isPalindrome(int x) {
        if(x < 0) return false;
        else if (x / 10 == 0) return true;
        std::string test_string = numberToString(x);
        int start = 0;
        int end   = test_string.length() - 1;
        while(start < end) {
            if(test_string[start] != test_string[end])
                return false;
            ++start;
            --end;
        }
        return true;
    }

};
