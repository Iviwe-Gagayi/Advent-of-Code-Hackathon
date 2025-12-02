#include <algorithm>
#include <iostream>

using namespace std;

bool valid(string input) {
    int len = input.length();

    for (int chunk = 1; chunk <= len / 2; chunk++) {
        if (len % chunk != 0) continue;

        string pattern = input.substr(0, chunk);
        string built;

        for (int i = 0; i < len / chunk; i++) {
            built += pattern;
        }

        if (built == input) return true;
    }

    return false;
}

int main() {
    long long answer = 0;
    string input;
    cin >> input;

    bool num2 = false;
    string holder1, holder2;
    long long begin = 0, stop = 0;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] != '-' && input[i] != ',' && num2 == false) {
            holder1 += input[i];
        } else if (input[i] == '-') {
            num2 = true;
        } else if (input[i] != '-' && input[i] != ',' && num2 == true) {
            holder2 += input[i];
        } else if (input[i] == ',' || i == input.length() - 1) {
            begin = stoll(holder1);
            stop  = stoll(holder2);

            for (long long j = begin; j <= stop; j++) {
                if (valid(to_string(j))) {
                    cout << "adding: " << j << " to answer" << endl;
                    answer += j;
                }
            }

            num2 = false;
            holder1 = "";
            holder2 = "";
            begin = stop = 0;
        }
    }

    cout << "answer is: " << answer << endl;
    return 0;
}
