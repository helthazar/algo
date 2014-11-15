int cnt = 0;

void dfs(int v, int pr = - 1){
    used[v] = 1;
    fout[v] = tin[v] = cnt++;
    for (int i = 0; i < edges[v].size(); i++){
        int to = edges[v][i];
        if (to == pr)
            continue;
        if (!used[to]){
            dfs(to, v);
            fout[v] = min(fout[v], fout[to]);
            if (tin[v] < fout[to])
                ans.push_back(num[v][i]);
        }
        else{
            fout[v] = min(fout[v], tin[to]);
        }
    }
}
