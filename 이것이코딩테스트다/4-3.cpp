#include <iostream>
#include <string>

using namespace std;

int dx[8] = {-2,-1,1,2,2,1,-1,-2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

bool checkBound(int x, int y){
    return x>0 && y>0 && x<=8 && y<=8;
}

int main(){
    string start;
    cin >> start;

    int x = start[1]-'1';
    int y = start[0]-'a';

    int ans=0;
    for(int i=0;i<8;i++)
        if(checkBound(x+dx[i],y+dy[i]))
            ans++;

    cout << "Ans : " << ans << endl;
    return 0;
}