#include <iostream>
#include <string>

using namespace std;

int main(){
    int N; // 시
    cin >> N;

    int hour= 0;
    int min = 0;
    int sec = 0;
    int ans = 0;
    while(hour <= N){
        string time = to_string(hour) + to_string(min) + to_string(sec);
        if(time.find("3") != string::npos)
            ans++;
        
        sec = (sec+1)%60;
        if(sec == 0){
            min = (min+1)%60;
            if(min == 0)
                hour++;
        }
    }
    cout << "Ans : " << ans << endl;
    return 0;
}