// C++ 코드로 해도 정상작동하는데, cin cout endl에서 속도저하가 일어나서 계속 시간초과 발생.
// 어쩔수없이 scanf, printf로 전환

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    
    vector<tuple<int,int,int,string>> v;
    for(int i=0;i<N;i++){
        char s[11];
        int a, b, c;
        scanf("%s %d %d %d",s,&a,&b,&c);
        v.push_back(make_tuple(-a,b,-c,s));
    }
    sort(v.begin(),v.end());
    
    for(auto s : v)
        printf("%s\n",get<3>(s).c_str());
    return 0;
}