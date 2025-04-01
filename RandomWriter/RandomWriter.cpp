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

unordered_map<string, vector<char>> getCharFrequencies(ifstream);
void generateText();
ifstream getFile();
int getMarkov();

int main() {
    string textName = getLine("Enter the text file name: ");
    ifstream file = getFile();
    int markovNum = getMarkov();

    return 0;
}

// Function gets the text file name from user and validates input
ifstream getFile() {
    while (true) {
        string textName = getLine("Enter the CORRECT text file name: ");
        ifstream file = ifstream{ textName };
        if (file) return file;
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

// Function reads file by characters and constructs the matrix of character frequencies
unordered_map<string, vector<char>> getCharFrequencies(ifstream &data) {
    char ch;
    while (data.get(ch)) {

    }

}

// Generates the text according to the chosen markov model and model training text
void generateText() {

}
