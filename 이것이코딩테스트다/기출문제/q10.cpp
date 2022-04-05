#include <string>
#include <vector>


using namespace std;

// Key를 회전하는 코드
// x,y -> M-y,x로 변환시킨다.
vector<vector<int>> spin(vector<vector<int>>& key){
    vector<vector<int>> newKey(key.size(),vector<int>(key.size()));
    for(int i=0;i<key.size();i++)
        for(int j=0;j<key.size();j++)
            newKey[key.size()-1-j][i] = key[i][j];
    return newKey;
}

bool check(vector<vector<int>>& key, vector<vector<int>> lock, int x, int y){
    // x, y 는 Lock에 대한 Key의 상대좌표
    // Key의 상대범위는 x~x+M-1, y~y+M-1
    for(int i=0;i<key.size();i++)
        for(int j=0;j<key.size();j++)
            if(x+i >= 0 && x+i < lock.size() && y+j >= 0 && y+j < lock.size())
                lock[x+i][y+j] += key[i][j];

    for(int i=0;i<lock.size();i++)
        for(int j=0;j<lock.size();j++)
            if(lock[i][j] != 1)
                return false;
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

    // 상대위치를 바꿔보면서 대조
    for(int i=0;i<4;i++){
        for(int x=1-(int)key.size();x<(int)lock.size();x++)
            for(int y=1-(int)key.size();y<(int)lock.size();y++){
                if(check(key,lock,x,y))
                    return true;
            }
        key = spin(key);
    }
    
    return false;
}