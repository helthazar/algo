bool dfs(int v, int h = 0) {
    used[v] = 1;
    p[h] = v;
    for (int i = 0; i < edges[v].size(); i++) {
        int next = edges[v][i];
        if (used[next] == 1) {
            printf("YES\n");
            int cur = h;
            while (p[cur] != next) {
                cur--;
            }
            while (cur <= h) {
                printf("%d ", p[cur] + 1);
                cur++;
            }
            return false;
        }
        else if (used[next] == 0) {
            if (!dfs(next, h + 1)) {
                return false;
            }
        }
    }
    used[v] = 2;
    return true;
}