#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Function to clean and normalize a word
string CleanWord(const string& word) {
    string cleaned;
    for (char ch : word) {
        if (isalpha(ch)) {
            cleaned += tolower(ch);
        }
    }
    return cleaned;
}

int main() {
    // Step 1: Load dictionary file
    ifstream dictFile("dictionary.txt");
    if (!dictFile) {
        cerr << "Error: Could not open dictionary.txt" << endl;
        return 1;
    }

    vector<string> words;
    string dictWord;
    while (dictFile >> dictWord) {
        words.push_back(CleanWord(dictWord));
    }
    dictFile.close();

    // Step 2: Interactive input loop
    cout << "Spell Checker (type 'done' to quit)\n";
    string input;
    while (true) {
        cout << "\nEnter a word: ";
        cin >> input;

        if (input == "exit")
            break;

        string cleaned = CleanWord(input);
        if (cleaned.empty()) {
            cout << "No valid letters entered.\n";
            continue;
        }

        if (find(words.begin(), words.end(), cleaned) == words.end()) {
            cout << "Misspelled: " << cleaned << endl;
        }
        else {
            cout << "Correct.\n";
        }
    }

    return 0;
}