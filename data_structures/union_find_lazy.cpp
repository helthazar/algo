const int MAXN = 100001;

int parent[MAXN];
vector<int> st[MAXN];

void make_set(int v) {
    parent[v] = v;
    st[v].push_back(v);
}

int find_set(int v) {
    return parent[v];
}

bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    
    if (a != b) {
        if (st[a].size() > st[b].size()) {
            swap(a, b);
        }
        
        while (!st[a].empty()) {
            int x = st[a].back();
            parent[x] = b;
            st[a].pop_back();
            
            st[b].push_back(x);
        }
        return true;
    }
    
    return false;
}