class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        vector<bool> opened(rooms.size());
        queue<int> keys;
        int count = 0;

        opened[0] = true;
        for (int i : rooms[0])
            keys.push(i);

        while (!keys.empty())
        {
            int i = keys.front();
            int count = 0;
            keys.pop();

            if (opened[i] == false)
            {
                opened[i] = true;
                for (int j : rooms[i])
                    keys.push(j);
            }
        }
        for (bool b : opened)
            if (b)
                count++;
        return count == rooms.size();
    }
};