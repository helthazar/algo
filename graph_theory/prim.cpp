used[0] = 1;

double sum = 0;

for (int i = 0; i < n; i++) {
    int mini = -1;
    for (int j = 0; j < n; j++) {
        if (used[j] != 1) {
            continue;
        }
        if (mini == -1 || prim[mini] > prim[j]) {
            mini = j;
        }
    }
    if (mini == -1) {
        break;
    }
    double add = prim[mini];
    sum += sqrt(add);
    used[mini] = 2;
    for (int j = 0; j < n; j++) {
        int len = sqr(x[j] - x[mini]) + sqr(y[j] - y[mini]);
        if (used[j] == 0 || (used[j] == 1 && prim[j] > len)) {
            used[j] = 1;
            prim[j] = len;
        }
    }
}