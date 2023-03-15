#include <bits/stdc++.h>

using namespace std;

const int maxN = 999;

typedef pair<int, int> location; 

int visited[maxN][maxN], d[maxN][maxN], m, n, r, c;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

queue<location> q;

int Try() {
    q.push(location(r, c));     // Dua diem bat dau vao queue
    d[r][c] = 0;
    visited[r][c] = 1;

    while (!q.empty())
    {
        location u = q.front(); q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = dx[i] + u.first;
            int y = dy[i] + u.second;

            if (x < 1 || x > m || y < 1 || y > n)
            {
                return d[u.first][u.second] + 1;
            }

            if (visited[x][y] != 1)
            {
                d[x][y] = d[u.first][u.second] + 1;
                q.push(location(x,y));
                visited[x][y] = 1;
            } 
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    cin >> m >> n >> r >> c;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> visited[i][j];
        }
    }
    
    cout << Try();
    
    return 0;
}
