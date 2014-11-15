int l = 0, r = 1000000000;
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