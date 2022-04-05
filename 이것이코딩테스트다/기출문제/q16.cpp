#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

using namespace std;

void spread(int x, int y, vector<vector<int>>& map){
    if(x < 1 || x >= map.size() || y < 1 || y>=map[0].size())
        return;
    if(map[x][y] == 0){
        map[x][y] = 2;
        spread(x-1,y, map);
        spread(x+1,y, map);
        spread(x,y-1, map);
        spread(x,y+1, map);
    }
}

int startSpread(vector<pair<int,int>>& walls, vector<vector<int>> map){
    // 벽 세우기
    for(auto wall : walls)
        map[wall.first][wall.second] = 1;

    // 확산
    for(int i=1;i<map.size();i++){
        for(int j=1;j<map[0].size();j++){
            if(map[i][j] == 2){
                spread(i+1,j,map);
                spread(i-1,j,map);
                spread(i,j+1,map);
                spread(i,j-1,map);
            }
        }
    } 

    // 안전구역 카운트
    int count = 0;
    for(int i=1;i<map.size();i++)
        for(int j=1;j<map[0].size();j++)
            if(map[i][j] == 0)
                count++;
    return count;
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<int>> v(N+1, vector<int>(M+1));
    vector<pair<int,int>> emptySpace;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            int n;
            cin >> n;
            v[i][j] = n;
            if(n == 0)
                emptySpace.push_back(make_pair(i,j));
        }
    }

    vector<int> perm;
    for(int i=0;i<emptySpace.size()-3;i++)
        perm.push_back(0);
    for(int i=0;i<3;i++)
        perm.push_back(1);

    int maxSafe = 0;
    do{
        vector<pair<int,int>> walls;
        for(int i=0;i<perm.size();i++){
            if(perm[i] == 1)
                walls.push_back(emptySpace[i]);
        }
        maxSafe = max(maxSafe, startSpread(walls,v));
    }while(next_permutation(perm.begin(),perm.end()));
    cout << maxSafe << endl;

    return 0;
}