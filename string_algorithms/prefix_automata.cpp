const int MAXN = 100001;

const int MAXA = 128;

int p[MAXN];
int paut[MAXN][MAXA];

void prefix_function(string s) {
    int n = (int) s.length();
    
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        
        if (s[i] == s[j]) {
            j++;
        }
        
        p[i] = j;
    }
}

void prefix_automata_build(string s) {
    s += "$";
    
    int n = (int) s.length();
    
    prefix_function(s);
    
    for (int i = 0; i < n; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (i > 0 && c != s[i]) {
                paut[i][c] = paut[p[i - 1]][c];
            }
            else {
                paut[i][c] = i + (c == s[i]);
            }
        }
    }
}

vector<int> prefix_automata_find(string s, string t) {
    int n = (int) s.length();
    
    vector<int> pos;
    
    for (int i = 0, j = 0; i < t.length(); i++) {
        j = paut[j][t[i]];
        if (j == n) {
            pos.push_back(i - n + 2);
        }
    }
    
    return pos;
}
