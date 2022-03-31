#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


/*
    ��������+�켱����ť �̿�.
    ������ 0�� ���ǵ��� ���� ���� ��û������ ���ǵ�
    ������ 0�� �Ǹ� �ҿ�ð� + ���� ����ִ� ���� �ð�.
    �̹�ȸ���� ������ �ҿ�ð� ���
    ť�� �׻� ������������ ���� (�ִ��� �������� ������).

    1�� ����
    Queue : 2 1
    3�� ������ 0�� �ɶ� 3�����ǿ� +30�ð�
    ������ 3�� ���� �ð� 70�ð� ���.

    2�� ����
    1���� 10�ð�
    2���� 10�ð� ���� 1
    3���� 4�ð� ���� 1
    4���� 4�ð� ���� 1 3
    5���� 3�ð� ���� 3
    Queue : 1
    Queue : 3(14) 2(20)
    Queue : 5(17) 4(18) 2(20)
    
    ���
    1���� 10�ð�
    2���� 20�ð�
    3���� 14�ð�
    4���� 18�ð�
    5���� 17�ð�


    å Ǯ�̰��� : ��� �ִ��� ����ϴ� ������� ����.
*/

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<vector<int>> graph(N+1,vector<int>()); // ��������Ʈ
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

            // �ٽ�
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
