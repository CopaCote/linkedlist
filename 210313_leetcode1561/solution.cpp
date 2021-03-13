class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        int answer = 0;
        std::sort(piles.begin(), piles.end());

        vector<int>::iterator bob = piles.begin();
        vector<int>::iterator alice = --piles.end();

        while (1)
        {
            alice--;
            bob++;
            answer += *alice;
            if (alice == bob)
                break;
            alice--;
        }
        return answer;
    }
};