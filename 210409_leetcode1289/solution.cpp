class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &arr)
    {
        int dp[arr.size()][arr[0].size()];

        for (int i = 0; i < arr[0].size(); i++)
            dp[0][i] = arr[0][i];

        for (int i = 1; i < arr.size(); i++)
        {
            for (int j = 0; j < arr[0].size(); j++)
            {
                int dpMin = 0;
                if (j == 0)
                    dpMin = *min_element(&dp[i - 1][j + 1], &dp[i - 1][arr[0].size()]);
                else if (j == arr[0].size() - 1)
                    dpMin = *min_element(&dp[i - 1][0], &dp[i - 1][j]);
                else
                    dpMin = min(*min_element(&dp[i - 1][j + 1], &dp[i - 1][arr[0].size()]), *min_element(&dp[i - 1][0], &dp[i - 1][j]));
                dp[i][j] = dpMin + arr[i][j];
            }
        }
        return *min_element(&dp[arr.size() - 1][0], &dp[arr.size() - 1][arr[0].size()]);
    }
};