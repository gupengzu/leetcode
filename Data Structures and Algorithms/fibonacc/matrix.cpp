#include<iostream>
#include<vector>
using namespace std;


typedef vector<vector<long long>> matrix;
const int MOD = 1000000007;

//matrix multiplication
matrix multiply(matrix A,matrix B)
{
    int n = A.size();
    matrix C(n,vector<long long>(n));
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < n;++j)
        {
            for (int k = 0; k < n;++k)
            {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

//matrix fast power
matrix matrix_pow(matrix A,int p)
{
    int n=A.size();
    matrix result(n,vector<long long>(n));
    for (int i = 0; i < n;++i)
    {
        result[i][i] = 1;
    }
    while(p)
    {
        if(p%2==1)
        {
            result = multiply(result, A);
        }
        A=multiply(A,A);
        p /= 2;
    }
    return result;
}

long long fibonacci(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    matrix T = {{1, 1}, {1, 0}};
    T = matrix_pow(T, n - 1);
    return T[0][0];
}

int main()
{
    return 0;
}