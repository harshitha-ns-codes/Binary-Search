class Solution {
public:
    int myAtoi(string s) 
    {
        int i = 0;

        while(i < s.size() && s[i] == ' ')
            i++;

        int sign = 1;

        if(i < s.size() && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '-') 
                sign = -1;
            i++;
        }

        long long ans = 0;   // 🔥 important change

        while(i < s.size() && isdigit(s[i]))
        {
            if(ans > (INT_MAX - (s[i] - '0')) / 10)
                return sign == 1 ? INT_MAX : INT_MIN;

            ans = ans * 10 + (s[i] - '0');
            i++;
        }

        return (int)(sign * ans);
    }
};