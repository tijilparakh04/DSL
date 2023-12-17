#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<int> a;
vector<int> visited;
vector<vector<int>> mat;
vector<vector<int>> list;
vector<int>dist;
vector<int>q;

stack<int> dfs;
queue<int> bfs;

void depth(int n)
{
    int i, j, k;
    for (i = 0; i < a.size(); i++)
    {
        if (a[i] == n)
        {
            k = i;
            break;
        }
    }
    dfs.push(n);
    visited[k] = 1;
    cout << dfs.top();
reloop:
    int x = 0;

    for (j = 0; j < a.size(); j++)
    {
        if (mat[k][j] == 1)
        {
            if (visited[j] != 1)
            {
                x = 1;
                break;
            }
        }
    }

    if (x == 1)
    {
        depth(a[j]);
        int c = 0;
        for (i = 0; i < a.size(); i++)
        {
            if (visited[i] == 0)
            {
                c++;
                goto reloop;
            }
        }
        if (c == 0)
        {
            dfs.pop();
            return;
        }
    }
}

void breadth(int n)
{
    int i, j, k;
    for(i=0; i<a.size(); i++)
    {
        visited[i]=0;
    }
    bfs.push(n);
    while(!bfs.empty())
    {
        for (i = 0; i < a.size(); i++)
        {
            if (n == a[i])
            {
                k = i;
                break;
            }
        }
        visited[k]=1;
        for (j = 0; j < a.size(); j++)
        {
            if (mat[k][j] == 1)
            {
                if(visited[j]!=1)
                {
                    bfs.push(a[j]);
                    visited[j]=1;
                }
            }
        }
        cout<<bfs.front();
        bfs.pop();
        n=bfs.front();
    }
}

void add_vertex()
{
    int x;
    cout << "enter vertex value - ";
    cin >> x;
    a.push_back(x);
    mat.resize(a.size());
    list.resize(a.size());
    dist.resize(a.size());
    visited.resize(a.size());
    int i;
    for (i = 0; i < a.size(); i++)
    {
        mat[i].resize(a.size());
        list[i].resize(a.size());
    }
    int j;
    for (i = 0; i < a.size(); i++)
    {
        for (j = 0; j < a.size(); j++)
        {
            mat[i][j] = 0;
        }
    }
}

void add_edge()
{
    int x, y;
    cout << "enter the vertices - ";
    cin >> x >> y;
    int i, j,z;
    // cout<<"Enter the weight - ";
    // cin>>z;
    for (i = 0; i < a.size(); i++)
    {
        for (j = 0; j < a.size(); j++)
        {
            if (a[i] == x && a[j] == y)
            {
                mat[i][j] = 1;
                mat[j][i] = 1;
            }
        }
    }
}

void display_matrix()
{
    int i, j;
    for (i = 0; i < a.size(); i++)
    {
        if (i == 0)
        {
            cout << "  ";
        }
        cout << a[i] << " ";
    }
    cout << endl;
    for (i = 0; i < a.size(); i++)
    {
        cout << a[i];
        for (j = 0; j < a.size(); j++)
        {
            if (j == 0)
            {
                cout << " ";
            }
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void display_list()
{
    int i;
    int j;
    for (i = 0; i < a.size(); i++)
    {
        list[i][0] = a[i];
        for (j = 0; j < a.size(); j++)
        {
            if (mat[i][j] == 1)
            {
                list[i][j] = a[j];
            }
        }
    }
    for (i = 0; i < a.size(); i++)
    {
        for (j = 0; j < a.size(); j++)
        {
            if (list[i][j] != 0)
            {
                cout << list[i][j] << "->";
            }
        }
        cout << endl;
    }
}

void dijkstra(int n)
{
    int i, j, k ;
    for (i = 0; i < a.size(); i++)
    {
        if (a[i] == n)
        {
            k = i;
            break;
        }
    }
    for (i = 0; i < a.size(); i++)
    {
        visited[i] = 0;
    }
    dist[k] = 0;
    for(i=0; i<a.size(); i++)
    {
        if(i!=k)
        {
            dist[i] = 99999;
        }
    }
    for(i=0; i<a.size(); i++)
    {
        q.push_back(a[i]);
    }
    int u,v;
    int av = 99999;
    int alt;
    int p;
    while(!q.empty())
    {
        for(i=0; i<a.size(); i++)
        {
            if(dist[i]<av && visited[i]!= 1)
            {
                av = dist[i];
                u = a[i];
                k=i;
            }
        }
        visited[k]=1;
        q.erase(q.begin()+k);
        for(i=0; i<a.size(); i++)
        {
            if(mat[k][i]!=0)
            {
                alt = dist[k] + mat[k][i];
            }
            if(alt<dist[i])
            {
                dist[i] = alt;
            }
        }
        av=99999;
    }
    for(i=0; i<a.size(); i++)
    {
        cout<<a[i]<<"->"<<dist[i]<<" "<<endl;
        
    }
}

main()
{
    add_vertex();
    add_vertex();
    add_vertex();
    add_vertex();
    add_vertex();
    add_vertex();
    add_edge();
    add_edge();
    add_edge();
    add_edge();
    add_edge();
    add_edge();
    add_edge();
    display_matrix();
    // dijkstra(1);
    display_list();
    depth(1);
    cout<<endl;
    breadth(1);
}