#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;


int  playground[1000][1000];
bool pointer[1000][1000];
bool passed[1000];
int n;

void dfs(int start, int se)
{
    passed[start] = true;
    for (int to = 0; to < n; to++) {
        if (!passed[to] && (se ? pointer[to][start] : pointer[start][to])) {
            dfs(to, se);
        }
    }
}
bool isVisited()
{
    for (int in = 0; in < n; in++)
        if (!passed[in]) return false;
    return true;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> playground[i][j];
        }}
    if (n == 1) {
        cout << 0;
        exit(0);
    }
    int mid;
    int l = 0;
    int r = INT32_MAX;
    while (l < r) {
        mid = (l+r)/2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pointer[i][j] = (mid >= playground[i][j]);
            }}
        bool done = false;
        memset(passed, false, sizeof(passed));
        dfs(0, false);
            if (isVisited()) {
                memset(passed, false, sizeof(passed));
                dfs(0, true);
                if (!isVisited()) {
                    done = true;
                }
            } else {
                done = true;
            }
        if (done) l = mid + 1;
        else r = mid;
    }
    cout << (l+r)/2;
}
