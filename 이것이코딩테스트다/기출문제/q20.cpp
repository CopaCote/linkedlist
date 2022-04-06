// 감시망은 반복문을 쓰거나 재귀함수로 같은 방향으로 계속 찾아보도록 코딩
// 모든 경우의 수를 그냥 깔아봐야 하는 문제

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool DFS(int x, int y, int dir, vector<vector<char>>& map){
    if(x < 0 || x >= map.size() || y < 0 || y >= map.size())
        return true;
    if(map[x][y] == 'O' || map[x][y] == 'T')
        return true;
    if(map[x][y] == 'S')
        return false;
    
    return DFS(x+dx[dir],y+dy[dir],dir,map);
}

bool startDFS(vector<vector<char>>& map){
    for(int i=0;i<map.size();i++)
        for(int j=0;j<map.size();j++)
            if(map[i][j] == 'T')
                for(int dir=0;dir<4;dir++)
                    if(!DFS(i+dx[dir],j+dy[dir],dir,map))
                        return false;
    return true;
}

int main(){
    int N;
    cin >> N;

    vector<vector<char>> map(N,vector<char>(N));
    vector<pair<int,int>> spaces;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            char c;
            cin >> c;
            map[i][j] = c;
            if(c == 'X')
                spaces.push_back(make_pair(i,j));
        }
    }

    vector<int> perm;
    for(int i=0;i<spaces.size()-3;i++)
        perm.push_back(0);
    for(int i=0;i<3;i++)
        perm.push_back(1);

    do{
        vector<pair<int,int>> toRemove;
        for(int i=0;i<perm.size();i++)
            if(perm[i] == 1)
                toRemove.push_back(spaces[i]);
        
        for(auto a : toRemove)
            map[a.first][a.second] = 'O';
        if(startDFS(map)){
            cout << "YES" << endl;
            return 0;
        }
        for(auto a : toRemove)
            map[a.first][a.second] = 'X';
    }while(next_permutation(perm.begin(),perm.end()));

    cout << "NO" << endl;
    return 0;

}