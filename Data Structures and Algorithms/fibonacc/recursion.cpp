#include <iostream>
using namespace std;

int recursion(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int a = recursion(n - 1);
    int b = recursion(n - 2);
    return a + b;
}

int main()
{
    int c = recursion(6);
    cout << c << endl;

    return 0;
}