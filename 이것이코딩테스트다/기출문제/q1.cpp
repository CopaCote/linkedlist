// 공포도 문제
/*
공포도가 X인 모험가는 X명이상으로 출발해야한다.
공포도가 낮은 사람부터 묶어서 최소값 X명으로 출발
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> v;
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }    
    sort(v.begin(),v.end());

    int result = 0;
    int count = 0;
    for(int i=0;i<N;i++){
        count++;
        if(count == v[i]){
            result++;
            count = 0;
        }
    }
    cout << result << endl;
    return 0;
}