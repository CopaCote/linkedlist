#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main(){
    int nodes, vertices;
    cin >> nodes >> vertices;

    vector<vector<int>> graph(nodes+1, vector<int>(nodes+1,INT16_MAX));
    for(int i=1;i<=nodes;i++)
        graph[i][i] = 0;
    
    for(int i=0;i<vertices;i++){
        int from, to, dist;
        cin >> from >> to >> dist;
        graph[from][to] = dist;
    }

    // 거쳐갈 노드
    for(int i=1;i<=nodes;i++){
        for(int from=1;from<=nodes;from++){
            for(int to=1;to<=nodes;to++){
                if(from==to)
                    continue;
                int d1 = graph[from][i];
                int d2 = graph[i][to];
                graph[from][to] = min(graph[from][to], d1+d2);
            }
        }
    }

    for(int i=1;i<=nodes;i++){
        for(int j=1;j<=nodes;j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}