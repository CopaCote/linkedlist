class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int t = max(grid[0][0], grid[grid.size() - 1][grid[0].size() - 1]);
        /*int t1 = max(grid[0][0],grid[grid.size()-1][grid[0].size()-1]); // MIN heigh
        int t2 = grid.size()*grid[0].size()-1; // MAX height
        int result = t2;*/
        bool **visited = (bool **)malloc(sizeof(bool *) * grid.size());

        for (int i = 0; i < grid.size(); i++)
        {
            visited[i] = (bool *)malloc(sizeof(bool) * grid[0].size());
            memset(visited[i], 0, sizeof(bool) * grid[0].size());
        }
        /*
        while(t1<=t2){
            for(int i=0;i<grid.size();i++)
                memset(visited[i],0,sizeof(bool)*grid[0].size());
            if(reccur((t1+t2)/2, 0,0,grid.size()-1, grid[0].size()-1, grid, visited))
            {
                result = (t1+t2)/2;
                t2 = (t1+t2)/2-1;
            }
            else
                t1 = (t1+t2)/2+1;
        }*/

        while (!reccur(t, 0, 0, grid.size() - 1, grid[0].size() - 1, grid, visited))
        {
            for (int i = 0; i < grid.size(); i++)
                memset(visited[i], 0, sizeof(bool) * grid[0].size());
            t++;
        }
        //return result;
        return t;
    }

    bool reccur(int time, int x, int y, int x_end, int y_end, vector<vector<int>> &grid, bool **visited)
    {
        bool ret = false;
        visited[x][y] = true;
        if (x == x_end && y == y_end)
            return true;

        if (!ret && y > 0 && !visited[x][y - 1] && grid[x][y - 1] <= time) //check top
            ret = reccur(time, x, y - 1, x_end, y_end, grid, visited);
        if (!ret && y < y_end && !visited[x][y + 1] && grid[x][y + 1] <= time) //check bottom
            ret = reccur(time, x, y + 1, x_end, y_end, grid, visited);
        if (!ret && x > 0 && !visited[x - 1][y] && grid[x - 1][y] <= time) //check left
            ret = reccur(time, x - 1, y, x_end, y_end, grid, visited);
        if (!ret && x < x_end && !visited[x + 1][y] && grid[x + 1][y] <= time) //check right
            ret = reccur(time, x + 1, y, x_end, y_end, grid, visited);
        //visited[x][y] = false; 문제의 코드
        return ret;
    }
};