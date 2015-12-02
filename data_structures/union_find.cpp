const int MAXN = 100001;

int parent[MAXN];
int rang[MAXN];

void make_set(int v) {
    parent[v] = v;
    rang[v] = 1;
}

int find_set(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    
    if (a != b) {
        if (rang[a] < rang[b]) {
            swap(a, b);
        }
        
        parent[b] = a;
        if (rang[a] == rang[b]) {
            rang[a]++;
        }
        return true;
    }
    
    return false;
}