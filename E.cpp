#include <iostream>
#include <vector>

using namespace std;
int main() {
    vector<int> arr;
    int n;
    int k;
    int left;
    int right;
    int enough;
    int j;
    int middle;

    cin >> n;
    cin >> k;

    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        arr.push_back(c);
    }
    left = 0;
    right = arr.back() - arr.front() + 1;
    while (right-left > 1) {
        middle = (left + right) / 2;
        enough = 1;
        j = arr.front();
        for(int i : arr){
            if (i - j >= middle) {
                j = i;
                enough++;
            }
        }
        if (enough >= k){
            left = middle;
        } else{
            right = middle;
        }
    }
    cout << left<< endl;
    return 0;
}
