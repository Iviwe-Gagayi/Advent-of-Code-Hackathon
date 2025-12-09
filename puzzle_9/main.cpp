#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

bool isValidRectangle(pair<long long,long long> a, pair<long long,long long> b,
    const unordered_set<long long>& validTiles) {
    long long x1 = min(a.first, b.first);
    long long x2 = max(a.first, b.first);
    long long y1 = min(a.second, b.second);
    long long y2 = max(a.second, b.second);

    for (long long x = x1; x <= x2; x++) {
        for (long long y = y1; y <= y2; y++) {
            long long key = (x << 32) ^ y;
            if (!validTiles.count(key)) return false;
        }
    }
    return true;
}



int main() {

    vector<pair<long long, long long>> input;
    int counter = 0;
    while (true) {
        string num1, num2;
        string line;
        getline(cin, line);
        if (line == "end") {
            break;
        }
        for (int i = 0; i < line.size(); i++) {
            if (line[i] != ',') {
                if (counter == 0) {
                    num1 += line[i];
                }else if (counter == 1) {
                    num2 += line[i];
                }
            }else if (line[i] == ',') {
                counter++;
            }
        }
        //cout << "num 1 is: "<< num1 << endl;
        //cout <<  "num 2 is: "<<num2 << endl;
        input.emplace_back(make_pair(stoll(num1), stoll(num2)));
        num1 = "";
        num2 = "";
        counter = 0;
    }
    unordered_set<long long> validTiles;

    auto encode = [](long long x, long long y) {
        return (x << 32) ^ y;
    };

    // adding red tiles
    for (auto &p : input) {
        validTiles.insert(encode(p.first, p.second));
    }

    // connecting red tiles
    for (int i = 0; i < input.size(); i++) {
        auto [x1,y1] = input[i];
        auto [x2,y2] = input[(i+1) % input.size()];

        if (x1 == x2) {
            // vertical line
            long long ymin = min(y1,y2), ymax = max(y1,y2);
            for (long long y = ymin; y <= ymax; y++) {
                validTiles.insert(encode(x1,y));
            }
        } else if (y1 == y2) {
            // horizontal line
            long long xmin = min(x1,x2), xmax = max(x1,x2);
            for (long long x = xmin; x <= xmax; x++) {
                cout << "processing..." << endl;
                validTiles.insert(encode(x,y1));
            }
        }
    }

    long long minX = LLONG_MAX, maxX = LLONG_MIN;
    long long minY = LLONG_MAX, maxY = LLONG_MIN;
    for (auto &p : input) {
        minX = min(minX, p.first);
        maxX = max(maxX, p.first);
        minY = min(minY, p.second);
        maxY = max(maxY, p.second);
    }


    long long seedX = (minX + maxX) / 2;
    long long seedY = (minY + maxY) / 2;

    queue<pair<long long,long long>> q;
    unordered_set<long long> visited;
    q.push({seedX, seedY});

    while (!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        long long key = encode(x,y);
        if (visited.count(key)) continue;
        visited.insert(key);


        if (x < minX || x > maxX || y < minY || y > maxY) continue;

        if (validTiles.count(key)) continue;


        validTiles.insert(key);

        q.push({x+1,y});
        q.push({x-1,y});
        q.push({x,y+1});
        q.push({x,y-1});
    }


    //finding the largest area
    long long area = 0;
    for (int i = 0; i < input.size()-1; i++) {
        long long temp_area = 0;
        for (int j = i+1; j < input.size(); j++) {
            temp_area = ((abs(input[i].first - input[j].first) + 1) * ((abs(input[i].second - input[j].second)) + 1));
            if (isValidRectangle(input[i], input[j], validTiles)) {
                    area = max(area, temp_area);
            }
        }
    }

    cout << "area is: "<< area << endl;

    return 0;
}