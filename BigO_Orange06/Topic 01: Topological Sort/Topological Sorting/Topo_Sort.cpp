#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int V,E;
bool topologicalSort(vector<vector<int>> &graph, vector<int> &result)
{
    vector <int> degree(V+1,0);
    priority_queue<int,vector<int>,greater<int>> zero_degree;
    //degree counter
    for (int u=1; u<=V; u++)
    {
        vector <int> :: iterator it;
        for (it = graph[u].begin(); it!=graph[u].end(); it++)
        {
            degree[*it]++;
        }
    }
    for (int i=1; i<=V;i++)
    {
        if (degree[i]==0)
        {
            zero_degree.push(i);
        }
    }
    while(!zero_degree.empty())
    {
        int u = zero_degree.top();
        zero_degree.pop();
        result.push_back(u);
        vector<int>::iterator it;
        for (it = graph[u].begin(); it!=graph[u].end(); it++)
        {
            degree[*it]--;
            if (degree[*it]==0)
            {
                zero_degree.push(*it);
            }
        }
    }
    for (int i=1; i<=V; i++)
    {
        if (degree[i]!=0)
            return false;
    }
    return true;
}
int main()
{
    vector <vector<int>> graph;
    vector <int> result;
    cin >> V >> E;
    graph.assign(V+1,vector<int>());
    for (int u,v,i=0;i<E;i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    
    if (topologicalSort(graph,result))
    {
        for (int x:result)
            cout << x << " ";
    }
    else
    {
        cout <<"Sandro fails.";
    }
    return 0;
}