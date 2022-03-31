#include <iostream>
#include <vector>

using namespace std;

int findTeam(vector<int>& team, int x){
    if(team[x] != x)
        team[x] = findTeam(team,team[x]);
    return team[x];
}

void unionTeam(vector<int>& team, int a, int b){
    a = findTeam(team, a);
    b = findTeam(team, b);

    if(a < b)
        team[b] = a;
    else
        team[a] = b;
}

int main(){
    int N, M;
    cin >> N >> M;
    
    vector<int> team(N+1);
    for(int i=0;i<N+1;i++)
        team[i] = i;
    
    for(int i=0;i<M;i++){
        int op, a, b;
        cin >> op >> a >> b;
        
        if(op == 0){
            unionTeam(team, a, b);
        }else if(op == 1){
            if(findTeam(team,a) == findTeam(team,b))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}