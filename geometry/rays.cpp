double ray_dis(point p, point a, point b) {
    double abc = point_angle(p, a, b);
    
    if (abc + eps < pi / 2) {
        line l;
        line_build(l, p1, p2);
        return line_dis(l, p);
    }
    else {
        return sqrt(a);
    }
}