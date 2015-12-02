struct matrix {
    long double a[3][3];
    
    matrix() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) {
                    a[i][j] = 1;
                }
                else {
                    a[i][j] = 0;
                }
            }
        }
    }
    
    void print() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                dout << a[i][j] << " ";
            }
            dout << endl;
        }
    }
    
    void valprint() {
        dout << a[2][2] << endl;
    }
};

void mul(matrix l, matrix r, matrix &res) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            long double sum = 0;
            for (int k = 0; k < 3; k++) {
                sum += l.a[i][k] * r.a[k][j];
            }
            res.a[i][j] = sum;
        }
    }
}

void binpow(matrix x, matrix &res, int n) {
    if (n == 0) {
        res = matrix();
    }
    else {
        binpow(x, res, n >> 1);
        mul(res, res, res);
        if (n & 1) {
            mul(res, x, res);
        }
    }
}