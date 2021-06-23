#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
int main(){
    std::vector<std::string> word;
    std::string number, line;
    while (std::cin >> number) word.push_back(number);
    std::sort(word.begin(), word.end(), [](const std::string& i1, const std::string& i2){return i1+i2 > i2+i1;});
    for(const std::string& it : word)line+=it;
    std::cout << line.c_str()<< std::endl;
    return 0;
}

