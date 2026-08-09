class Solution {
private:
    long long helper(long long x, long long dig, long long mod) {
        long long ans = 1;
        while(dig) {
            if(dig % 2 == 0) {
                x = (x * x) % mod;
                dig /= 2;
            }
            else {
                ans = (ans * x) % mod;
                dig -= 1;
            }
        }
        return ans;
    }
public:
    int countGoodNumbers(long long n) {
       long long even = (n + 1) / 2;
       long long odd = n / 2;
       long long mod = 1e9 + 7;
       return (int)((helper(5, even, mod) * helper(4, odd, mod)) % mod);
    }
};