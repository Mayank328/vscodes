#include <bits/stdc++.h>
using namespace std;

// check the safety
int isSafe(int r, int c, vector<vector<char>> &mat, int n)
{
    // same row
    for (int i = 0; i < r; i++)
    {
        if (mat[i][c] == 'Q')
            return 0;
    }
    // diagonal /
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (mat[i][j] == 'Q')
        {
            return 0;
        }
    }
    // diagonal /
    for (int i = r, j = c; i >= 0 && j < n; i--, j++)
    {
        if (mat[i][j] == 'Q')
        {
            return 0;
        }
    }
    return 1;
}

// print the matrix
void printMat(vector<vector<char>> &mat, int &count)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat.size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    count++;
}

// check the position of queen
void nQueen(int r, vector<vector<char>> &mat, int n, int &count)
{
    if (r == n)
    {
        printMat(mat, count);
        return;
    }

    for (int i = 0; i < n; i++)
    {

        if (isSafe(r, i, mat, n))
        {

            mat[r][i] = 'Q';

            nQueen(r + 1, mat, n, count);
            // bactracking
            mat[r][i] = '-';
        }
    }
}

int main()
{
    int n = 15;
    int count = 0;

    vector<vector<char>> mat(n, vector<char>(n, '-'));

    nQueen(0, mat, n, count);

    cout << count << endl;

    return 0;
}