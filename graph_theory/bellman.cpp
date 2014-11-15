for (int i = 0; i < n; i++) {
    d[i] = INF;
}
d[s] = 0;

for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n; j++) {
        if (d[j] == INF) {
            continue;
        }
        for (int k = 0; k < edges[j].size(); k++) {
            int next = edges[j][k];
            long long cost = costs[j][k];
            if (d[next] > d[j] + cost) {
                d[next] = max(-INF, d[j] + cost);
            }
        }
    }
}

for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n; j++) {
        if (d[j] == INF) {
            continue;
        }
        for (int k = 0; k < edges[j].size(); k++) {
            int next = edges[j][k];
            long long cost = costs[j][k];
            if (d[next] > d[j] + cost) {
                d[next] = - INF;
            }
        }
    }
}