#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> v;
    for(int i=0;i<N;i++){
        int t;
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(),v.end());
    cout << v[(v.size()-1)/2] << endl;

    return 0;
}