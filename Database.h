// Title: Lab 2 - Database.h
//
// Purpose: Declares the functions that must be used for any attempt to access the word database.
//
// Class: CSC 2430 Winter 2022
// Author: Max Benson

#ifndef DATABASE_H
#define DATABASE_H

//
// THIS FILE SHOULD NOT BE MODIFIED
//

#include "Record.h"

const int CAPACITY  = 20000;

void InitDatabase(int capacity, Record records[], int& size);
bool AddWordToDatabase(int capacity, Record records[], int& size, const string& word, int score);
void FindWordInDatabase(const Record records[], int size,
        const string& word, int& occurrences, double& averageScore);
void GetInfoAboutDatabase(const Record records[], int size,
        int& numberWords, int& maxOccurrences, int& minOccurrences, double& maxScore, double& minScore);

#endif //DATABASE_H
