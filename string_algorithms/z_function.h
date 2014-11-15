string s;
int len = (int) s.length();

string t = "";
int tlen = 0;
int cnt = 0;

for (int si = 0; si < len; si++) {
    t.push_back(s[si]);
    tlen++;
    
    reverse(t.begin(), t.end());
    
    int j = 0, k = 0;
    int zmax = 0;
    for (int i = 1; i < tlen; i++) {
        z[i] = 0;
        if (i < j + k) {
            z[i] = min(z[i - j], j + k - i);
        }
        while (i + z[i] < len && t[z[i]] == t[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > j + k) {
            j = i;
            k = z[i];
        }
        zmax = max(zmax, z[i]);
    }
    
    cnt += tlen - zmax;
    
    reverse(t.begin(), t.end());
}