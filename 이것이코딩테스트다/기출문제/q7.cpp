#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;

    int leftSum = 0;
    int rightSum = 0;
    for(int i=0;i<s.size()/2;i++)
        leftSum += s[i]-'0';
    for(int i=s.size()/2;i<s.size();i++)
        rightSum += s[i]-'0';
    if(leftSum == rightSum)
        cout << "LUCKY" << endl;
    else
        cout << "READY" << endl;

    return 0;
}