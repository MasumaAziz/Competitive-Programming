#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1000];   // stores all neighbors of node
bool visited[1000]; //tells if a node is already visited in BFS

void bfs(int start)
{
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int i = 0; i < graph[node].size(); i++)
        {
            int nxt = graph[node][i];

            if (!visited[nxt])
            {
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }
}

int main()
{
    int n, e;
    cout<<"Enter number of nodes: ";
    cin >> n;   // edges
    cout<<"Enter number of edges: ";
    cin >> e;   // edges

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u); // remove if directed graph
    }
    int start;
    cout<<"Enter from where to start: ";
    cin>>start;
    bfs(start); // starting node

    return 0;
}
