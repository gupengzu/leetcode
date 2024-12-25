#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

long long fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    Matrix2d A;
    A << 1, 1,
        1, 0;

    EigenSolver<Matrix2d> es(A);
    Matrix2d D = es.eigenvalues().asDiagonal();
    Matrix2d V = es.eigenvectors().real();
    Matrix2d V_inv = V.inverse();

    Matrix2d A_n = V * D.pow(n - 1) * V_inv;

    return round(A_n(0, 0));
}

int main()
{
    int n;
    cout << "请输入要计算的斐波那契数列的项数: ";
    cin >> n;
    cout << "第" << n << "个斐波那契数是: " << fibonacci(n) << endl;
    return 0;
}
