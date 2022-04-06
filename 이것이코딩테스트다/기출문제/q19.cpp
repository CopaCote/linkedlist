// 간단하게 모든 경우의 수를 뽑으면 되기는 한다.

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

int evaluate(vector<int>& nums, vector<int>& ops){
    int a = nums[0];
    int b = nums[1];
    int op = ops[0];

    switch(op){
        case 1:
            a += b;
            break;
        case 2:
            a -= b;
            break;
        case 3:
            a *= b;
            break;
        case 4:
            a /= b;
    }

    for(int i=2;i<nums.size();i++){
        b = nums[i];
        op = ops[i-1];

        switch(op){
            case 1:
                a += b;
                break;
            case 2:
                a -= b;
                break;
            case 3:
                a *= b;
                break;
            case 4:
                a /= b;
        }
    }
    return a;
}

int main(){
    int N;
    cin >> N;
    
    vector<int> nums(N);
    for(int i=0;i<N;i++){
        int n;
        cin >> n;
        nums[i] = n;
    }

    vector<int> ops;
    for(int i=1;i<=4;i++){
        int op;
        cin >> op;
        for(int j=0;j<op;j++)
            ops.push_back(i);
    }

    int MAXn = INT32_MIN;
    int MINn = INT32_MAX;
    do{
        int result = evaluate(nums,ops);
        MAXn = max(MAXn, result);
        MINn = min(MINn, result);
    }while(next_permutation(ops.begin(),ops.end()));

    cout << MAXn << endl << MINn << endl;
    return 0;
}