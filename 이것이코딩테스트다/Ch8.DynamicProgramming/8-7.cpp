#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;

    /*
    2*1, 1*2, 2*2
    1칸을 채우는 경우 : 2*1 1개 1가지 경우의 수
    2칸을 채우는 경우 : 1*2 2개 or 2*2 1개 2가지 경우의 수 / 2*1 2개 채우는건 1칸 채우는거 중복이라서 무시
    
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