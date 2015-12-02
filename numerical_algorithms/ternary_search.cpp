long double ternary(long double l, long double r) {
    while (r - l > eps) {
        long double x1 = l + (r - l) / 3.0;
        long double x2 = l + 2.0 * (r - l) / 3.0;
        
        long double f1 = f(x1);
        long double f2 = f(x2);
        
        if (f1 > f2) {
            l = x1;
        }
        else {
            r = x2;
        }
    }
    return (l + r) / 0.5;
}

