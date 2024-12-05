#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

vector<int> findMatchingDigits(map<int, string>& digitPatterns, string currentPattern) {
    vector<int> potentialMatches;

    for (auto& entry : digitPatterns) {
        int mismatchCount = 0;
        string pattern = entry.second;

        for (size_t i = 0; i < currentPattern.size(); i++) {
            if (currentPattern[i] != pattern[i]) {
                mismatchCount++;
            }
        }

        if (mismatchCount <= 1) {
            potentialMatches.push_back(entry.first);
        }
    }

    return potentialMatches;
}

void generateCombinations(vector<vector<int>>& potentialNums, size_t index, vector<int>& currentCombination, vector<vector<int>>& results) {
    if (index == potentialNums.size()) {
        results.push_back(currentCombination);
        return;
    }

    for (int num : potentialNums[index]) {
        currentCombination.push_back(num);
        generateCombinations(potentialNums, index + 1, currentCombination, results);
        currentCombination.pop_back();
    }
}


vector<vector<int>> getCombinations(vector<vector<int>>& potentialNums) {
    vector<vector<int>> results;
    vector<int> temp;
    generateCombinations(potentialNums, 0, temp, results);
    return results;
}

void solve() {
    vector<string> digitMatrix(3);
    vector<string> displayMatrix(3);

    // Input for the digit matrix
    for (int i = 0; i < 3; i++) {
        getline(cin, digitMatrix[i]);
    }

    // Input for the display matrix
    for (int i = 0; i < 3; i++) {
        getline(cin, displayMatrix[i]);
    }

    map<int, string> digitPatterns;

    // Create the digit patterns for all 10 digits
    for (int digit = 0; digit < 10; digit++) {
        string pattern = "";
        for (int row = 0; row < 3; row++) {
            pattern += digitMatrix[row].substr(digit * 3, 3);
        }
        digitPatterns[digit] = pattern;
    }

    vector<vector<int>> potentialNums;
    int digitLength = displayMatrix[0].size() / 3;

    for (int i = 0; i < digitLength; i++) {
        string currentPattern = "";
        for (int row = 0; row < 3; row++) {
            currentPattern += displayMatrix[row].substr(i * 3, 3);
        }

        vector<int> matches = findMatchingDigits(digitPatterns, currentPattern);

        if (matches.empty()) {
            cout << "Invalid";
            return;
        }
        potentialNums.push_back(matches);
    }

    // Calculate the sum of all possible numbers
    int totalSum = 0;
    vector<vector<int>> combinations = getCombinations(potentialNums);

    for (auto& combination : combinations) {
        string number = "";
        for (int digit : combination) {
            number += to_string(digit);
        }
        totalSum += stoi(number);
    }

    cout << totalSum;
}

int main() {
    solve();
    return 0;
}