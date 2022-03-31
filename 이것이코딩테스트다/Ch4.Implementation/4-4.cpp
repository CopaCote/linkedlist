#include <iostream>
#include <vector>

using namespace std;

// �ϼ�����
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

bool checkBound(int N, int M, int x, int y){
    return x>=0 && y>=0 && x<N && y<M;
}


int main(){
    vector<vector<int>> map;
    int N,M;
    cin >> N >> M;

    int x,y,dir;
    cin >> x >> y >> dir;
    dir = 4-dir; // �̵��� ���ϰ� �ϱ�����

    for(int i=0;i<N;i++){
        vector<int> v;
        int tmp;
        for(int j=0;j<M;j++){
            cin >> tmp;
            v.push_back(tmp);
        }
        map.push_back(v);
    }

    int ans=1;
    map[x][y] = 1;
    while(true){
        for(int i=0;i<4;i++){
            dir = (dir+1)%4; // 1�ܰ� ������ȯ

            // 2�ܰ� ������ ����ĭ�� ������ ����.
            if(checkBound(N,M,x+dx[dir],y+dy[dir]) && map[x+dx[dir]][y+dy[dir]]==0){
                x += dx[dir];
                y += dy[dir];
                map[x][y] = 1; // ����ǥ��
                ans++;
            }
        }

        // 3�ܰ�. ������ �����ϸ� �ڷ� �̵�
        if(checkBound(N,M,x-dx[dir],y-dy[dir]) && map[x-dx[dir]][y-dy[dir]]==0){
            x -= dx[dir];
            y -= dy[dir];
            map[x][y] = 1;
            ans++;
        }else
            break;
    }

    cout << "Ans : " << ans << endl;
    return 0;
}