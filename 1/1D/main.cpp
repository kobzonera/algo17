#include <fstream>

int main() {
    std::ifstream in;
    std::ofstream out;
    in.open("smallsort.in");
    out.open("smallsort.out");
    int n;
    in >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        in >> arr[i];

    for (int j = 1; j < n; j++) {
        int key = arr[j];
        int i = j - 1;
        for (; i >= 0 && arr[i] > key; i--)
            arr[i + 1] = arr[i];
        arr[i + 1] = key;
    }

    for (int i = 0; i < n; i++)
        out << arr[i] << " ";
    in.close();
    out.close();
    return 0;
}
