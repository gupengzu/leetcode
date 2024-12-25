#include <iostream>
using namespace std;

int iteration(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int b = 1;
    int a = 0;
    for (int i = 2; i < n; i++)
    {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return a + b;
}

int main()
{
    int c = iteration(6);
    cout << c << endl;
    return 0;
}