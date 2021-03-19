class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        int maxNum = 0;
        std::sort(satisfaction.begin(), satisfaction.end());

        for (int i = 0; i < satisfaction.size(); i++)
        {
            maxNum += (i + 1) * satisfaction[i];
        }

        for (int i = 0; i <= satisfaction.size(); i++)
        {
            int tempSat = 0;
            for (int j = i; j < satisfaction.size(); j++)
            {
                tempSat += (j - i + 1) * satisfaction[j];
            }
            if (tempSat > maxNum)
                maxNum = tempSat;
        }
        return maxNum;
    }
};