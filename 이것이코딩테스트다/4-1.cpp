#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// L, R, U, D 순
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

// 범위안에 있는지 체크
bool checkBound(int N, int x, int y){
    return x > 0 && y > 0 && x <= N && y <= N;
}


int main(){
    int N;
    cin >> N;
    cin.ignore();
    
    int x = 1;
    int y = 1;

    string move;
    getline(cin, move);

    // Split
    stringstream ss(move);
    string tmp;
    while(getline(ss,tmp, ' ')){
        // 구현부
        int dir = 0;
        switch(tmp[0]){
            case 'L':
                dir = 0;
                break;
            case 'R':
                dir = 1;
                break;
            case 'U':
                dir = 2;
                break;
            case 'D':
                dir = 3;
        }
        if(checkBound(N,x+dx[dir],y+dy[dir])){
            x += dx[dir];
            y += dy[dir];
        }
    }
    cout << "Ans : " << x << " " << y << endl;

    return 0;
}