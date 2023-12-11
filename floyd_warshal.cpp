class Solution
{
public:
// finds the shortest path between any two nodes by calculating path via every node and putting the shortest one in the matrix
    void shortest_distance(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i += 1)
        {
            for (int j = 0; j < n; j += 1)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = 1e8;
                }
            }
        }
        for (int k = 0; k < n; k += 1)
        {
            for (int i = 0; i < n; i += 1)
            {
                for (int j = 0; j < n; j += 1)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
        for (int i = 0; i < n; i += 1)
        {
            for (int j = 0; j < n; j += 1)
            {
                if (matrix[i][j] == 1e8)
                {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};