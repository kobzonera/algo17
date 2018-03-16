#include <fstream>

int kth(int *arr, int l, int r, int k) {
    int x = arr[(l + r) / 2];
    int i = l, j = r;
    while (i <= j) {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (l <= k && k <= j) return kth(arr, l, j, k);
    if (i <= k && k <= r) return kth(arr, i, r, k);
    return arr[k];
}

int main() {
    std::ifstream in;
    std::ofstream out;
    in.open("kth.in");
    out.open("kth.out");
    int n, k;
    in >> n >> k;
    int A, B, C, a1, a2;
    in >> A >> B >> C >> a1 >> a2;
    int *arr = new int[n];
    arr[0] = a1;
    arr[1] = a2;
    for (int i = 2; i < n; i++)
        arr[i] = A * arr[i - 2] + B * arr[i - 1] + C;
    out << kth(arr, 0, n - 1, k - 1);
    in.close();
    out.close();
    return 0;
}
