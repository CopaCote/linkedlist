#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


/*
    위상정렬+우선순위큐 이용.
    차수가 0인 강의들이 현재 동시 시청가능한 강의들
    차수가 0이 되면 소요시간 + 지금 듣고있는 강의 시간.
    이번회차가 끝나면 소요시간 기록
    큐는 항상 오름차순으로 유지 (최댓값이 마지막에 나오게).

    1번 예시
    Queue : 2 1
    3번 차수가 0이 될때 3번강의에 +30시간
    마지막 3번 강의 시간 70시간 결과.

    2번 예시
    1과목 10시간
    2과목 10시간 선수 1
    3과목 4시간 선수 1
    4과목 4시간 선수 1 3
    5과목 3시간 선수 3
    Queue : 1
    Queue : 3(14) 2(20)
    Queue : 5(17) 4(18) 2(20)
    
    결과
    1과목 10시간
    2과목 20시간
    3과목 14시간
    4과목 18시간
    5과목 17시간


    책 풀이과정 : 결과 최댓값을 기록하는 방식으로 유지.
*/

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<vector<int>> graph(N+1,vector<int>()); // 인접리스트
    vector<int> length(N+1);
    vector<int> degree(N+1,0);

    for(int i=1;i<N+1;i++){
        int t;
        cin >> t;
        length[i] = t;

        while(true){
            int n;
            cin >> n;
            if(n == -1)
                break;
            graph[n].push_back(i);
            degree[i]++;
        }
    }

    queue<int> q;
    for(int i=1;i<N+1;i++)
        if(degree[i] == 0)
            q.push(i);

    vector<int> result = length; // deep copy
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int n : graph[cur]){
            degree[n]--;

            // 핵심
            result[n] = max(result[n] , result[cur] + length[n]);

            if(degree[n] == 0)
                q.push(n);
        }
    }

    for(int i=1;i<N+1;i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}
