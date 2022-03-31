#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int>& v, int target){
    int left = 0;
    int right = v[v.size()-1];

    while(left <= right){
        int mid = (left+right) / 2;
        int cutSum = 0;
        for(auto n : v)
            cutSum += (n - mid) > 0 ? n-mid : 0;
        if(cutSum == target)
            return mid;
        else if(cutSum < target)
            right = mid-1;
        else
            left = mid+1;
    }
    return (left+right) / 2;
}

int main(){
    int N,M;
    vector<int> v;
    cin >> N >> M;

    for(int i=0;i<N;i++){
        int n;
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(),v.end());
    cout << "Ans : " << binarySearch(v,M) << endl;

    return 0;
}