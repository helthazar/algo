queue<int> q;
q.push(s);
used[s] = 1;
from[s] = s;

while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < edges[cur].size(); i++) {
        int next = edges[cur][i];
        if (!used[next]) {
            used[next] = used[cur] + 1;
            from[next] = cur;
            q.push(next);
        }
    }
}
