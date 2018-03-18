#include <fstream>
#include <iomanip>

int main() {
	std::ifstream in;
	std::ofstream out;
	in.open("garland.in");
	out.open("garland.out");
	int n;
	double A;
	in >> n >> A;
	double left = 0;
	double right = A;
	double B = -1;
	while (true) {
		double mid = (left + right) / 2;
		if (mid == left || mid == right) break;
		double prev = A;
		double cur = mid;
		bool flag = true;
		for (int i = 3; i <= n; i++) {
			double next = 2 * cur - prev + 2;
			prev = cur;
			cur = next;
			flag &= cur > 0;
		}
		if (flag) {
			right = mid;
			B = cur;
		} else {
			left = mid;
		}
	}
	out << std::fixed << std::setprecision(2) << B;
	out.close();
	return 0;
}