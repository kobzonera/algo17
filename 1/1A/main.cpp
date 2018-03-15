#include <fstream>

int main() {
    std::ifstream in;
    std::ofstream out;
    in.open("aplusb.in");
    out.open("aplusb.out");
    int a, b;
    in >> a >> b;
    out << a + b;
    in.close();
    out.close();
    return 0;
}

