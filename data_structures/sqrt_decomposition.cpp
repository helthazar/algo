const int MAXN = 100001;
const int BLSIZE = 320;

int bl[MAXN / BLSIZE + 1];
int addbl[MAXN / BLSIZE + 1];

int a[MAXN];

int sum(int l, int r) {
    int sum = 0;
    
    int il = l / BLSIZE;
    int ir = r / BLSIZE;
    
    if (il == ir) {
        for (int i = l; i <= r; i++) {
            sum += a[i] + addbl[il];
        }
    }
    else {
        for (int i = l, end = (il + 1) * BLSIZE - 1; i <= end; i++) {
            sum += a[i] + addbl[il];
        }
        
        for (int i = il + 1; i <= ir - 1; i++) {
            sum += bl[i] + addbl[i] * BLSIZE;
        }
        
        for (int i = ir * BLSIZE; i <= r; i++) {
            sum += a[i] + addbl[ir];
        }
    }
    
    return sum;
}

void update(int l, int r, int val) {
    int il = l / BLSIZE;
    int ir = r / BLSIZE;
    
    if (il == ir) {
        for (int i = l; i <= r; i++) {
            a[i] += val;
            bl[il] += val;
        }
    }
    else {
        for (int i = l, end = (il + 1) * BLSIZE - 1; i <= end; i++) {
            a[i] += val;
            bl[il] += val;
        }
        
        for (int i = il + 1; i <= ir - 1; i++) {
            addbl[i] += val;
        }
        
        for (int i = ir * BLSIZE; i <= r; i++) {
            a[i] += val;
            bl[ir] += val;
        }
    }
}