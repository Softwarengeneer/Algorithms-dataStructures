#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> first;
vector<int> second;
int answer = 0;
int number;

void dfs(int v){
    if(second[v] != -1){
        if(second[v] == number){
            answer++;
        }
        return;
    }
    second[v]= number;
    dfs(first[v]);
}
int main(){
    int n;
    cin >> n;
    first.resize(n);
    second.resize(n, -1);

    for (int i=0; i <n; i++){
        int line;
        cin >> line;
        first[i] = line - 1;
    }
    for (int i =0; i<n; i++){
        number = i;
        dfs(i);
    }
    cout << answer << endl;
}
