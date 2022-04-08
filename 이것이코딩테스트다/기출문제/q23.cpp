// C++ �ڵ�� �ص� �����۵��ϴµ�, cin cout endl���� �ӵ����ϰ� �Ͼ�� ��� �ð��ʰ� �߻�.
// ��¿������ scanf, printf�� ��ȯ

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