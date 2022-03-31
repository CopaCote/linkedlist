// 볼링공 고르기
// NP2 - 같은 볼링공경우의 수(xP2)

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int ball[11] ={0,};
    int N, M;
    cin >> N >> M;

    for(int i=0;i<N;i++){
        int weight;
        cin >> weight;
        ball[weight]++;
    }

    int result = N*(N-1)/2;
    for(int i=1;i<11;i++){
        if(ball[i] > 1)
            result -= ball[i]*(ball[i]-1)/2;
    }
    cout << result << endl;

    return 0;
}