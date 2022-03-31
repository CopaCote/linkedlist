#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void dfs(vector<string>& graph, int x, int y){
    // 방문처리
    graph[x][y] = '1';

    for(int i=0;i<4;i++){
        int nextX = x+dx[i];
        int nextY = y+dy[i];
        if(nextX >= 0 && nextX < graph.size() && nextY >= 0 && nextY < graph[0].size() && graph[nextX][nextY] == '0')
            dfs(graph,nextX,nextY);
    }
}


int main(){
    int N, M;
    cin >> N >> M;

    vector<string> input(N);
    for(int i=0;i<N;i++)
        cin >> input[i];

    int count = 0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(input[i][j] == '0'){
                dfs(input, i,j);
                count++;
            }
                
    cout << "Ans : " << count << endl;   
    return 0;
}