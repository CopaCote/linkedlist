class Solution
{
public:
    int minimumBoxes(int n)
    {
        int left = 1, right = 1817; // Height
        int result = 1;
        while (left <= right)
        {
            int64_t mid = (left + right) / 2;
            int64_t boxes = (mid) * (mid + 1) * (mid + 2) / 6;
            if (boxes > n)
            { // Possible
                right = mid - 1;
            }
            else if (boxes < n)
            { // Impossible
                left = mid + 1;
                result = mid;
            }
            else
            {
                result = mid;
                break;
            }
        }

        int64_t totalBoxes = (result) * (result + 1) / 2 * (result + 2) / 3;
        int i = 1;
        while (totalBoxes < n)
        {
            bottom++;
            totalBoxes += i;
            i++;
        }
        return (int)bottom;
    }
};