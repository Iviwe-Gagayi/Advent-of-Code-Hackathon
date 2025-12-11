#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> keys;

vector<vector<string>> adj;

int findKeyIndex(const string& target) {
    for (int i = 0; i < keys.size(); i++) {
        if (keys[i] == target) {
            return i;
        }
    }
    return -1;
}


void populateGraph() {
    string line;
    cout << "Enter the graph structure (type 'end' to finish):" << endl;
    cout << "Format example: 'aaa: you hhh'" << endl;

    while (true) {
        getline(cin, line);


        if (line == "end" || line.empty()) {
            break;
        }


        size_t colonPos = line.find(':');
        if (colonPos == string::npos) continue;


        string key = line.substr(0, colonPos);


        string valuesPart = line.substr(colonPos + 1);


        stringstream ss(valuesPart);
        string neighbor;
        vector<string> row;

        while (ss >> neighbor) {
            row.push_back(neighbor);
        }


        keys.push_back(key);
        adj.push_back(row);
    }
}


int countRoutes(string current) {

    if (current == "out") {
        return 1;
    }

    int index = findKeyIndex(current);


    if (index == -1) {
        return 0;
    }

    int totalRoutes = 0;


    for (const string& nextNode : adj[index]) {
        totalRoutes += countRoutes(nextNode);
    }

    return totalRoutes;
}

int main() {

    populateGraph();


    string startNode = "you";


    if (findKeyIndex(startNode) == -1) {
        cout << "Error: The starting node '" << startNode << "' was not found in the input." << endl;
    } else {
        int result = countRoutes(startNode);
        cout << "---------------------------------" << endl;
        cout << "Total possible routes from '" << startNode << "' to 'out': " << result << endl;
    }

    return 0;
}