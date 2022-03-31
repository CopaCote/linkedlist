// 곱하기 혹은 더하기
/*
왼쪽부터 순서대로 연산을 하는데,
0,1이면 덧셈, 그 외의 모든 경우는 곱셈을 하면된다.
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;

    int result = 0;
    for(int c : s){
        c = c-'0'; // to int
        if(result <= 1 || c <= 1)
            result += c;
        else
            result *= c;
    }
    cout << result << endl;
    return 0;
}