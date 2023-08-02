// https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/count-the-subarrays-having-product-less-than-k1708

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int ans = 0;
        long long prod = 1;
        int left = 0, right = 0;
        
        for(right = 0; right < n; right++) {
            prod = prod * a[right];

            while(prod >= k && left <= right) {
                    prod = prod / a[left];
                    left++;
            }
            
            ans += right - left + 1;
        }
        return ans;
    }
};
