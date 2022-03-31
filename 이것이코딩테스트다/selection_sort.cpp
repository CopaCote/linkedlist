#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void selection_sort(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        int minIndex = i;
        for (int j = i; j < v.size(); j++)
        {
            if (v[j] < v[minIndex])
                minIndex = j;
        }
        int temp = v[i];
        v[i] = v[minIndex];
        v[minIndex] = temp;
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

    selection_sort(v);
    for (int i = 0; i < 20; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}