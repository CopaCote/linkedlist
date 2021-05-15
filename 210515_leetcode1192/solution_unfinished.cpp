class Solution
{
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adjList(n);
        vector<int> parentNum(n, -1);
        vector<bool> visited(n);
        vector<vector<int>> output;

        for (vector<int> &v : connections)
        {
            adjList[v[0]].push_back(v[1]);
            adjList[v[1]].push_back(v[0]);
        }

        dfs(0, -1, parentNum, adjList, visited, output);
        return output;
    }

    void dfs(int curr, int parent, vector<int> &parentNum, vector<vector<int>> &adjList, vector<bool> &visited, vector<vector<int>> &output)
    {
        parentNum[curr] = curr;
        visited[curr] = true;
        for (int n : adjList[curr])
        {
            if (n == parent)
                continue;
            if (!visited[n])
                dfs(n, curr, parentNum, adjList, visited, output);
            parentNum[curr] = min(parentNum[curr], parentNum[n]);
            // if(??????){
            //     output.push_back({curr,n});
            // }
        }
    }
};