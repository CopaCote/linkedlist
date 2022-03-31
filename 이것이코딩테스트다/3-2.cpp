#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N,M,K;
    cin >> N >> M >> K;
    vector<int> arr(N);
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }

    sort(arr.begin(),arr.end(),greater<int>());
    
    // M / (K+1) = 싸이클 수
    // M / (K+1) * K + M % (K+1) = 가장 높은수가 더해지는 횟수
    // M / (K+1) = 두번째로 높은 수가 더해지는 횟수
    int first = (M / (K+1) * K + M % (K+1))*arr[0];
    int second = M / (K+1) * arr[1];
    cout << "Ans : " << first+second << endl;

    return 0;
}