#include <bits/stdc++.h>
using namespace std;
class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue()
    {
    }
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int getsize()
    {
        return pq.size();
    }
    int getmin()
    {
        if (isEmpty())
        {
            return 0;
        }
        return pq[0];
    }
    void insert(int element)
    {
        pq.push_back(element);
        int ci = pq.size() - 1;
        while (ci > 0)
        {
            int pi = (ci - 1) / 2;
            if (pq[ci] < pq[pi])
            {
                swap(pq[pi], pq[ci]);
                ci = pi;
            }
            else
            {
                break;
            }
        }
    }
    int RemoveMin()
    {
        int ans = pq[0];
        swap(pq[0], pq[pq.size() - 1]);
        int pi = 0;
        while (true)
        {
            int lci = 2 * pi + 1;
            int rci = 2 * pi + 2;
            int min = pi;
            if (lci < pq.size() && pq[pi] > pq[lci])
            {
                min = lci;
            }
            else if (rci < pq.size() && pq[pi] > pq[rci])
            {
                min = rci;
            }
            else if (pi == min)
            {
                break;
            }
            swap(pq[pi], pq[min]);
            pi = min;
        }
        return ans;
    }
};
int main()
{
    PriorityQueue p;
    p.insert(5);
    p.insert(7);
    p.insert(2);
    p.insert(12);
    p.insert(10);
    p.insert(25);

    cout << p.getsize() << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << p.RemoveMin() << endl;
    }
    return 0;
}