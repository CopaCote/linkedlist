#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

int main(){
    /*
    [x/5] + 1
    [x/3] + 1
    [x/2] + 1
    [x-1] + 1
    */
   int X;
   cin >> X;
   vector<int> dp(X+1,0);
    dp[1] = 0;
    for(int i=2;i<dp.size();i++){
        dp[i] = dp[i-1] + 1;
        if(i%5 == 0)
            dp[i] = min(dp[i/5]+1,dp[i]);
        if(i%3 == 0)
            dp[i] = min(dp[i/3]+1,dp[i]);
        if(i%2 == 0)
            dp[i] = min(dp[i/2]+1,dp[i]);
    }
    cout << "Ans : " << dp[X] << endl;
    return 0;
}