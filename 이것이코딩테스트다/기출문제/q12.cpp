/*
���� ����� �����ϴ� �� true false�� ��ȯ�ϴ� �Լ��� �����,
�߰��Ҷ��� �ش� �͸� üũ�غ��� �߰�.
������ �����Ҷ� �̸� �������� üũ�� �ڿ� ��ΰ� �����ϴٰ� �ϸ� ����
�ϳ��� �Ұ����� ���� ���´ٸ� �ٽ� ����ְ� ����.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ����� �ٴ� ���� �ְų� ���� ���� ���κ� ���� �ְų�, �Ǵ� �ٸ� ��� ���� �־���մϴ�.
bool checkPillar(int x, int y, vector<vector<vector<int>>>& house){
    bool able = false;
    // �ٴ� ��
    if(y == 0)
        able = true;
    // ���� ���� ���κ� -> x,y(���ʳ�) or x-1,y(�����ʳ�)�� ��
    else if(find(house[x][y].begin(),house[x][y].end(),1) != house[x][y].end())
        able = true;
    else if(x > 0 && find(house[x-1][y].begin(),house[x-1][y].end(),1) != house[x-1][y].end())
        able = true;
    // �ٸ� ��� �� -> x,y-1�� ���
    else if(y > 0 && find(house[x][y-1].begin(),house[x][y-1].end(),0) != house[x][y-1].end())
        able = true;
    return able;
}


void addPillar(int x, int y, vector<vector<vector<int>>>& house){
    bool able = checkPillar(x,y,house);
    if(able)
        house[x][y].push_back(0);
}
// ���� ���� ���κ��� ��� ���� �ְų�, �Ǵ� ���� ���κ��� �ٸ� ���� ���ÿ� ����Ǿ� �־�� �մϴ�.
bool checkRoof(int x, int y, vector<vector<vector<int>>>& house){
    bool able = false;
    // ���� ���κ��� ������� -> x+1, y-1�� ��� or x, y-1�� ���
    if(find(house[x+1][y-1].begin(),house[x+1][y-1].end(),0) != house[x+1][y-1].end())
        able = true;
    else if(find(house[x][y-1].begin(),house[x][y-1].end(),0) != house[x][y-1].end())
        able = true;
    // ���� ���κ��� �ٸ� ���� ���ÿ� ���� -> x-1,y�� x+1,y�� ��
    else if(x > 0 && x<house.size() && find(house[x-1][y].begin(),house[x-1][y].end(),1) != house[x-1][y].end() && find(house[x+1][y].begin(),house[x+1][y].end(),1) != house[x+1][y].end())
        able = true;
    return able;
}

void addRoof(int x, int y, vector<vector<vector<int>>>& house){
    bool able = checkRoof(x,y,house);
    if(able)
        house[x][y].push_back(1);
}

void checkRemove(int x, int y, int type, vector<vector<vector<int>>>& house){
    for(auto i=house[x][y].begin(); i!=house[x][y].end() ; i++)
        if(*i == type){
            house[x][y].erase(i);
            break;
        }
    
    for(int i = 0 ; i<house.size();i++){
        for(int j = 0 ; j<house[0].size();j++){
            for(auto t : house[i][j]){
                bool able;
                if(t == 0)
                    able = checkPillar(i,j,house);
                else
                    able = checkRoof(i,j,house);
                if(!able){
                    house[x][y].push_back(type);
                    return;
                }
            }
        }
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    vector<vector<vector<int>>> house(n+1,vector<vector<int>>(n+1,vector<int>()));
    
    for(int i=0;i<build_frame.size();i++){
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        
        if(b == 1){
            if(a == 0)
                addPillar(x,y,house);
            else
                addRoof(x,y,house);
        }else{
            checkRemove(x,y,a,house);
        }
    }
    for(int x=0;x<house.size();x++){
        for(int y=0;y<house[0].size();y++){
            sort(house[x][y].begin(),house[x][y].end());
            for(auto t : house[x][y]){
                vector<int> v;
                v.push_back(x);
                v.push_back(y);
                v.push_back(t);
                answer.push_back(v);
            }
        }
    }
    
    return answer;
}