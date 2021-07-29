class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        // dp[i] = index i까지의 최대 합
        /*
            k=3라고 하면, dp[i]는
            1. dp[i-1] + arr[i] * 1
            2. dp[i-2] + max(arr[i-1], arr[i]) * 2
            3. dp[i-3] + max(arr[i-2], arr[i-1], arr[i]) * 3
            중에서의 최댓값이다.
        */

        int n = arr.size();
        vector<int> dp(n);

        // 0 ~ k-1 까지는 길이가 조절이 자유로우므로 초기화를 0~k-1까지 한다.
        dp[0] = arr[0];
        int max_val = arr[0];
        for (int i = 1; i < k; i++)
        {
            max_val = max(max_val, arr[i]);
            dp[i] = max_val * (i + 1);
        }

        // k인덱스부터는 앞 방향으로 구분을 늘려가면서 최댓값을 찾는다.
        for (int i = k; i < n; i++)
        {
            int subArrayMax = arr[i]; // 현재 구간내에서의 최댓값
            for (int subArraySize = 1; subArraySize <= k; subArraySize++)
            {
                subArrayMax = max(subArrayMax, arr[i - subArraySize + 1]);
                dp[i] = max(dp[i], dp[i - subArraySize] + subArrayMax * subArraySize);
            }
        }

        return dp[n - 1];
    }
};