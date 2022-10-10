// Title: Lab 2 - Record.cpp
//
// Purpose: Implement Getters and Setters for Record Class
//
// Class: CSC 2430 Winter 2022
// Author: Christian Case Wright

#include "Record.h"

// Getter for _word member of Record class
string Record::GetWord() const {
    return _word;
}

// Getter for _count member of Record class
int Record::GetCount() const {
    return _count;
}

// Getter for _scoreTotal member of Record class
int Record::GetScoreTotal() const {
    return _scoreTotal;
}

// Setter for _word member of Record class
void Record::SetWord(string word) {
    _word = word;
}

// Setter for _count member of Record class
void Record::SetCount(int count) {
    _count = count;
}

// Setter for _scoreTotal member of Record class
void Record::SetScoreTotal(int scoreTotal) {
    _scoreTotal = scoreTotal;
}
