for (int i = 0; i < n; i += 1)
{
    cout << i << ": ";
    for (auto it : adj[i])
    {
        cout << "{" << it.first << "," << it.second << "}"
             << " ";
    }
    cout << endl;
}
// for 4-direction traversal
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

// for 8-direction traversal
int dr[] = {0, 1, -1, 0, 1, -1, 1, -1};
int dc[] = {1, 0, 0, -1, 1, 1, -1, -1};