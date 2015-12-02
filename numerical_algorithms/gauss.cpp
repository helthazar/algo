const int MAXN = 100;
const double EPS = 1e-9;
const int INF = 1000000000;

double a[MAXN][MAXN];
double b[MAXN];
double ans[MAXN];
int where[MAXN];

int gauss (int n, int m) {
    fill(where, where + m, - 1);
    for (int col = 0, row = 0; col < m && row < n; col++) {
        int sel = row;
        for (int i = row; i < n; i++) {
            if (abs(a[i][col]) > abs(a[sel][col])) {
                sel = i;
            }
        }
        if (abs(a[sel][col]) < EPS) {
            continue;
        }
        for (int i = col; i < m; i++){
            swap(a[sel][i], a[row][i]);
        }
        swap(b[sel], b[row]);
        where[col] = row;

        for (int i = 0; i < n; i++) {
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j = col; j < m; j++) {
                    a[i][j] -= a[row][j] * c;
                }
                b[i] -= b[row] * c;
            }
        }
        row++;
    }

    fill(ans, ans + m, 0);
    for (int i = 0; i < m; i++) {
        if (where[i] != -1) {
            ans[i] = b[where[i]] / a[where[i]][i];
        }
    }
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < m; j++) {
            sum += ans[j] * a[i][j];
        }
        if (abs(sum - b[i]) > EPS) {
            return 0;
        }
    }

    for (int i = 0; i < m; i++) {
        if (where[i] == -1) {
            return INF;
        }
    }
    return 1;
}
