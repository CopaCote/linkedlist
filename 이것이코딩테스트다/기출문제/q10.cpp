#include <string>
#include <vector>


using namespace std;

// Key�� ȸ���ϴ� �ڵ�
// x,y -> M-y,x�� ��ȯ��Ų��.
vector<vector<int>> spin(vector<vector<int>>& key){
    vector<vector<int>> newKey(key.size(),vector<int>(key.size()));
    for(int i=0;i<key.size();i++)
        for(int j=0;j<key.size();j++)
            newKey[key.size()-1-j][i] = key[i][j];
    return newKey;
}

bool check(vector<vector<int>>& key, vector<vector<int>> lock, int x, int y){
    // x, y �� Lock�� ���� Key�� �����ǥ
    // Key�� �������� x~x+M-1, y~y+M-1
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

    // �����ġ�� �ٲ㺸�鼭 ����
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