#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>



using namespace std;

int main()
{
    int n, m, xFront, yFront, xBack, yBack;
    cin >> n >> m >> xFront >> yFront >> xBack >> yBack;
    vector<vector<int>> count(n, vector<int>(m, INT32_MAX));
    vector<vector<int>> playground(n, vector<int>(m, -1));
    

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char way;
            cin >> way;
            if (way == 'W') {
                playground[i][j] = 2;
            }
            if (way == '.') {
                playground[i][j] = 1;
            }
        }
    }

    queue<pair<int, int>> line;
    xBack -= 1;
    yBack -= 1;
    count[xFront - 1][yFront - 1] = 0;
    line.push({xFront - 1, yFront - 1});
    while (!line.empty()) {
        int x = line.front().first;
        int y = line.front().second;
        line.pop();
        if (x + 1 < n) {
            if (playground[x + 1][y] != -1) {
                if (count[x + 1][y] > count[x][y] + playground[x + 1][y]) {
                    count[x + 1][y] = count[x][y] + playground[x + 1][y];
                    line.push({x + 1, y });
                }
            }
        }
        if (x - 1 > -1) {
            if (playground[x - 1][y] != -1) {
                if (count[x - 1][y] > count[x][y] + playground[x - 1][y]) {
                    count[x - 1][y] = count[x][y] + playground[x - 1][y];
                    line.push({x - 1, y });
                }
            }
        }
        if (y - 1 > -1) {
            if (playground[x][y - 1] != -1) {
                if (count[x][y - 1] > count[x][y] + playground[x][y - 1]) {
                    count[x][y - 1] = count[x][y] + playground[x][y - 1];
                    line.push({x, y - 1});
                }
            }
        }

        if (y + 1 < m) {
            if (playground[x][y + 1] != -1) {
                if (count[x][y + 1] > count[x][y] + playground[x][y + 1]) {
                    count[x][y + 1] = count[x][y] + playground[x][y + 1];
                    line.push({x, y + 1});
                }
            }
        }
    }

    int x = xBack;
    int y = yBack;
    if (count[x][y] == INT32_MAX) {
        cout << -1;
        return 0;
    }

    cout << count[x][y] << endl;
    string answer;
    while (count[x][y] != 0) {


        if (x + 1 < n && count[x + 1][y] + playground[x][y] == count[x][y]) {
            answer += "N";
            ++x;
            continue;
        }
        if (x - 1 > -1 && count[x - 1][y] + playground[x][y] == count[x][y]) {
            answer += "S";
            --x;
            continue;
        }

        if (y - 1 > -1 && count[x][y - 1] + playground[x][y] == count[x][y]) {
            answer += "E";
            --y;
            continue;
        }

        if (y + 1 < m && count[x][y + 1] + playground[x][y] == count[x][y]) {
            answer += "W";
            ++y;
            continue;
        }

    }
	std::reverse(answer.begin(), answer.end());

    cout << answer;

    return 0;
}
