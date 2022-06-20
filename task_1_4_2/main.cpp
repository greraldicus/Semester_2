#include <iostream>
#include <vector>

long long PossiblePyramidsCounter(int n)
{
    std::vector<std::vector<long long> > PyramidMatrix (n+1,std::vector<long long> (n+1,0));
    for (long long i = 0; i <= n; i++)
    {
        PyramidMatrix[0][i] = 1;
    }
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= n; j++)
        {
            if (j <= i) PyramidMatrix[i][j] = PyramidMatrix[i][j-1] + PyramidMatrix[i-j][j];
            else PyramidMatrix[i][j] = PyramidMatrix[i][j-1];
        }
    }
    return PyramidMatrix[n][n];
}

int main() {
    int n;
    std::cin >> n;
    std::cout << PossiblePyramidsCounter(n);
    return 0;
}