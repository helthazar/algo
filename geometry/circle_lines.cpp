void intersect_circle_line(double a, double b, double c, double r, double x1, double y1) {
    double x0 = -a*c/(a*a+b*b),  y0 = -b*c/(a*a+b*b);
    if (c*c > r*r*(a*a+b*b)+EPS)
        printf("0\n");
    else if (abs (c*c - r*r*(a*a+b*b)) < EPS) {
        printf("1\n");
        printf("%0.9lf %0.9lf\n", x0 + x1, y0 + y1);
    }
    else {
        double d = r*r - c*c/(a*a+b*b);
        double mult = sqrt (d / (a*a+b*b));
        double ax,ay,bx,by;
        ax = x0 + b * mult + x1;
        bx = x0 - b * mult + x1;
        ay = y0 - a * mult + y1;
        by = y0 + a * mult + y1;
        printf("2\n");
        printf("%0.9lf %0.9lf\n", ax, ay);
        printf("%0.9lf %0.9lf\n", bx, by);
    }
}

void intersect_circles(double x1, double y1, double x2, double y2, double r1, double r2) {
    if (fabs(x1 - x2) < EPS && fabs(y1 - y2) < EPS) {
        if (fabs(r1 - r2) < EPS) {
            printf("3\n");
        }
        else {
            printf("0\n");
        }
        return;
    }
    x2 -= x1;
    y2 -= y1;
    double a = - 2.0 * x2;
    double b = - 2.0 * y2;
    double c = x2 * x2 + y2 * y2 + r1 * r1 - r2 * r2;
    intersect_circle_line(a, b, c, r1, x1, y1);
}