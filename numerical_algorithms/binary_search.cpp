int binary(int l, int r) {
    int best = 0;

    while (l <= r) {
        int mid = (l + r) >> 1;
        if (true) {
            best = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    
    return best;
}
