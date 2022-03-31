// ������ ����
/*
�������� X�� ���谡�� X���̻����� ����ؾ��Ѵ�.
�������� ���� ������� ��� �ּҰ� X������ ���
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> v;
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }    
    sort(v.begin(),v.end());

    int result = 0;
    int count = 0;
    for(int i=0;i<N;i++){
        count++;
        if(count == v[i]){
            result++;
            count = 0;
        }
    }
    cout << result << endl;
    return 0;
}