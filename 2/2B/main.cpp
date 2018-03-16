#include <fstream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

void merge(vector <pair<string, string>> &arr_str,
           int firstA,
           int lastA,
           int firstB,
           int lastB) {
    int i = firstA;
    int j = firstB;
    int nA = lastA - firstA + 1;
    int nB = lastB - firstB + 1;
    vector <pair<string, string>> arr_str_temp;
    while (i < firstA + nA || j < firstB + nB) {
        if (j == firstB + nB ||
            (i < firstA + nA && arr_str[i].first.compare(arr_str[j].first) <= 0))
        {
            arr_str_temp.push_back(arr_str[i]);
            i++;
        } else
        {
            arr_str_temp.push_back(arr_str[j]);
            j++;
        }
    }
    int index = firstA;
    for (auto it :arr_str_temp) {
        arr_str[index] = it;
        index++;
    }
}

void merge_sort(vector <pair<string, string>> &arr_str, int first, int last) {
    int nA = last - first + 1;
    int mid = first + nA / 2;
    if (nA == 1)
        return;
    merge_sort(arr_str, first, mid - 1);
    merge_sort(arr_str, mid, last);
    return merge(arr_str, first, mid - 1, mid, last);
}

void radix_sort(vector <pair<string, string>> &arr, int k) {
    for (auto it : arr)
        while (it.first.size() < k)
            it.first.append("0");

    merge_sort(arr, 0, arr.size() - 1);

    for (int i = k - 1; i > 0; i--)
        for (auto it : arr)
            if (it.first[i] == '0')
                it.first.pop_back();
}

int main() {
    std::ifstream in;
    std::ofstream out;
    in.open("race.in");
    out.open("race.out");
    int n;
    in >> n;
    vector <pair<string, string>> countries_and_players(n);
    string country, player;
    for (int i = 0; i < n; i++) {
        in >> country >> player;
        countries_and_players[i] = make_pair(country, player);
    }

    radix_sort(countries_and_players, 10);

    out << "=== " << countries_and_players[0].first << " ===" << std::endl;
    out << countries_and_players[0].second << std::endl;
    for (int i = 1; i < n; i++) {
        if (countries_and_players[i].first.compare(countries_and_players[i - 1].first)) {
            out << "=== " << countries_and_players[i].first << " ===" << std::endl;
        }
        out << countries_and_players[i].second << std::endl;
    }
    in.close();
    out.close();
    return 0;
}