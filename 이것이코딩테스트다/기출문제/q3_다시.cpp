// 풀다가 잘 안되서 넘어가고 나중에

#include <iostream>
#include <string>

using namespace std;

bool isSame(string& s){
    for(int i=1;i<s.size();i++)
        if(s[i-1] != s[i])
            return false;
    return true;
}

void flip(string::iterator a, string::iterator b){
    while(a != b){
        *a = (*a=='0') ? '1' : '0';
        a++;
    }
    *a = (*a=='0') ? '1' : '0';
}

int main(){
    string s;
    cin >> s;

    int result = 0;
    string::iterator l = s.begin(), r = s.end()-1;

    while(!isSame(s)){
        while(*l == *r)
            l++;
        while(*l != *r)
            r--;
        flip(l,r);
        result++;
    }
    cout << result << endl;
    return 0;
}