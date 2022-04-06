#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(){
    int N, K;
    cin >> N >> K;

    vector<vector<int>> v(N+1,vector<int>(N+1));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int n;
            cin >> n;
            v[i][j] = n;
        }
    }

    int S,X,Y;
    cin >> S >> X >> Y;

    queue<tuple<int,int,int,int>> q;
    vector<tuple<int,int,int,int>> temp;
    for(int x=1;x<=N;x++)
        for(int y=1;y<=N;y++)
            if(v[x][y] != 0)
                temp.push_back(make_tuple(v[x][y],x,y,0));
    sort(temp.begin(),temp.end());
    for(auto tup : temp)
        q.push(tup);

    while(!q.empty()){
        auto tup = q.front();
        q.pop();

        if(get<3>(tup) == S)
            break;

        for(int i=0;i<4;i++){
            int nx = get<1>(tup) + dx[i];
            int ny = get<2>(tup) + dy[i];

            if(nx > 0 && nx <= N && ny > 0 && ny <= N && v[nx][ny] == 0){
                v[nx][ny] = get<0>(tup);
                q.push(make_tuple(get<0>(tup),nx,ny,get<3>(tup)+1));
            }
        }
    }

    cout << v[X][Y] << endl;

    return 0;
}