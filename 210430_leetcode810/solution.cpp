class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int sum = 0;
        for(int n : nums)
            sum ^= n;
        return (nums.size()%2 == 0) || (sum==0);
    }
};