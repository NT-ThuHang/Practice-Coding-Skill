#include <iostream>
#include <vector>
using namespace std;

int N, K; // N means the number os students ; K means the number of successfull students
void Topological_Sort(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &topo_Result, int student)
{
    visited[student] = true;
    vector<int> :: iterator it;
    for (it=graph[student].begin(); it!=graph[student].end();it++)
    {
        if (!visited[*it])
            Topological_Sort(graph, visited, topo_Result,*it);
    }
    topo_Result.push_back(student);
}
int main()
{
    cin >> N >> K;
    vector <vector<int>> graph;
    vector <int> topo_Result;
    vector <int> Result(N+1);
    vector <bool> visited(N+1,false);
    graph.assign(N+1, vector<int>());
    for (int u,i=1; i<=K; i++)
    {
        cin >> u;
        for (int v,j=0; j<u; j++)
        {
            cin >> v;
            graph[i].push_back(v);
        }
    }
    for (int i=1;i<=N; i++)
    {
        if (!visited[i])
            Topological_Sort(graph, visited, topo_Result, i);
    }
        
    int position = 0;
    for (int i=N-1;i>=0;i--)
    {
        int student = topo_Result[i];
        Result[student] = position;
        position = student;
    }
    for (int i=1;i<=N;i++)
        cout << Result[i]<<" ";
    
    return 0;
        
}