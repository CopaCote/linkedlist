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
    int dir; // 0 == ��, 1 == ��, 2 == ��, 3 == ��
    Robot(int x1, int y1, int x2, int y2, int t) : x1(x1), x2(x2), y1(y1), y2(y2), t(t){}
};

bool isGoal(Robot& r, int N){
    return (r.x1 == N && r.y1 == N) || (r.x2 == N && r.y2 == N);
}

int pathFind(vector<vector<int>>& map){

    // Queue�� ����, ���� ��ġ(2��), �ð���
    queue<Robot> q;
    q.push(Robot(1,1,1,2,0));

    while(!q.empty()){
        Robot r = q.front();
        q.pop();

        if(isGoal(r,map.size()-1))
            return r.t;
        
        // ����� ���� 6���� �����¿� �̵� + �ð�ݽð� ȸ��
        

    }
    return -1;
}

int main(){


    return 0;
}