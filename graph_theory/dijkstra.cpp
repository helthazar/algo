used[s] = 1;
for (int i = 0; i < n; i++) {
    int mini = - 1;
    for (int j = 0; j < n; j++) {
        if (used[j] != 1)
            continue;
        if (mini == -1 || deik[mini] > deik[j])
            mini = j;
    }
    if (mini == -1)
        break;
    used[mini] = 2;
    for (int j = 0; j < n; j++) {
        if (d[mini][j] == -1)
            continue;
        if (used[j] == 0 || deik[j] > deik[mini] + d[mini][j]) {
            used[j] = 1;
            deik[j] = deik[mini] + d[mini][j];
        }
    }
}