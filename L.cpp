#include <iostream>
#include <algorithm>
using namespace std;


int line[3000000];
int t[1000000];
void build (int v, int tl, int tr) {
    if (tl == tr)
        t[v] = line[tl];
    else {
        int tm = (tl + tr) / 2;
        build (v*2, tl, tm);
        build (v*2+1, tm+1, tr);
        t[v] = min(t[v*2] , t[v*2+1]);
    }
}
int get_min(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 2281488;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return min(get_min(v * 2, tl, tm, l, min(r, tm)), get_min(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
int main()
{
    int n;
    int k;
    cin >> n;
    cin >> k;
    for (int i = 1; i <= n; ++i)
        cin >> line[i];
    build(1, 1, n);
    for(int i = 0; i <= n - k; ++i)
        cout << get_min(1, 0, n - 1, i, i + k - 1) << ' ';
    return 0;
}
