/*
 * File: WordLadder.cpp
 * --------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Word Ladder problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <vector>
#include "StanfordCPPLib/console.h"
#include "StanfordCPPLib/simpio.h"
#include "StanfordCPPLib/lexicon.h"
#include "StanfordCPPLib/queue.h"
using std::string;

string getLadder(Lexicon &words, string start, string dest);

int main() {
    Lexicon data("EnglishWords.dat");
    while (true) {
        string startWord = getLine("Enter start word (RETURN to exit): ");
        string endWord = getLine("Enter destination word (RETURN to exit): ");
        if (startWord == "" || endWord == "") break; // validate input
        if (startWord.length() != endWord.length()) {
            std::cout << "Can't find a ladder" << std::endl;
            continue;
        }

        getLadder(data, startWord, endWord);
    }

    return 0;
}

/* Constructs the word ladder with start and destination words
* return: word ladder string
*/
string getLadder(Lexicon &words, string start, string dest) {
    Queue<vector<string>> ladder;

    return "";
}
