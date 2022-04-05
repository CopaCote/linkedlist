// 뱀
/*
이동을 할때의 두 판정
1. 사과가 있다 -> 머리에 새로운 위치 삽입
2. 사과가 없다 -> 머리에 새로운 위치 삽입 및 꼬리 제거
*/

#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <algorithm>

enum Direction{
    RIGHT = 0,
    DOWN = 1,
    LEFT = 2,
    UP = 3
};

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

using namespace std;

bool checkSelfCrash(list<pair<int,int>>& snake, pair<int,int> newpos){
    for(auto i : snake)
        if(i == newpos)
            return true;
    return false;
}

int main(){
    int N, K;
    cin >> N >> K;

    list<pair<int,int>> apple;
    for(int i=0;i<K;i++){
        int x, y;
        cin >> x >> y;
        apple.push_back(make_pair(x,y));
    }

    int L;
    cin >> L;
    list<pair<int,char>> moving;
    for(int i=0;i<L;i++){
        int t;
        char d;
        cin >> t >> d;
        moving.push_back(make_pair(t,d));
    }

    int time = 0;
    int dir = RIGHT;
    list<pair<int,int>> snake;
    snake.push_back(make_pair(1,1));

    auto movingIndex = moving.begin();
    while(true){
        time++;

        auto head = *(snake.begin());
        // 다음 이동할 위치
        int nx = head.first + dx[dir], ny = head.second + dy[dir];
        
        // 밖으로 나간 경우 게임 오버
        if(nx < 1 || nx > N || ny < 1 || ny > N)
            break;

        // 몸통에 박는경우 검사
        if(checkSelfCrash(snake,make_pair(nx,ny)))
            break;
        
        // 머리 추가
        snake.push_front(make_pair(nx,ny));

        // 사과 검사
        bool eat = false;
        for(auto i = apple.begin(); i != apple.end(); i++){
            if(*i == *snake.begin()){
                apple.erase(i);
                eat = true;
                break;
            }
        }
        // 사과를 먹지 않았을 경우 꼬리 제거
        if(!eat)
            snake.pop_back();

        // 방향전환 적용
        if(movingIndex != moving.end() && time == movingIndex->first){
            if(movingIndex->second == 'L')
                dir = (dir == 0) ? UP : dir-1;
            else
                dir = (dir+1)%4;
            movingIndex++;
        }
    }

    cout << time << endl;
    return 0;
}