// ���ϱ� Ȥ�� ���ϱ�
/*
���ʺ��� ������� ������ �ϴµ�,
0,1�̸� ����, �� ���� ��� ���� ������ �ϸ�ȴ�.
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;

    int result = 0;
    for(int c : s){
        c = c-'0'; // to int
        if(result <= 1 || c <= 1)
            result += c;
        else
            result *= c;
    }
    cout << result << endl;
    return 0;
}