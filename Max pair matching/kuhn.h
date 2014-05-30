const int MAXN = 500;

vector <int> edges[MAXN];
int match[MAXN];
bool used[MAXN];

bool try_kuhn (int v) {
	if (used[v]) {
        return false;
    }
	used[v] = true;
    for (int i = 0; i < edges[v].size; i++) {
        int to = edges[v][i];
        if (match[to] == -1 || try_kuhn(match[to])) {
            match[to] = v;
            return true;
        }
    }
    return false;
}

int main() {
    
    for (int i = 0; i < k; i++) {
        match[i] = - 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            used[j] = false;
        }
        try_kuhn(i);
    }
    
    for (int i = 0; i < k; i++) {
        if (match[i] != -1) {
            printf("%d %d'n", match[i] + 1, i + 1);
        }
    }
}