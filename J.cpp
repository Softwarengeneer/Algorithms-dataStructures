#include <iostream>
#include <deque>


using namespace std;
int main() {
    int count;
    cin >> count;

    deque<int> one;
    deque<int> two;

    int number;
    char action;
    for (int i = 1; i <= count; i++) {
        cin >> action;
        if(one.size() < two.size()) {
            number = two.front();
            one.push_back(number);
            two.pop_front();
        }
        if(action=='+'){
            cin >> number;
            two.push_back(number);
        }
        else if(action=='*'){
            cin >> number;
            two.push_front(number);
        }
        else{
            cout << one.front()<<"\n";
            one.pop_front();
        }


    }
}
