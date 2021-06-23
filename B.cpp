// Nikita on 15.03.2021.
#include <string>
#include <iostream>
#include <vector>
#include <stack>

//Массивы
std::vector<std::string> resalt;
std::vector<std::pair<char, int>> bin;

void index_find(char c, int &ind, int &anim, int &cage);
int main(){
    //Переменные
    std::string line;
    int ind = 0, anim = 0, cage = 0;
    std::cin >> line;
    resalt = std::vector<std::string> (line.length());
    //Цикл
    for (int i = 0; i < line.size(); i++){
        if (!bin.empty() && tolower(bin.back().first) == tolower(line[i])) {
            if (bin.back().first != line[i]) {
                ind = bin.back().second;
                if (!islower(line[i])) {
                    resalt[cage++] = std::to_string(ind);
                } else {
                    resalt[ind] = std::to_string(++anim);
                }
                bin.pop_back();
            } else {
                index_find(line[i], ind, anim, cage);
                bin.emplace_back(line[i], ind);
            }
        } else {
            index_find(line[i], ind, anim, cage);
            bin.emplace_back(line[i], ind);
        }
    }
    if (bin.size() <= 0) {
        printf("%s\n", "Possible");
        for (auto it = resalt.begin(); it != resalt.end(); ++it) std::cout << *it << " ";
    } else {
        printf("%s\n", "Impossible");
    }
    return 0;
}


void index_find(char c, int &ind, int &anim, int &cage) {
    if (!islower(c)) {
        ind = cage++;
    } else {
        ind = ++anim;
    }
}
