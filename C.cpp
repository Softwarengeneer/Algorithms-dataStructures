#include <vector>
#include <map>
#include <iostream>

std::map<std::string, std::string> m;
std::vector<std::map<std::string, std::string>> y;
void getChars(const std::string &ch, std::string &s1, std::string &s2);
void push(const std::string &s1);
int main() {
    

    std::string ch;
    y.emplace_back();


    while (getline(std::cin, ch)) {

        if (ch == "}") {

            for (const auto& it : y.back()) {
                m[it.first] = it.second;
            }

            y.pop_back();
        }
        else if (ch == "{") {
            y.emplace_back();
        }
        else{
            std::string s1, s2;
            getChars(ch, s1, s2);
            if (atoi(s2.c_str())) {
                push(s1);
                m[s1] = s2;
            }
            else {
                int res;
                if (m[s2].empty()) {
                    res = atoi("0");
                }
                else {
                    res = atoi(m[s2].c_str());
                }
                push(s1);
                m[s1] = std::to_string(res);
                std::cout << std::to_string(res) << std::endl;
            }
        }
    }
}
void push(const std::string &s1) {
    if (y.back()[s1].empty()) {
        if (m[s1].empty()) {
            y.back()[s1] = "0";
        } else {
            y.back()[s1] = m[s1];
        }
    }
}
void getChars(const std::string &ch, std::string &s1, std::string &s2) {
    auto p = ch.find('=');
    s1= ch.substr(0, p);
    s2= ch.substr(p + 1);
}
