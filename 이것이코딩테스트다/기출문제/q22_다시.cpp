#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Robot{
public:
    int x1;
    int x2;
    int y1;
    int y2;
    int t;
    int dir; // 0 == 하, 1 == 우, 2 == 상, 3 == 좌
    Robot(int x1, int y1, int x2, int y2, int t) : x1(x1), x2(x2), y1(y1), y2(y2), t(t){}
};

bool isGoal(Robot& r, int N){
    return (r.x1 == N && r.y1 == N) || (r.x2 == N && r.y2 == N);
}

int pathFind(vector<vector<int>>& map){

    // Queue에 들어갈거, 현재 위치(2점), 시간값
    queue<Robot> q;
    q.push(Robot(1,1,1,2,0));

    while(!q.empty()){
        Robot r = q.front();
        q.pop();

        if(isGoal(r,map.size()-1))
            return r.t;
        
        // 경우의 수는 6가지 상하좌우 이동 + 시계반시계 회전
        

    }
    return -1;
}

int main(){


    return 0;
}