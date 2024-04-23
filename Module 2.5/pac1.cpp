#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool visite[1005];

int parent[1005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visite[src] = true;

    while (!q.empty())
    {
        int per = q.front();
        q.pop();

        for (int child : v[per])
        {
            if (visite[child] == false)
            {
                q.push(child);
                visite[child] = true;
                parent[child] = per;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int q;
    cin >> q;
    while(q--)
    {
        int src, des;
        cin >> src >> des;
        memset(visite, false, sizeof(visite));

        memset(parent, -1, sizeof(parent));

        int x = des;
        vector<int> path;
        while (x != -1)
        {
            path.push_back(x);
            x = parent[x];
        }
        reverse(path.begin(), path.end());
        for (int ele : path)
        {
            cout << ele << endl;
        }
    }

    return 0;
}
