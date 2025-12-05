#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <bits/ranges_algo.h>
using namespace  std;

int main() {
    string input;
    bool bsecond = false;
    vector<pair<long long, long long>> ranges;
    string begin, end;
    long long total = 0;

    getline(cin, input);

    while (input != "end") {
        if (input == "end") {
            break;
        }
        for (int i = 0; i < input.size(); i++) {
            if (bsecond) {
                end += input[i];
            }
            else if (input[i] != '-' && bsecond == false) {
                begin += input[i];
            }else if (input[i] == '-') {
                bsecond = true;
            }
        }

        ranges.emplace_back(stoll(begin),stoll(end));
        getline(cin, input);
        bsecond = false;
        begin.clear();
        end.clear();
    }


    vector<pair<long long, long long>> merged;
    sort(ranges.begin(), ranges.end());
    merged.push_back(ranges[0]);

    for (int i = 1; i < ranges.size(); i++) {
        if (ranges[i].first <= merged.back().second) {
            merged.back().second = max(merged.back().second, ranges[i].second);
        }else {
            merged.push_back(ranges[i]);
        }
    }

    for (auto p : merged) {
        total += ((p.second - p.first) + 1);
    }

    cout << total << " id's are fresh" << endl;

    return 0;
}