#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main()
{
    int n;
    int m;
    cin >> n >> m;
    priority_queue<pair<int, int>> queue;
    vector<pair<int, int>> instructions;
    multiset<int> vacant;
    queue.push({ n, 1 });
    vacant.insert(1);
    vacant.insert(n);
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        if (a <= 0) {
            a = abs(a);
            instructions.push_back({0, 0});
            if (instructions[a - 1].first != 0) {
                vacant.insert(instructions[a - 1].second);
                vacant.insert(instructions[a - 1].second + instructions[a - 1].first - 1);
                if (vacant.find(instructions[a - 1].second - 1) != vacant.end()) {
                    vacant.erase(vacant.find(instructions[a - 1].second - 1));
                    vacant.erase(vacant.find(instructions[a - 1].second));
                }
                if (vacant.find(instructions[a - 1].second + instructions[a - 1].first) != vacant.end()) {
                    vacant.erase(vacant.find(instructions[a - 1].second + instructions[a - 1].first));
                    vacant.erase(vacant.find(instructions[a - 1].second + instructions[a - 1].first - 1));
                }
                auto add = vacant.lower_bound(instructions[a - 1].second);
                if (*add != instructions[a - 1].second) {
                    int right = *add;
                    --add;
                    queue.push({right - *add + 1, *add});
                } else {
                    int left = *add;
                    ++add;
                    queue.push({*add - left + 1, left});
                }
                instructions[a - 1].first = 0;
            }
        } else {
            auto front = queue.top();
            queue.pop();
            auto add = vacant.find(front.second);
            int upper = n;
            if (add != vacant.end() && ++add != vacant.end()) {
                upper = *add;
            }
            while ((vacant.find(front.second) == vacant.end() || upper - front.second + 1 != front.first) &&
                   !queue.empty()) {
                front = queue.top();
                queue.pop();
                upper = n;
                add = vacant.find(front.second);
                if (add != vacant.end() && ++add != vacant.end()) {
                    upper = *add;
                }
            }
            if (front.first >= a && vacant.find(front.second) != vacant.end() && upper - front.second + 1 == front.first) {
                cout << front.second << endl;
                instructions.push_back({a, front.second});
                vacant.erase(vacant.find(front.second));
                front.first != a ? vacant.insert(front.second + a) : vacant.erase(vacant.find(front.second + a - 1));
                queue.push({front.first - a, front.second + a});
            } else {
                cout << -1 << endl;
                instructions.push_back({0, 0});
                queue.push(front);
                
            }
        }
    }
}
