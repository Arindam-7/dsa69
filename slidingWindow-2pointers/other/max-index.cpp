// https://practice.geeksforgeeks.org/problems/maximum-index-1587115620/1

class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
      vector<int> leftMin(n, 0);
      vector<int> rightMax(n, 0);
      leftMin[0] = arr[0];
      rightMax[n-1] = arr[n-1];

      for(int i = 1; i < n; i++) {
        leftMin[i] = min(leftMin[i-1], arr[i]);

        rightMax[n-i-1] = max(rightMax[n-i], arr[n-i-1]);
      }

      int maxDiff = 0;
      
      int i = 0, j = 0;

      while(j < n) {
        if(leftMin[i] <= rightMax[j]) {
          maxDiff = max(maxDiff, j-i);
          j++;
        }
        else i++;
      }

      return maxDiff;
    }
};
