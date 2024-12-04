#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

string vectorToString(const vector<string>& vec, const string& label) {
    string result = label + " [";
    for (size_t i = 0; i < vec.size(); ++i) {
        result += "\"" + vec[i] + "\"";
        if (i < vec.size() - 1) result += ", ";
    }

    result += "]\n";
    return result;

}

int main() {

    vector<string> curinven = {"apples", "bananas", "oranges", "pears"};
    vector<string> shipment = {"kiwis", "bananas", "grapes"};
    unordered_set<string> SOI = {"apples", "oranges"};

    cout << vectorToString(curinven, "Current Inventory: ");
    cout << vectorToString(shipment, "Shipment: ");

    unordered_set<string> updatedinvenset(curinven.begin(), curinven.end());

    for (const auto & item : shipment) {
        updatedinvenset.insert(item);

    }

    for (const auto & item : SOI) {
        updatedinvenset.erase(item);

    }

    vector<string> updatedinv(updatedinvenset.begin(), updatedinvenset.end());

    cout << vectorToString(vector<string>(SOI.begin(), SOI.end()), "Sold-out items: ");
    cout << vectorToString(updatedinv, "Updated Inventory: ");

    return 0;

}