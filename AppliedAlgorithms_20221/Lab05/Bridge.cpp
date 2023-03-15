#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int n, m, CriticalEdge;
vector <int> a[N];
bool CriticalNode[N];
int Num[N], Low[N], Time;
// Num[i]: số thứ tự đỉnh i khi định chiều đồ thị (duyệt theo DFS)
// Low[i]: đỉnh con có số thứ tự Num[i] thấp nhất khi bắt đầu định chiều đồ thị từ i
 
void inp() 
{
    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= m ; i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    
}

void visit(int u, int p) {
    int NumChild = 0;
    Low[u] = Num[u] = ++Time;

    for (int i = 0; i < int(a[u].size()); i++)
    {
        int v = a[u][i];
        if (v != p)
        {
            if (Num[v])
            {
                Low[u] = min(Low[u], Num[v]);
            }
            else
            {
                visit(v, u);
                ++NumChild;
                Low[u] = min(Low[u], Low[v]);

                if (Low[u] >= Num[v] )
                {
                    ++CriticalEdge;
                }
                
                if (u == p)
                {
                    if(NumChild >= 2) CriticalNode[u] = true;
                }else
                {
                    if(Low[v] >= Num[u]) CriticalNode[u] = true;
                } 
            } 
        }
    }
}

void proc()
{
    for (int i = 1; i <= n; i++)
    {
        if(!Num[i]) visit(i,i);
    }

    int Count = 0;

    for (int i = 1; i <= n; i++)
    {
        if(CriticalNode[i]) ++Count;
    }
    cout << Count << " " << CriticalEdge;
}

int main(int argc, char const *argv[])
{
    inp();
    proc();
}
