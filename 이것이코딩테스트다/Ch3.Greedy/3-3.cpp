#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> arr;

    for(int i=0;i<N;i++){
        vector<int> v;
        int t;
        for(int j=0;j<M;j++){
            cin >> t;
            v.push_back(t);
        }
        arr.push_back(v);
    }

    vector<int> ans;
    for(vector<int>& v : arr)
        ans.push_back(*min_element(v.begin(),v.end()));
    int maxVal = *max_element(ans.begin(),ans.end());
    cout << "Ans : " << maxVal << endl;
    return 0;
}