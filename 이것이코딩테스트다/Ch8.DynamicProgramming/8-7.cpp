#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;

    /*
    2*1, 1*2, 2*2
    1ĭ�� ä��� ��� : 2*1 1�� 1���� ����� ��
    2ĭ�� ä��� ��� : 1*2 2�� or 2*2 1�� 2���� ����� �� / 2*1 2�� ä��°� 1ĭ ä��°� �ߺ��̶� ����
    
    f(1) = 1
    f(2) = 3
    */
    vector<int> dp(N+1, 0);
    dp[1] = 1;
    dp[2] = 3;
    for(int i=3;i<N+1;i++)
        dp[i] = (dp[i-1] + dp[i-2]*2) % 796796;

    cout << "Ans : " << dp[N] << endl;
    return 0;
}