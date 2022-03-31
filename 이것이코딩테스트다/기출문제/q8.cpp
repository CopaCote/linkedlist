#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string s;
    cin >> s;
    sort(s.begin(),s.end());

    int sum = 0;
    for(auto c : s){
        if(c >= '0' && c <= '9')
            sum += c-'0';
        else
            cout << c;
    }
    cout << sum << endl;
    return 0;
}