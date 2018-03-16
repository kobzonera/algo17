#include <fstream>
#include <ctime>

void quick_sort(int *array, int start, int end) {
    srand(time(NULL));
    int i = start, j = end;
    int rand_key = array[start + (rand() % (end - start))];
    while (i <= j) {
        while (array[i] < rand_key) { i++; }
        while (array[j] > rand_key) { j--; }
        if (i <= j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (start < j) quick_sort(array, start, j);
    if (i < end) quick_sort(array, i, end);
}

int main() {
    std::ifstream in;
    std::ofstream out;
    in.open("sort.in");
    out.open("sort.out");
    int n;
    in >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        in >> arr[i];
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n - 1; i++)
        out << arr[i] << " ";
    out << arr[n - 1];
    in.close();
    out.close();
    return 0;
}
