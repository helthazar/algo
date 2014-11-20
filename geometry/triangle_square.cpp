double triang(point p[]) {
    double x1 = p[1].x - p[0].x, y1 = p[1].y - p[0].y,
           x2 = p[2].x - p[0].x, y2 = p[2].y - p[0].y;
    return fabs(x1 * y2 - x2 * y1) / 2;
}