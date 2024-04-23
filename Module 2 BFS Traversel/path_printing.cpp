#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool visite[1005];
int level[1005];
int parent[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visite[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int per = q.front();
        q.pop();

        for (auto child : v[per])
        {
            if (visite[child] == false)
            {
                q.push(child);
                visite[child] = true;
                level[child] = level[per] + 1;
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

    int src, des;
    cin >> src >> des;
    memset(visite, false, sizeof(visite));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));
    bfs(src);

    int x = des;
    vector<int> path;

    while (x != -1)
    {
        path.push_back(x);
        x = parent[x];
    }
    reverse(path.begin(), path.end());

    for(int ele:path)
    {
        cout << ele << " ";
    }

    return 0;
}
