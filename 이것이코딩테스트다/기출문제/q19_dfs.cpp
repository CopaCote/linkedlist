#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int MAXn = INT32_MIN;
int MINn = INT32_MAX;

void calculate(int res, int index, vector<int>&nums, int a, int b, int c, int d){
    if(index == nums.size()){
        MAXn = max(MAXn,res);
        MINn = min(MINn,res);
    }

    if(a > 0) 
        calculate(res+nums[index],index+1,nums,a-1,b,c,d);
    if(b > 0)
        calculate(res-nums[index],index+1,nums,a,b-1,c,d);
    if(c > 0)
        calculate(res*nums[index],index+1,nums,a,b,c-1,d);
    if(d > 0)
        calculate(res/nums[index],index+1,nums,a,b,c,d-1);
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

    int a,b,c,d; // + - * /
    cin >> a >> b >> c >> d;

    calculate(nums[0],1,nums,a,b,c,d);
    cout << MAXn << endl << MINn << endl;
    return 0;
}