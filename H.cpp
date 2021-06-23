#include <iostream>
#include <algorithm>
using namespace std;

int compare(const void * a, const void * b) {
    return *(int*)b - *(int*)a;
}

int main() {
    int n;
    int k;
    int arr[100000];
    int summa = 0;
    int sell = 0;
    cin >> n;
    cin >> k;
    int index = k - 1;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        summa += arr[i];
    }
    qsort(arr, n, sizeof(int), compare);
    if (k > n) {
         cout << summa;
         exit(0);
    }else if (k == n) {
        cout << summa - arr[n - 1];
        exit(0);

    }else {
        for (int i = 0; i < n/k; ++i) {
            sell += arr[index];
            index += k;
        }

        
    }
    cout << summa - sell << endl;

    return 0;
}
