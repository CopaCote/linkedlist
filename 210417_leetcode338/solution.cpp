class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> dp;
        dp.reserve(num + 1);

        dp.push_back(0); // dp[0] = 0

        int i = 1;
        int curr = 1;
        int next = curr * 2;

        while (curr <= num)
        {
            for (int i = curr; i < next && i <= num; i++)
            {
                dp.push_back(1 + dp[i - curr]);
            }
            curr *= 2;
            next *= 2;
        }
        return dp;
    }
};