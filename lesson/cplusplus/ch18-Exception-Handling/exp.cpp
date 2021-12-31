#include <iostream>
#include <vector>

struct S {
    S() {a = ++cnt;}
    int a;
    static int cnt;
};

int S::cnt = 0;

int main () {
    std::vector<S> sv(5);
    sv.push_back(S());

    for (std::size_t i = 0; i <  sv.size(); ++i)
        std::cout << sv[i].a << " ";
    std::cout << std::endl;
}