const int MAXN = 500;
vector<int> edges[MAXN], q[MAXN];
int id[MAXN], ancestor[MAXN];
bool used[MAXN];

int get(int v) {
	return v == id[v] ? v : id[v] = get(id[v]);
}

void unite(int a, int b, int new_ancestor) {
	a = get(a), b = get(b);
	if (rand() & 1) {
        swap (a, b);
    }
	id[a] = b,  ancestor[b] = new_ancestor;
}

void dfs(int v) {
	id[v] = v,  ancestor[v] = v;
	used[v] = true;
	for (int i = 0; i < edges[v].size(); i++)
		if (!u[edges[v][i]]) {
			dfs(edges[v][i]);
			unite(v, edges[v][i], v);
		}
	for (int i = 0; i < q[v].size(); i++)
		if (u[q[v][i]]) {
			printf ("%d %d -> %d\n", v + 1, q[v][i] + 1,
                    ancestor[ get(q[v][i]) ] + 1);
        }
}

int main() {
    
    for (;;) {
        int a, b = ...;
        --a, --b;
        q[a].push_back (b);
        q[b].push_back (a);
    }
    
    dfs (0);
}