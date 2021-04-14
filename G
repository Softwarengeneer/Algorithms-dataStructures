#include <iostream>
#include <map>
#include <algorithm>

std::map<char, int> map1;
std::string values;
std::string str_mid;

int main() {
    std::string input;
    std::cin >> input;
    for (char i = 'a'; i <= 'z';i++)std::cin >> map1[i];
    for (auto i = input.begin(); i != input.end(); i++){
        if ((values.find(*i) == std::string::npos) && std::count(input.begin(),input.end(),*i) > 1) values.push_back(*i);
        else str_mid.push_back(*i);
    }
    std::sort(values.begin(), values.end(), [](auto i, auto j){
        return map1.find(i)->second < map1.find(j)->second;
    });
    for (char val : values) str_mid.erase(str_mid.find(val), 1);
    std::reverse(values.begin(), values.end());
    std::cout << values;
    std::cout << str_mid;
    std::reverse(values.begin(), values.end());
    std::cout << values << std::endl;
}

//6 8 7 3 1 2 6 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
