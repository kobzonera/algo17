#include <fstream>
#include <cmath>

void max_heapify(int *arr, int n, int i) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest = i;
	if (left < n && arr[left] > arr[i])
		largest = left;
	if (right < n && arr[right] > arr[largest])
		largest = right;
	if (largest != i) {
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		max_heapify(arr, n, largest);
	}
}

void build_maxHeap(int *arr, int n) {
	for (int i = n / 2 + 1; i >= 0; i--) {
		max_heapify(arr, n, i);
	}
}

void heap_sort(int *arr, int n) {
	build_maxHeap(arr, n);
	for (int i = n - 1; i > 0; i--) {
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		max_heapify(arr, i, 0);
	}
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
	heap_sort(arr, n);
	for (int i = 0; i < n; i++)
		out << arr[i] << " ";
	out.close();
	return 0;
}