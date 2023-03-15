#include <bits/stdc++.h>

using namespace std;

const int MAX = 1001;

int n;
vector <int> Graph[MAX];
vector <bool> Visited(MAX, false); 
vector <bool> Marked(MAX, false); 
int d[MAX], prevv[MAX];
int IN[MAX];
int tmp = -1;

void input()
{
    fill_n(d, n+1, 0);
    fill_n(prevv, n+1, -1);

    int v;
    cin >> n >> v;
    int x, y;
    for (int i = 0; i < v; i++)
    {
        cin >> x  >> y;
        Graph[x].push_back(y);
        // Graph[y].push_back(x);
    } 
    
}

void DFS(int u)
{
    if (Marked[u])
    {
        return;
    }
    
    Marked[u] = true;
    Visited[u] = true;
    
    tmp++;
    IN[u] = tmp;

    for (auto v : Graph[u])
    {
        if (!Visited[v])
        {
            prevv[v] = u;
            d[v] = d[u] + 1;
            Visited[v] = true;
            DFS(v);
        }
    }
    
}

int main(int argc, char const *argv[])
{
    input();
    DFS(0);

    for (int i = 0; i < n; i++)
    {
        cout << "v = " << i << "| Distance = " << d[i] << "| Parent = " << prevv[i] << "| IN = "<< IN[i] << endl;
    }
    
    return 0;
}

/**
12 18
0 1
1 2
1 3
2 5
3 2
3 4
4 1
5 6
6 3
6 4
6 7
6 8
6 9
7 8
7 9
8 11
9 10
10 9
 */