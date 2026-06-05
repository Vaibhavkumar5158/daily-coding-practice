class Solution {
public:
    int reverseNumber(int num) {
        int ans = 0;

        while(num != 0){
            int digit  = num % 10;

            // overflow check
            if(ans > INT_MAX / 10 || ans < INT_MIN / 10) {
                return 0;
            }

            ans = ans * 10 + digit;
            num = num / 10;
        }

        return ans;
    }

    bool isPalindrome(int x) {
        if(x < 0) return false;   // negative number palindrome nahi hota

        int original = x;
        int rev = reverseNumber(x);

        if (original == rev){
            return true;
        }
        else{
            return false;
        }
    }
};