#include <fstream>
#include <vector>

long long sum = 0;

void merge(std::vector<long long> &arr, int firstA, int lastA, int firstB, int lastB) {
    int i = firstA;
    int j = firstB;
    int nA = lastA - firstA + 1;
    int nB = lastB - firstB + 1;
    std::vector<long long> arr_temp;
    while (i < firstA + nA || j < firstB + nB) {
        if (j == firstB + nB || ((i < firstA + nA) && arr[i] <= arr[j])) {
            arr_temp.push_back(arr[i]);
            i++;
        } else {
            sum += firstA + nA - i;
            arr_temp.push_back(arr[j]);
            j++;
        }
    }
    int index = firstA;
    for (std::vector<long long>::iterator it = arr_temp.begin(); it != arr_temp.end(); it++) {
        arr[index] = *it;
        index++;
    }
    return;
}

void merge_sort(std::vector<long long> &arr, int first, int last) {
    int nA = last - first + 1;
    int nL = nA / 2;
    int nR = nA - nL;
    int mid = first + nL;
    if (nA == 1) { return; }
    merge_sort(arr, first, mid - 1);
    merge_sort(arr, mid, last);
    return merge(arr, first, mid - 1, mid, last);
}

int main() {
    std::ifstream in;
    std::ofstream out;
    in.open("inversions.in");
    out.open("inversions.out");
    int n;
    in >> n;
    std::vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        in >> arr[i];
    merge_sort(arr, 0, n - 1);
    out << sum;
    in.close();
    out.close();
    return 0;
}