#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector <int> a;
vector <vector<int>> mat;
vector <int> visited;
stack <int> dfs;
queue <int> bfs;

void add_vertex()
{
    int x;
    cout<<"enter vertex value - ";
    cin>>x;
    a.push_back(x);
    if(a.size() == 1)
    {
        visited.push_back(1);
    }
    mat.resize(a.size());
    int i,j;
    for(i=0; i<a.size(); i++)
    {
        mat[i].resize(a.size());
    }
    for(i=0; i<a.size(); i++)
    {
        for(j=0; j<a.size(); j++)
        {
            mat[i][j] = 0;
        }
    }
}

void add_edge()
{
    int x,y;
    int i,j;
    cout<<"enter vertices to add an edge between - "<<endl;
    cin>>x>>y;
    for(i=0; i<a.size(); i++)
    {
        for(j=0; j<a.size(); j++)
        {
            if(a[i]==x && a[j]==y)
            {
                mat[i][j] = 1;
                mat[j][i] = 1;
            }
        }
    }
}

void show_matrix()
{
    int i,j;
    for(i=0; i<a.size(); i++)
    {
        if(i==0)
        {
            cout<<" ";            
        }
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(i=0; i<a.size(); i++)
    {
        for(j=0; j<a.size(); j++)
        {
            if(j==0)
            {
                cout<<a[i]<<" ";
            }
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void depth(int l)
{
    dfs.push(l);
    cout<<dfs.top();
    reloop:
    int x,i;
    for(i=0; i<a.size(); i++)
    {
        if(a[i] == l)
        {
            x=i;
        }
    }
    int j =0;
    for(i=0; i<a.size(); i++)
    {
        if(mat[x][i]==1)
        {
            if(visited[i] != 1)
            {
                visited[i]=1;
                j++;
                break;
            }
        }
    }
    if(j==1)
    {
        depth(i);
        int m=0;
        for(i=0; i<a.size(); i++)
        {
            if(visited[i]==0)
            {
                m++;
                goto reloop;
            }
        }
        if(m==0)
        {
            cout<<dfs.top();
            dfs.pop();
            return;
        }
    }
    else
    {
        cout<<dfs.top();
        dfs.pop();
        return;
    }
}

main()
{   
    while(true)
    {
        int o,d=0;
        cout<<"\n0.Add Vertex\n1.Add an edge\n2.Display Matrix\n3.Display List\n4.DFS\n5.BFS\n6.Dijkstra's\n10.Exit: ";
        cin>>o;
        switch(o)
        {
            case 0:
            add_vertex();
            break;    
            case 1:
            add_edge();
            break;
            case 2:
            show_matrix();
            break;
            case 3:
            int x;
            cout<<"choose vertex - "<<endl;
            cin>>x;
            depth(x);
            case 10:
            exit(0);
            default:
            cout<<"error";
            break;
        }
    }   
}
