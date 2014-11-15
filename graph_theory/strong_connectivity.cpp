int cnt = 0;

void dfs1(int v){
    used[v] = 1;
    for (int i = 0; i < edges[v].size(); i++){
        int to = edges[v][i];
        if (!used[to]){
            dfs1(to);
        }
    }
    topsort.push_back(v);
}

void dfs2(int v){
    color[v] = cnt;
    for (int i = 0; i < redges[v].size(); i++){
        int to = redges[v][i];
        if (!color[to]){
            color[to] = cnt;
            dfs2(to);
        }
    }
}

for (int i = 0; i < n; i++)
    if (!used[i])
        dfs1(i);

reverse(topsort.begin(), topsort.end());

for (int i = 0; i < n; i++){
    if (!color[topsort[i]]){
        cnt++;
        dfs2(topsort[i]);
    }
}