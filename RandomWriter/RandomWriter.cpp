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
using namespace std;

void getCharFrequencies(ifstream&, unordered_map<string, vector<char>>&, int);
void generateText();
ifstream getFile();
int getMarkov();

int main() {
    // get the starting info ready
    string textName = getLine("Enter the text file name: ");
    ifstream file = getFile();
    int markovNum = getMarkov();

    unordered_map<string, vector<char>> freqMap;
    getCharFrequencies(file, freqMap, markovNum);

    return 0;
}

// Generates the text according to the chosen markov model and model training text
void generateText() {

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
        curr = curr.substr(1);
    }
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

