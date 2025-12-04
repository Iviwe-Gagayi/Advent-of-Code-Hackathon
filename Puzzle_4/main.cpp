#include <iostream>
#include <vector>
using namespace std;



int main() {
    int counter = 0;
    int rolls = 0;
    bool removed = false;

    vector<pair<int,int>> coords(135);

    vector<vector<char>> table(135, vector<char>(135));
    for (int i = 0; i < 135; i++) {
        for (int j = 0; j < 135; j++) {
            cin >> table[i][j];
        }
    }

    // for (int i = 0; i < 135; i++) {
    //     for (int j = 0; j < 135; j++) {
    //         cout << table[i][j] << " ";
    //     }
    //     cout << endl;
    // }

   while (removed == false) {
        removed = true;
        for (int i = 0; i < 135; i++) {
            counter = 0;
            for (int j = 0; j < 135; j++) {
                if (table[i][j] == '.') {continue;}
                //left and right
                if (j != 134){if (table[i][j+1] == '@')counter++; }
                if (j != 0){if (table[i][j-1] == '@')counter++; }
                //up and down
                if (i!= 134){if (table[i+1][j] == '@')counter++; }
                if (i!= 0){if (table[i-1][j] == '@')counter++; }
                //diagonal
                if (i!=134){if (table[i+1][j+1] == '@')counter++; }
                if (i!=134){if (table[i+1][j-1] == '@')counter++; }
                if (i!=0){if (table[i-1][j+1] == '@')counter++; }
                if (i!=0){if (table[i-1][j-1] == '@')counter++; }


                if (counter < 4 ){rolls++;  removed = false; coords.push_back({i,j});}
                counter = 0;
            }
        }
    for (auto p : coords) {
        table[p.first][p.second] = '.';
    }
    }

    cout << "rolls is: " << rolls << endl;



    return 0;
}