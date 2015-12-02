const int MAXN = 100001;

vector<int> edges[MAXN];

int used[MAXN];
int tin[MAXN];
int fout[MAXN];
bool cutpoint[MAXN];

int timer = 0;

void dfs_cutpoint(int v, bool root = false){
    used[v] = 1;
    fout[v] = tin[v] = timer++;
    
    cutpoint[v] = false;
    
    int directedges = 0;
    
    for (int i = 0; i < edges[v].size(); i++){
        int next = edges[v][i];
        
        if (!used[next]){
            dfs_cutpoint(next);
            
            fout[v] = min(fout[v], fout[next]);
            
            if (tin[v] <= fout[next] && !root)
                cutpoint[v] = true;
            directedges++;
        }
        else{
            fout[v] = min(fout[v], tin[next]);
        }
    }
    
    if (root && directedges >= 2) {
        cutpoint[v] = true;
    }
}