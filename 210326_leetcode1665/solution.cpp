class Solution
{
public:
    int minimumEffort(vector<vector<int>> &tasks)
    {
        sort(tasks.begin(), tasks.end(), [](vector<int> &p, vector<int> &q) { return p[1] - p[0] > q[1] - q[0]; });

        int min = tasks[0][1];
        int curr = tasks[0][1] - tasks[0][0];

        for (int i = 1; i < tasks.size(); i++)
        {
            if (curr < tasks[i][1])
            {
                min += tasks[i][1] - curr;
                curr = tasks[i][1] - tasks[i][0];
            }
            else
                curr -= tasks[i][0];
        }
        return min;
    }
};