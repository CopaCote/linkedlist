#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <limits>
#include <algorithm>

using namespace std;

int dist(pair<int,int> a, pair<int,int> b){
    return abs(a.first-b.first) + abs(a.second-b.second);
}

int chickenDist(vector<pair<int,int>>& house, vector<pair<int,int>>& chicken){
    int total = 0;
    for(int i=0;i<house.size();i++){
        int minDist = INT32_MAX;
        for(int j=0;j<chicken.size();j++)
            minDist = min(minDist, dist(house[i],chicken[j]));
        total += minDist;
    }
    return total;
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<pair<int,int>> house;
    vector<pair<int,int>> chicken;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int n;
            cin >> n;
            if(n == 1)
                house.push_back(make_pair(i,j));
            else if(n == 2)
                chicken.push_back(make_pair(i,j));
        }
    }


    // Next_Permutation을 이용한 조합 출력
    vector<int> perm;
    for(int i=0;i<house.size()-M;i++)
        perm.push_back(0);
    for(int i=0;i<M;i++)
        perm.push_back(1);
    
    int minDist = INT32_MAX;

	do{
        vector<pair<int,int>> selected;
		for(int i=0; i<perm.size(); i++)
			if(perm[i] == 1)
                selected.push_back(chicken[i]);
        minDist = min(minDist,chickenDist(house,selected));
	}while(next_permutation(perm.begin(), perm.end()));

    cout << minDist << endl;
    return 0;
}