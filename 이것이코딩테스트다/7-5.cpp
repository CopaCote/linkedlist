#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binarysearch(vector<int>& v, int target, int start, int end){
    if(start >  end)
        return false;

    int mid = (start+end) / 2;

    if(v[mid] == target)
        return true;
    else if(v[mid] > target)
        return binarysearch(v,target,start,mid-1);
    else
        return binarysearch(v,target,mid+1,end);
}

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
        if(binarysearch(v,t,0,v.size()-1))
            cout << "yes ";
        else
            cout << "no ";
    }
    cout << endl;
    return 0;
}