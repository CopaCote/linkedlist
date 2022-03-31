#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void insertion_sort(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (v[j] < v[j - 1])
                swap(v[j], v[j - 1]);
            else
                break;
        }
    }
}

int main()
{
    vector<int> v;
    srand((unsigned int)time(NULL));

    for (int i = 0; i < 20; i++)
    {
        int n = rand() % 100;
        v.push_back(n);
        cout << n << " ";
    }
    cout << endl;

    insertion_sort(v);
    for (int i = 0; i < 20; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}