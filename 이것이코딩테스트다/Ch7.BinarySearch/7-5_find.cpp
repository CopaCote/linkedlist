#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N,M;
    cin >> N;
    vector<int> v;

    for(int i=0;i<N;i++){
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());

    cin >> M;
    for(int i=0;i<M;i++){
        int t;
        cin >> t;
        if(find(v.begin(),v.end(),t) != v.end())
            cout << "yes ";
        else
            cout << "no ";
    }
    cout << endl;
    return 0;
}