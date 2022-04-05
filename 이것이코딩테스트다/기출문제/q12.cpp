/*
보와 기둥을 만족하는 지 true false로 반환하는 함수를 만들고,
추가할때는 해당 것만 체크해보고 추가.
삭제를 실행할때 미리 지워보고 체크한 뒤에 모두가 가능하다고 하면 삭제
하나라도 불가능한 것이 나온다면 다시 집어넣고 종료.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 기둥은 바닥 위에 있거나 보의 한쪽 끝부분 위에 있거나, 또는 다른 기둥 위에 있어야합니다.
bool checkPillar(int x, int y, vector<vector<vector<int>>>& house){
    bool able = false;
    // 바닥 위
    if(y == 0)
        able = true;
    // 보의 한쪽 끝부분 -> x,y(왼쪽끝) or x-1,y(오른쪽끝)가 보
    else if(find(house[x][y].begin(),house[x][y].end(),1) != house[x][y].end())
        able = true;
    else if(x > 0 && find(house[x-1][y].begin(),house[x-1][y].end(),1) != house[x-1][y].end())
        able = true;
    // 다른 기둥 위 -> x,y-1가 기둥
    else if(y > 0 && find(house[x][y-1].begin(),house[x][y-1].end(),0) != house[x][y-1].end())
        able = true;
    return able;
}


void addPillar(int x, int y, vector<vector<vector<int>>>& house){
    bool able = checkPillar(x,y,house);
    if(able)
        house[x][y].push_back(0);
}
// 보는 한쪽 끝부분이 기둥 위에 있거나, 또는 양쪽 끝부분이 다른 보와 동시에 연결되어 있어야 합니다.
bool checkRoof(int x, int y, vector<vector<vector<int>>>& house){
    bool able = false;
    // 한쪽 끝부분이 기둥위에 -> x+1, y-1이 기둥 or x, y-1이 기둥
    if(find(house[x+1][y-1].begin(),house[x+1][y-1].end(),0) != house[x+1][y-1].end())
        able = true;
    else if(find(house[x][y-1].begin(),house[x][y-1].end(),0) != house[x][y-1].end())
        able = true;
    // 양쪽 끝부분이 다른 보와 동시에 연결 -> x-1,y과 x+1,y이 보
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