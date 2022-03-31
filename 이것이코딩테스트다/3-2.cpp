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
    
    // M / (K+1) = ����Ŭ ��
    // M / (K+1) * K + M % (K+1) = ���� �������� �������� Ƚ��
    // M / (K+1) = �ι�°�� ���� ���� �������� Ƚ��
    int first = (M / (K+1) * K + M % (K+1))*arr[0];
    int second = M / (K+1) * arr[1];
    cout << "Ans : " << first+second << endl;

    return 0;
}