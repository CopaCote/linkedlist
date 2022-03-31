#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void counting_sort(vector<int> &v)
{
    vector<int> c(101, 0);

    for (int n : v) // Counting
        c[n]++;

    int index = 0;
    for (int i = 0; i < c.size(); i++)
        for (int j = 0; j < c[i]; j++)
            v[index++] = i;
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

    counting_sort(v);
    for (int i = 0; i < 20; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}