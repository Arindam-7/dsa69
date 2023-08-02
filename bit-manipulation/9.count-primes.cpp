// https://leetcode.com/problems/count-primes/description/

// sieve of eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n+1, true);
        int ans = 0;

        for(int p = 2; p*p <= n; p++) {
            if(prime[p] == true) {
                for(int i = p*p; i <= n; i += p) {
                    prime[i] = false;
                }
            }
        }

        for(int i = 2; i < n; i++) {
            if(prime[i] == true) ans++;
        }
         
        return ans;
    }
};
