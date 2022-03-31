#include <iostream>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    int ans = 0;

    while(N > 1){
        if(N%K==0)
            N/=K;
        else
            N--;
        ans++;
    }
    cout << "Ans : " << ans << endl;
    return 0;
}