void Graph::DFSUtil(int v)
{
    visited[v] = true;
    cout << v << " ";

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i);
}

void Graph::DFS()
{
   
    for (auto i : adj)
        if (visited[i.first] == false)
            DFSUtil(i.first);
}