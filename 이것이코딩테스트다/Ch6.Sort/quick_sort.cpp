#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void quick_sort(vector<int> &v, int left, int right)
{
    if (right - left < 1)
        return;

    int pivot = left;

    int leftPointer = left++;
    int rightPointer = right;
    while (true)
    {
        while (v[leftPointer] < v[pivot] && leftPointer < rightPointer)
            leftPointer++;
        while (v[rightPointer] >= v[pivot] && leftPointer < rightPointer)
            rightPointer--;
        if (leftPointer < rightPointer)
        {
            int temp = v[leftPointer];
            v[leftPointer] = v[rightPointer];
            v[rightPointer] = temp;
        }
        else
        {
            int temp = v[leftPointer];
            v[leftPointer] = v[pivot];
            v[pivot] = temp;
            break;
        }
    }
    quick_sort(v, left, pivot - 1);
    quick_sort(v, pivot + 1, right);
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

    quick_sort(v, 0, v.size() - 1);
    for (int i = 0; i < 20; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}