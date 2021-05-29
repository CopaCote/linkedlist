class Solution
{
public:
    int minimumBoxes(int n)
    {
        int height = 1;
        int maxBox = 1;
        int bottomBox = 1;
        while (maxBox < n)
        {
            height++;
            bottomBox = height * (height + 1) / 2;
            maxBox += bottomBox;
        }

        while (maxBox - height >= n)
        {
            bottomBox--;
            maxBox -= height;
            height--;
        }

        return bottomBox;
    }
};