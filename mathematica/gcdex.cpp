int gcdex(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    
    int x1, y1;
    int g = gcdex(b % a, a, x1, y1);
    
    x = y1 - (b / a) * x1;
    y = x1;
    
    return g;
}

int inverse(int a, int m) {
    int x, y;
    int g = gcdex(a, m, x, y);
    
    if (g != 1) {
        return - 1;
    }
    
    x = (x % m + m) % m;
    
    return x;
}