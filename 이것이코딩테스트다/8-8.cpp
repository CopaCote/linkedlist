#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    
    vector<int> coins(N,0);
    for(int i=0;i<N;i++)
        cin >> coins[i];
    sort(coins.begin(),coins.end());

    vector<int> dp(M+1,INT32_MAX);

    for(int i=0;i<coins.size();i++)
        if(coins[i] < M+1)
            dp[coins[i]] = 1;

    for(int i=1;i<M+1;i++){
        for(int j=0;j<coins.size();j++){
            if(coins[j] > i)
                continue;
            if(dp[i-coins[j]] != INT32_MAX)
                dp[i] = min(dp[i-coins[j]]+1,dp[i]);
        }
    }

    /*
    dp[i] = 금액 i를 만들기 위한 최소 동전개수
    dp[i] = dp[i-coins] + 1 / 이때 dp[i-coins] != 0

    */
   if(dp[M] == INT32_MAX)
        dp[M] = -1;
    cout << "Ans : " << dp[M] << endl;
    return 0;
}