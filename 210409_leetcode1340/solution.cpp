class Solution
{
public:
    int maxJumps(vector<int> &arr, int d)
    {
        int dp[arr.size()];

        set<pair<int, int>> nums;
        for (int i = 0; i < arr.size(); i++)
            nums.insert(make_pair(arr[i], i));

        for (auto i : nums)
        {
            int j = i.second;
            int indices = 1;

            for (int k = j - 1; k >= max(0, j - d) && arr[k] < arr[j]; k--)
            {
                if (dp[k] + 1 > indices)
                    indices = dp[k] + 1;
            }
            for (int k = j + 1; k <= min((int)arr.size() - 1, j + d) && arr[k] < arr[j]; k++)
            {
                if (dp[k] + 1 > indices)
                    indices = dp[k] + 1;
            }
            dp[j] = indices;
        }
        return *max_element(dp, dp + arr.size());
    }
};