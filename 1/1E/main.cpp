#include <fstream>

int main() {
    std::ifstream in;
    std::ofstream out;
    in.open("sortland.in");
    out.open("sortland.out");
    int n;
    in >> n;
    float *arr = new float[n];
    float *arr_index = new float[n];
    for (int i = 0; i < n; i++)
        in >> arr[i];

    for (int i = 0; i < n; i++)
        arr_index[i] = i + 1;
    for (int j = 1; j < n; j++) {
        float key = arr[j];
        int i = j - 1;
        for (; i >= 0 && arr[i] > key; i--) {
            arr[i + 1] = arr[i];
            arr_index[i + 1] = arr_index[i];
        }
        arr[i + 1] = key;
        arr_index[i + 1] = j + 1;
    }

    out << arr_index[0] << " " << arr_index[(n - 1) / 2] << " " << arr_index[n - 1];
    in.close();
    out.close();
    return 0;
}

