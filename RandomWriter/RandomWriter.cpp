/*
 * File: RandomWriter.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Random Writer problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "StanfordCPPLib/console.h"
#include "StanfordCPPLib/simpio.h"
#include "StanfordCPPLib/random.h"
using namespace std;

void getCharFrequencies(ifstream&, unordered_map<string, vector<char>>&, int);
void generateText(unordered_map<string, vector<char>>&, string&);
string getMostFreq(unordered_map<string, vector<char>>&);
ifstream getFile();
int getMarkov();

int main() {
    // get the starting info ready
    string textName = getLine("Enter the text file name: ");
    ifstream file = getFile();
    int markovNum = getMarkov();

    unordered_map<string, vector<char>> freqMap;
    getCharFrequencies(file, freqMap, markovNum);

    string mostFreq = getMostFreq(freqMap);
    generateText(freqMap, mostFreq);

    return 0;
}

// Generates the text according to the chosen markov model and model training text
void generateText(unordered_map<string, vector<char>> &freqMap, string &mostFreq) {
    if (freqMap.empty()) {
        cout << "Can't generate text, Not enough info!" << endl;
        return;
    }

    cout << mostFreq;
    int charNum = mostFreq.size();
    string curr = mostFreq;
    while (charNum < 2000) {
        vector<char> followingChars = freqMap[curr];
        if (followingChars.empty()) break;

        int randIdx = randomInteger(0, followingChars.size()-1);
        cout << followingChars[randIdx];
        curr = curr.substr(1) + followingChars[randIdx];
        charNum++;
    }

}

// Function reads file by characters and constructs the matrix of character frequencies
void getCharFrequencies(ifstream &data, unordered_map<string, vector<char>> &freqMap, int markovNum) {
    string curr; // store first k chars
    char ch;
    for (int i = 0; i < markovNum; i++) {
        if (data.get(ch))
            curr += ch;
        else return;
    }

    while (data.get(ch)) {
        freqMap[curr].push_back(ch);
        curr = curr.substr(1) + ch; // push back first char
    }
}

string getMostFreq(unordered_map<string, vector<char>> &freqMap) {
    int res = 0;
    string maxSequence;
    for (auto& [seq, _] : freqMap) {
        int followingCharsSz = freqMap[seq].size();
        if (followingCharsSz > res) {
            res = followingCharsSz;
            maxSequence = seq;
        }
    }

    return maxSequence;
}

// Function gets the text file name from user and validates input
ifstream getFile() {
    while (true) {
        string textName = getLine("Enter the correct text file name: ");
        ifstream file = ifstream{ textName };
        if (file) return file;
        cerr << "Error: incorrect file name." << endl;
    }
}

// Function gets the valid markov number input
int getMarkov() {
    int markovNum = -1;
    while (markovNum < 0 || markovNum > 10) {
        markovNum = getInteger("Set the markov model number (1-10): ");
    }

    return markovNum;
}

