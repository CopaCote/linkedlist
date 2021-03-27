class Solution
{
public:
    int minimumOneBitOperations(int n)
    {
        int mask = 0x20000000; // Maximum Bit Used
        int sign = 1;          // + or -
        int totalOps = 0;
        while (mask > 0)
        {
            if ((mask & n) != 0)
            {
                totalOps += sign * (mask * 2 - 1);
                sign *= -1;
            }
            mask /= 2;
        }
        return totalOps;
    }
};