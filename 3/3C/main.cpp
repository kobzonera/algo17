#include <fstream>

int main() {
	std::ifstream in;
	std::ofstream out;
	in.open("isheap.in");
	out.open("isheap.out");
	int n;
	in >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
		in >> arr[i];
	for (int i = 0; (2 * i + 1) < n; i++) {
		if (arr[i] > arr[2 * i + 1]) {
			out << "NO";
			out.close();
			return 0;
		}
		if ((2 * i + 2) < n && arr[i] > arr[2 * i + 2]) {
			out << "NO";
			out.close();
			return 0;
		}
	}
	out << "YES";
	out.close();
	return 0;
}