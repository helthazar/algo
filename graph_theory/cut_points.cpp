int cnt = 0;

void dfs(int v, bool root = false){
    used[v] = 1;
    fout[v] = tin[v] = cnt++;
    bool is = false;
    int sons = 0;
    for (int i = 0; i < edges[v].size(); i++){
        int to = edges[v][i];
        if (!used[to]){
            dfs(to);
            fout[v] = min(fout[v], fout[to]);
            if (tin[v] <= fout[to] && !root)
                is = true;
            sons++;
        }
        else{
            fout[v] = min(fout[v], tin[to]);
        }
    }
    if (root && sons >= 2)
        is = true;
    if (is){
        ans.push_back(v);
    }
}