#include <fstream>

int main() {
    std::ifstream in;
    std::ofstream out;
    in.open("turtle.in");
    out.open("turtle.out");
    int h, w;
    in >> h >> w;
    int **arr = new int *[h];
    for (int i = 0; i < h; i++)
        arr[i] = new int[w];
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            in >> arr[i][j];

    for (int j = 0; j < w; j++)
        arr[h - 1][j + 1] = arr[h - 1][j] + arr[h - 1][j + 1];
    for (int i = h - 1; i > 0; i--)
        arr[i - 1][0] = arr[i - 1][0] + arr[i][0];

    for (int i = h - 2; i >= 0; i--)
        for (int j = 1; j < w; j++)
            if (arr[i + 1][j] < arr[i][j - 1])
                arr[i][j] += arr[i][j - 1];
            else arr[i][j] += arr[i + 1][j];

    out << arr[0][w - 1];
    in.close();
    out.close();
    return 0;
}

