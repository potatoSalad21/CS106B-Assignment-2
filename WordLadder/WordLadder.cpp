/*
 * File: WordLadder.cpp
 * --------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Word Ladder problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <unordered_set>
#include <vector>
#include "StanfordCPPLib/console.h"
#include "StanfordCPPLib/simpio.h"
#include "StanfordCPPLib/lexicon.h"
#include "StanfordCPPLib/queue.h"
using std::string;

vector<string> getLadder(Lexicon &words, string &start, string &dest);
void printLadder(vector<string> &ladder);

int main() {
    Lexicon data("EnglishWords.txt");
    std::cout << "HERE" << std::endl;
    while (true) {
        string startWord = getLine("Enter start word (RETURN to exit): ");
        string endWord = getLine("Enter destination word (RETURN to exit): ");
        if (startWord == "" || endWord == "") break; // validate input
        if (startWord.length() != endWord.length()) {
            std::cout << "Can't find a ladder" << std::endl;
            continue;
        }

        vector<string> ladder = getLadder(data, startWord, endWord);
        if (ladder.size() == 0) {
            std::cout << "Can't constrcut a ladder" << std::endl;
            continue;
        }
        printLadder(ladder);
    }

    return 0;
}

/* Constructs the word ladder with start and destination words
* return: word ladder string
*/
vector<string> getLadder(Lexicon &words, string &start, string &dest) {
    Queue<vector<string>> ladder;
    ladder.enqueue(vector<string>({ start })); // for base-case
    unordered_set<string> checkedWords;

    while (!ladder.isEmpty()) {
        vector<string> currentLad = ladder.dequeue();
        // base case: ladder completed
        if (currentLad[currentLad.size() - 1] == dest) {
            currentLad.pop_back();
            return currentLad;
        }

        for (int i = 0; i < start.length(); i++) {
            for (char ch = 'a'; ch <= 'z'; ch++) {
                string changedWord = currentLad[currentLad.size() - 1];
                changedWord[i] = ch;

                if (changedWord == dest) {
                    currentLad.push_back(dest);
                    return currentLad;
                }

                if (words.contains(changedWord) && !checkedWords.count(changedWord)) {
                    vector<string> newLad= currentLad;
                    newLad.push_back(changedWord);
                    checkedWords.insert(changedWord);
                    ladder.enqueue(newLad);
                }
            }
        }
    }

    return vector<string>(); // ladder can't be constructed, return empty vector
}

// print the words from the ladder
void printLadder(vector<string> &ladder) {
    cout << "Found Ladder: ";
    for (string word : ladder) {
        cout << word << " ";
    }
    cout << std::endl;
}
