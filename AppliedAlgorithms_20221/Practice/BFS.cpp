#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000001;

int n;
vector <int> graph[MAX];
int d[MAX], prevv[MAX];
bool visited[MAX] = {false};
queue <int> q;

void input()
{
    
    int v;
    cin >> n >> v;
    int x, y;
    for (int i = 0; i < v; i++)
    {
        cin >> x  >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    } 
    
}

void BFS(int root)
{
    fill_n(d, n+1, 0);
    fill_n(prevv, n+1, -1);

    q.push(root);
    visited[root] = true;

    while (!q.empty())
    {
        int u = q.front(); q.pop();

        for (auto v : graph[u])
        {
            if (!visited[v])
            {
                d[v] = d[u] + 1;
                prevv[v] = u;
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void path(int u)
{
    if (!visited[u])
    {
        cout << "No path";
    }else
    {
        vector <int> path;
        int v = u;
        while (v != -1)
        {
            path.push_back(v);

            v = prevv[v];
        }
        reverse(path.begin(), path.end());

        cout << "Path from root " << " to " << u << endl;
        for (auto v :  path)
        {
            cout << v << " ";
        }
        cout << endl;
    }   
}

int main(int argc, char const *argv[])
{
    input();
    BFS(0);
    for (int i = 0; i < n; i++)
    {
        cout << "v = " << i << "| Distance = " << d[i] << "| Parent = " << prevv[i] << endl;
    }
    cout << "\n ------------------------------- \n";
    path(13);
    return 0;
}
/*
15 16
0 1
1 2
2 5
6 10
2 6
6 11
7 11
1 3
1 4
7 4
4 8
4 9
8 12
8 13
9 13
9 14
*/