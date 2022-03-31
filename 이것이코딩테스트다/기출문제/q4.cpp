// 만들 수 없는 금액
/*
현재 확인하는 금액이 T이고, T-1까지의 금액은 모두 만들 수 있을때
새로들어온 동전 C가 T보다 작거나 같으면
모든 경우의 수에 C를 더한 값인 T+C-1까지 모든 금액도 만들 수 있다.
그러므로 다음 확인하는 금액은 T+C이다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> coins;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        coins.push_back(t);
    }
    sort(coins.begin(), coins.end());

    int T = 1;
    for (auto C : coins)
    {
        if (C > T)
            break;
        T += C;
    }
    cout << T << endl;

    return 0;
}