// lab8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <queue>

struct comparer {
    bool compareStrings(const std::string a, const std::string b) const {

        for (int i = 0; i < a.size() && i < b.size(); i++) {
            if (a[i] != b[i]) {
                return a[i] > b[i];
            }
        }
        
        if (a.size() != b.size()) {
            return a.size() > b.size();
        }
    }

    bool operator()(std::pair<std::string, int> const& a, std::pair<std::string, int> const& b) {
        if (a.second == b.second) {
            return compareStrings(a.first, b.first);
        }
        return a.second < b.second;
    }
};
bool isCharacterADelim(char c) {
    char delim[] = " .!?,";
    for (auto i : delim) {
        if (i == c) {
            return true;
        }
    }
    return false;
}

std::string toLowerCase(std::string s) {
    for (int i = 0; i < s.size();i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
    }
    return s;
}

std::vector<std::string> getWordsFromString(std::string s) {
    std::string word = "";
    std::vector<std::string> words;
    for (auto i : s) {
        bool isDelim = isCharacterADelim(i);
        if (isDelim) {
            if (word == "") {
                continue;
            }
            words.push_back(toLowerCase(word));
            word = "";
        } else 
        word += i;
    }

    return words;
}

bool operator<(const std::pair<std::string, int>& x, const std::pair<std::string, int>& y) {
    return x.second > y.second;
}
int main()
{
    std::string s = "I bought an apple. Then I eat an apple. Apple is my favourite.";

    std::vector<std::string> words = getWordsFromString(s);

    std::map<std::string, int> wordsDictionary;
    for (auto word : words) {
        wordsDictionary[word] ++;
    }

    for (auto word : wordsDictionary) {
        std::cout << word.first << " " << word.second << '\n';
    }
    std::cout << "\n\n";

    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, comparer> q;

    for (auto word : wordsDictionary) {
        q.push(word);
    }

    while (!q.empty()) {
        auto top = q.top();
        q.pop();
        std::cout << top.first << " => " << top.second << '\n';
    }
}

