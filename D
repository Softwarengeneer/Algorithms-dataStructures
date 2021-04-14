#include <iostream>
int a, b, c, d, k;
int main() {
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> d;
    int answer = 0;
    for(std::cin >> k; k>0; k--){
        a = a * b - c;
        if (a<=0) {
            answer = 0;
            break;
        }
        else if (a>=d)a=d;
        if (answer==a)break;
        answer = a;
    }
    std::cout << answer << std::endl;
    return 0;
}
