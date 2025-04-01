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
#include "StanfordCPPLib/console.h"
#include "StanfordCPPLib/simpio.h"
using std::string;

void getCharFrequencies(std::ifstream);
void generateText();

int main() {
    string textName = getLine("Enter the text file name: ");
    std::ifstream file{ textName };
    while (!file) { // validating input
        std::cerr << "Error: Couldn't find the file" << std::endl;
        string textName = getLine("Enter the CORRECT text file name: ");
        file = std::ifstream{ textName };
    }

    int markovNum = -1;
    while (markovNum < 0 || markovNum > 10) {
        markovNum = getInteger("Set the markov model number (1-10): ");
    }


    return 0;
}

// Function reads file by characters and constructs the matrix of character frequencies
void getCharFrequencies(std::ifstream &data) {
    char ch;
    while (data.get(ch)) {

    }

}

// Generates the text according to the chosen markov model and model training text
void generateText() {

}
