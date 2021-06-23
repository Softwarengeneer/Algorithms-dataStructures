#include <iostream>
#include <vector>

using namespace std;

int main() {
    size_t n, m;
    cin >> n >> m;
    vector<vector<int>> field(n, vector<int>(m, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            if (c != '.')
                field[i][j] = c - '0';
        }
    }
    vector<vector<pair<int, int>>> next_index_horizontal(n, {m, {-1, -1}});
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (field[i][j] != -1) {
                size_t first = j;
                while(++j < m && field[i][j] != -1);
                if (first == j - 1)
                    continue;
                for (int k = 0; k < (j - first) / 2; ++k) {
                    next_index_horizontal[i][first + k] = {i, j - k - 1};
                    next_index_horizontal[i][j - k - 1] = {i, first + k};
                }
            }
        }
    }

    vector<vector<pair<int, int>>> next_index_vertical(n, {m, {-1, -1}});
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (field[i][j] != -1) {
                size_t first = i;
                while(++i < n && field[i][j] != -1);
                if (first == i - 1)
                    continue;
                for (int k = 0; k < (i - first) / 2; ++k) {
                    next_index_vertical[first + k][j] = {i - k - 1, j};
                    next_index_vertical[i - k - 1][j] = {first + k, j};
                }
            }
        }
    }

    vector<vector<bool>> used(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (field[i][j] != -1 && !used[i][j]) {
                used[i][j] = true;
                size_t digit_count[10] = {};
                ++digit_count[field[i][j]];
                size_t count = 1;
                pair<int, int> first = {i, j};
                auto cur = next_index_horizontal[i][j];
                auto cur_index = &next_index_vertical;
                auto other_index = &next_index_horizontal;
                while (cur != pair<int, int>{-1, -1} && cur != first) {
                    used[cur.first][cur.second] = true;
                    ++digit_count[field[cur.first][cur.second]];
                    ++count;
                    cur = (*cur_index)[cur.first][cur.second];
                    swap(cur_index, other_index);
                }
                if (cur != first) {
                    cur = next_index_vertical[i][j];
                    cur_index = &next_index_horizontal;
                    other_index = &next_index_vertical;
                    while (cur != pair<int, int>{-1, -1}) {
                        used[cur.first][cur.second] = true;
                        ++digit_count[field[cur.first][cur.second]];
                        ++count;
                        cur = (*cur_index)[cur.first][cur.second];
                        swap(cur_index, other_index);
                    }
                }

                int d = 0;
                for (size_t sum = 0; ; ++d){
                    sum += digit_count[d];
                    if (sum >= (count - 1) / 2 + 1)
                        break;
                }
                field[i][j] = d;
                cur = next_index_horizontal[i][j];
                cur_index = &next_index_vertical;
                other_index = &next_index_horizontal;
                while (cur != pair<int, int>{-1, -1} && cur != first) {
                    field[cur.first][cur.second] = d;
                    cur = (*cur_index)[cur.first][cur.second];
                    swap(cur_index, other_index);
                }
                if (cur != first) {
                    cur = next_index_vertical[i][j];
                    cur_index = &next_index_horizontal;
                    other_index = &next_index_vertical;
                    while (cur != pair<int, int>{-1, -1}) {
                        field[cur.first][cur.second] = d;
                        cur = (*cur_index)[cur.first][cur.second];
                        swap(cur_index, other_index);
                    }
                }

            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << (field[i][j] == -1 ? '.' : char('0' + field[i][j]));
        }
        cout << endl;
    }
}
