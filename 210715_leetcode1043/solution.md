# 1043. Partition Array for Maximum Sum

**Medium**
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

최대 K개의 숫자로 이루어진 여러개의 묶음을 만들어서 각각의 묶음에서 제일 큰 숫자로 다 바꿨을때 배열의 모든 숫자의 합의 최댓값을 뽑아라.

Example 1:
```
Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
```

Example 2:
```
Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
```

Constraints:
- 1 <= arr.length <= 500
- 0 <= arr[i] <= 109
- 1 <= k <= arr.length

# 풀이과정
k=3라고 하면, dp[i]는 
1. dp[i-1] + arr[i] * 1 
2. dp[i-2] + max(arr[i-1], arr[i]) * 2 
3. dp[i-3] + max(arr[i-2], arr[i-1], arr[i]) * 3 
중에서의 최댓값이다. 
2중 반복문을 돌려서 이러한 경우들의 최댓값들을 비교해서 dp배열에 넣어주면된다.