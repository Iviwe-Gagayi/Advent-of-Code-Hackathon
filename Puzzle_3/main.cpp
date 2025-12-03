#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long sum = 0;
int counter = 0;

void add_sum(string input) {
    string largest;
    largest += input[0];
    for (int i = 1; i < input.length(); i++) {
        while (largest.length() > 0 && (input[i]-'0' > (largest[largest.length() - 1] - '0') && ((largest.length() + input.length() - i - 1) >= 12))) {
            largest.erase(largest.length() - 1, 1);
        }
            if (largest.length() < 12) {
                largest += input[i];
            }
    }
    cout << "adding: " << largest << endl;
    counter++;
    sum += stoll(largest);
}



int main() {
    string input;
    for (int i = 0; i < 200; i++) {
        getline(cin, input);

        add_sum(input);

    }

    cout << "the sum is: " << sum << endl;
    cout << "counter is: " << counter << endl;

    return 0;
}