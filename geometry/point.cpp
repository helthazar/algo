const double pi = acos(-1.0);
const double eps = 1e-9;

struct point {
    double x, y;
};

double sqr(double a) {
    return a * a;
}

double point_dis_sqr(point a, point b) {
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

double point_dis(point a, point b) {
    return sqrt(point_dis_sqr(a, b));
}

double point_angle(point a, point b, point c) {
    double ab = point_dis_sqr(a, b);
    double bc = point_dis_sqr(b, c);
    double ca = point_dis_sqr(c, a);
    
    return acos((ab + bc - ca) / (2.0 * sqrt(ab) * sqrt(bc)));
}

double point_polar_angle(point p) {
    double angle = atan2(p.y, p.x);
    if (angle < 0) {
        angle += 2 * pi;
    }
    return angle;
}