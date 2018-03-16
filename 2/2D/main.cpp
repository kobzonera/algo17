#include <fstream>

void quick_test(int *arr, int n) {
    for (int i = 2; i < n; i++) {
        int temp = arr[i];
        arr[i] = arr[i / 2];
        arr[i / 2] = temp;
    }
}

int main() {
    std::ifstream in;
    std::ofstream out;
    int n;
    in.open("antiqs.in");
    out.open("antiqs.out");
    in >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;
    quick_test(arr, n);
    for (int i = 0; i < n; i++)
        out << arr[i] << " ";
    in.close();
    out.close();
    return 0;
}