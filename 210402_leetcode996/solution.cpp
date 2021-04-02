class Solution
{
public:
    int numSquarefulPerms(vector<int> &A)
    {
        vector<int> result;
        bool *visited = new bool[A.size()]{0};
        int ans = 0;

        sort(A.begin(), A.end());

        for (int i = 0; i < A.size(); i++)
        {
            if (i > 0 && A[i] == A[i - 1])
                continue;
            visited[i] = true;
            result.push_back(A[i]);
            dfs(A, visited, result, ans);
            visited[i] = false;
        }
        delete[] visited;
        return ans;
    }

    void dfs(vector<int> &A, bool *visited, vector<int> &result, int &ans)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if (visited[i])
                continue;
            if (i > 0 && (A[i] == A[i - 1]) && visited[i - 1] == false)
                continue;

            if (checkSquare(A[i] + result.back()))
            {
                visited[i] = true;
                result.push_back(A[i]);
                dfs(A, visited, result, ans);
                visited[i] = false;
            }
        }
        if (result.size() == A.size())
            ans++;
        result.pop_back();
    }

    bool checkSquare(int n)
    {
        int i = 0;
        while (i * i <= n)
        {
            if (n == i * i)
                return true;
            i++;
        }
        return false;
    }
};