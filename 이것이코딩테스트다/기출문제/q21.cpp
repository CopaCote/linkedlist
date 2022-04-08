// 국경선을 연다
// 인구이동을 시작한다 (DFS 혹은 BFS로 모든 인원수 합 구하기)
// 위를 반복.

// 풀이 이후에 답지를 보니 BFS를 하는 과정에서 미리 sum과 위치 정보 다 담아두고 인구이동을 바로 하는 방법이 있다.

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void movePeople(vector<vector<int>>& A, int unionIndex, vector<vector<int>>& unionNum){
    vector<vector<pair<int,int>>> u(unionIndex,vector<pair<int,int>>());
    for(int x=0;x<A.size();x++)
        for(int y=0;y<A.size();y++)
            u[unionNum[x][y]].push_back(make_pair(x,y));
    
    for(int i=0;i<u.size();i++){
        int sum = 0;
        for(auto n : u[i])
            sum += A[n.first][n.second];
        sum /= u[i].size();
        for(auto n : u[i])
            A[n.first][n.second] = sum;
    }
}

bool findUnion(vector<vector<int>>& A, int L, int R, vector<vector<int>>& unionNum){
    int unionIndex = 0;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A.size();j++){
            if(unionNum[i][j] == -1){

                // BFS 실행
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));

                while(!q.empty()){
                    pair<int,int> p = q.front();
                    q.pop();
                    unionNum[p.first][p.second] = unionIndex;

                    for(int dir = 0;dir<4;dir++){
                        int nx = p.first+dx[dir];
                        int ny = p.second+dy[dir];
                        if(nx >= 0 && nx < A.size() && ny >= 0 && ny < A.size()){
                            int dif = abs(A[p.first][p.second] - A[nx][ny]);
                            if(dif <= R && dif >= L && unionNum[nx][ny] == -1)
                                q.push(make_pair(nx,ny));
                        }
                    }
                }

                unionIndex++;
            }
        }
    }

    if(unionIndex != A.size()*A.size()){
        movePeople(A,unionIndex,unionNum);
        return true;
    }
    return false;
}

int main(){
    int N, L, R;
    cin >> N >> L >> R;

    vector<vector<int>> A(N,vector<int>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int n;
            cin >> n;
            A[i][j] = n;
        }
    }

    int ans = 0;
    while(true){
        vector<vector<int>> unionNum(N,vector<int>(N,-1));
        if(!findUnion(A,L,R,unionNum))
            break;
        ans++;
    }
    cout << ans << endl;
    return 0;
}