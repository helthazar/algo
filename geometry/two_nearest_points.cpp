struct point {
    int x, y, id;
};

bool cmpx(point a, point b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cmpy(point a, point b) {
    return a.y < b.y;
}

point p[MAXN];
point t[MAXN];

double mindist;
int ansa, ansb;

void update_ans(point a, point b) {
    double dist = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + .0);
    if (dist < mindist) {
        mindist = dist;
        ansa = a.id;
        ansb = b.id;
    }
}

void two_nearest(int l, int r) {
    if (r - l <= 3) {
        for (int i = l; i <= r; i++) {
            for (int j = i + 1; j <= r; j++) {
                update_ans(p[i], p[j]);
            }
        }
        sort (p + l, p + r + 1, &cmpy);
        return;
    }

    int m = (l + r) >> 1;
    int midx = p[m].x;
    two_nearest(l, m);
    two_nearest(m + 1, r);

    merge(p + l, p + m + 1, p + m + 1, p + r + 1, t, &cmpy);
    copy(t, t + r - l + 1, p + l);

    int tsz = 0;
    for (int i = l; i <= r; i++) {
        if (abs(p[i].x - midx) < mindist) {
            for (int j = tsz - 1; j >= 0 && p[i].y - t[j].y < mindist; j--) {
                update_ans(p[i], t[j]);
            }
            t[tsz++] = p[i];
        }
    }
}

void point_two_nearest(int n) {
    sort(a, a + n, &cmpx);
    mindist = 1E20;
    two_nearest(0, n - 1);
}
