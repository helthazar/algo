const double pi = acos(- 1.0);
const double eps = 1e-9;

double dis_interval(point p, point A, point B) {
    double x1 = A.x, y1 = A.y, x2 = B.x, y2 = B.y;
    double a = sqr(p.x - x1) + sqr(p.y - y1);
    double b = sqr(x1 - x2) + sqr(y1 - y2);
    double c = sqr(p.x - x2) + sqr(p.y - y2);
    
    double alpha = acos((a + b - c) / (2.0 * sqrt(a) * sqrt(b)));
    double betta = acos((b + c - a) / (2.0 * sqrt(b) * sqrt(c)));
    
    if (alpha + eps < pi / 2 && betta + eps < pi / 2) {
        line l;
        build_line(l, A, B);
        return dis_line(l, p);
    }
    
    return min(sqrt(a), sqrt(c));
}

double signed_triang(point p0, point p1, point p2) {
    double x1 = p1.x - p0.x, y1 = p1.y - p0.y,
    x2 = p2.x - p0.x, y2 = p2.y - p0.y;
    return (x1 * y2 - x2 * y1);
}

inline bool bounding_box (int a, int b, int c, int d) {
    if (a > b)  swap (a, b);
    if (c > d)  swap (c, d);
    return max(a,c) <= min(b,d);
}

bool intersect_interval (point a, point b, point c, point d) {
    return bounding_box (a.x, b.x, c.x, d.x)
    && bounding_box (a.y, b.y, c.y, d.y)
    && signed_triang(a,b,c) * signed_triang(a,b,d) <= 0
    && signed_triang(c,d,a) * signed_triang(c,d,b) <= 0;
}