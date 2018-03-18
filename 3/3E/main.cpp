#include <fstream>

#define K 26
int alphabet_ascii[K];

void counting_sort(char *last_digit, int n, int *index_char) {
	int char_ascii;
	int *index_last_digit = new int[n];
	for (int i = 0; i < K; i++)
		alphabet_ascii[i] = 0;
	for (int i = 0; i < n; i++) {
		char_ascii = last_digit[index_char[i]] - 97;
		alphabet_ascii[char_ascii] = alphabet_ascii[char_ascii] + 1;
	}
	for (int i = 1; i < K; i++)
		alphabet_ascii[i] = alphabet_ascii[i] + alphabet_ascii[i - 1];
	for (int i = n - 1; i >= 0; i--) {
		char_ascii = last_digit[index_char[i]] - 97;
		index_last_digit[alphabet_ascii[char_ascii] - 1] = i;
		alphabet_ascii[char_ascii]--;
	}
	int *index_arr_char_temp = new int[n];
	for (int i = 0; i < n; i++)
		index_arr_char_temp[i] = index_char[i];
	for (int i = 0; i < n; i++) {
		index_char[i] = index_arr_char_temp[index_last_digit[i]];
	}
	delete (index_last_digit);
	delete (index_arr_char_temp);
}

int main() {
	std::ifstream in;
	std::ofstream out;
	in.open("radixsort.in");
	out.open("radixsort.out");
	int n, m, k;
	in >> n >> m >> k;
	char **arr_char = new char *[n];
	for (int i = 0; i < n; i++) {
		arr_char[i] = new char[m];
	}
	int *index_arr_char = new int[n];
	for (int i = 0; i < n; i++) {
		index_arr_char[i] = i;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			in >> arr_char[i][j];
		}
	for (int i = m - 1; i > m - 1 - k; i--) {
		char *arr_char_temp = new char[n];
		for (int j = 0; j < n; j++) {
			arr_char_temp[j] = arr_char[j][i];
		}
		counting_sort(arr_char_temp, n, index_arr_char);
	}
	for (int i = 0; i < n; i++) {
		if (i > 0) out << std::endl;
		for (int j = 0; j < m; j++)
			out << arr_char[index_arr_char[i]][j];
	}
	out.close();
	return 0;
}