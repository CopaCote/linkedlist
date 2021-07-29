class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int left = *max_element(weights.begin(), weights.end());
        int right = 0;
        int mid;
        int min_weight = INT_MAX;
        for (int i : weights)
            right += i;

        while (left <= right)
        {
            int day = 1;
            int weight = 0;

            mid = (left + right) / 2;

            for (int i : weights)
            {
                if (weight + i > mid)
                {
                    day++;
                    weight = 0;
                }
                weight += i;
            }

            if (day > days)
                left = mid + 1;
            else
            {
                min_weight = min(min_weight, mid);
                right = mid - 1;
            }
        }
        return min_weight;
    }
};