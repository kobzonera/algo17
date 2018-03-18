#include <fstream>
#include <cmath>

int index_first;
int index_last;

void binary_search(int *arr, int first, int end, int key) {
    int mid = (first + end) / 2;
    if (first == end) {
        if (arr[mid] == key) {
            if (mid < index_first) index_first = mid;
            if (mid > index_last) index_last = mid;
        }
        return;
    }
    if (arr[mid] == key) {
        if (index_first >= 0 && index_last >= 0) {
            if (mid < index_first) {
                index_first = mid;
                binary_search(arr, first, mid, key);
            }
            if (mid > index_last) {
                index_last = mid;
                binary_search(arr, mid + 1, end, key);
            }
        } else {
            index_first = index_last = mid;
            binary_search(arr, first, mid, key);
            binary_search(arr, mid + 1, end, key);
        }
    }
    if (arr[mid] < key) {
        binary_search(arr, mid + 1, end, key);
    }
    if (arr[mid] > key) {
        binary_search(arr, first, mid, key);
    }
}

int main() {
    std::ifstream in;
    std::ofstream out;
    in.open("binsearch.in");
    out.open("binsearch.out");
    int n, m;
    in >> n;
    int *arr_elements = new int[n];
    for (int i = 0; i < n; i++) {
        in >> arr_elements[i];
    }
    in >> m;
    int *arr_query = new int[m];
    for (int i = 0; i < m; i++) {
        in >> arr_query[i];
    }
    for (int i = 0; i < m; i++) {
        index_first = -2;
        index_last = -2;
        binary_search(arr_elements, 0, n - 1, arr_query[i]);
        out << index_first + 1 << " " << index_last + 1 << std::endl;
    }
    out.close();
    return 0;
}