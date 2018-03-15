#include <fstream>

int main() {
    std::ifstream in;
    std::ofstream out;
    in.open("aplusbb.in");
    out.open("aplusbb.out");
    long long a, b;
    in >> a >> b;
    out << a + b * b;
    in.close();
    out.close();
    return 0;
}

