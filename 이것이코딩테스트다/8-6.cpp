#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> v(N,0);
    vector<int> dp(N,0);

    for(int i=0;i<N;i++)
        cin >> v[i];

    dp[0] = v[0];
    dp[1] = max(v[0],v[1]);
    for(int i=2;i<v.size();i++)
        dp[i] = max(dp[i-1], dp[i-2]+v[i]);
    cout << "Ans : " << dp[N-1] << endl;
    return 0;
}