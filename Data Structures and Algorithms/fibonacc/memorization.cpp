#include <iostream>
#include <vector>
using namespace std;

int fibonacc(int n, vector<int> &memorization)
{
    if (n <= 1)
    {
        return n;
    }
    else if (memorization[n] != -1)
    {
        return memorization[n];
    }
    else
    {
        memorization[n] = fibonacc(n - 1, memorization) + fibonacc(n - 2, memorization);
        return memorization[n];
    }
}

int fast_fibonacc(int n)
{
    vector<int> memorization(n + 1, -1);
    return fibonacc(n, memorization);
}

int main()
{
    int x = fast_fibonacc(8);
    cout << x << endl;
    return 0;
}