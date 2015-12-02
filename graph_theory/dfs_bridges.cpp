const int MAXN = 100001;

vector<int> edges[MAXN];
vector<int> edgind[MAXN];

int used[MAXN];
int tin[MAXN];
int fout[MAXN];
int bridge[MAXN];

int timer = 0;

void dfs_bridge(int v, int prev = -1, int prevind = -1){
    used[v] = 1;
    fout[v] = tin[v] = timer++;
    
    for (int i = 0; i < edges[v].size(); i++){
        int next = edges[v][i];
        int ind = edgind[v][i];
        
        if (next == prev && ind == prevind) {
            continue;
        }
        
        if (!used[next]){
            dfs_bridge(next, v, ind);
            
            fout[v] = min(fout[v], fout[next]);
            
            if (tin[v] < fout[next]) {
                bridge[ind] = 1;
            }
        }
        else{
            fout[v] = min(fout[v], tin[next]);
        }
    }
}