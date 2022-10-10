// Title: Lab 2 - Database.cpp
//
// Build database with the words, occurrences, and scores of each word and return their values
//
// Class: CSC 2430 Winter 2022
// Author: Christian Case Wright

#include "Database.h"
#include <iostream>

using namespace std;

// This is the value used to score a word not found in the database
const double NEUTRAL = 2.0;

// sets size of database to 0 and makes records array with capacity
// Parameters:
//      record - database
//      size - amount of words in database
//      capacity - max amount of words accepted
// Returns:
//      nothing
// Error Handling:
//      N/A
//
void InitDatabase(int capacity, Record records[], int& size)
{

    records[capacity];
    size =0;

}

// gets word from BuildDatabase and adds it to database, if word is found, increases count and total score
// otherwise, it sets score and count. if size is at capacity then returns false
// Parameters:
//      record - database
//      size - amount of words in database
//      word - word of the line
//      capacity - max amount of words accepted
//      score - finds the average score of the word score total / occurrences
// Returns:
//      true or false
// Error Handling:
//      makes sure does not store more words than capacity
//
bool AddWordToDatabase(int capacity, Record records[], int& size, const string& word, int score)
{
    // if size is zero, adds word to database, sets its score and count
    if(size == 0)
    {
        records[size].SetWord(word);
        records[size].SetScoreTotal(score);
        records[size].SetCount(1);

        size++;

        return true;
    }
    else
    {
        // looks through the database to see if the word is already stored
        // if it is stored, it increments count and score to total score
        for (size_t i = 0; i < size; i++)
        {
            if (records[i].GetWord() == word)
            {
                records[i].SetCount(records[i].GetCount() + 1);
                records[i].SetScoreTotal(records[i].GetScoreTotal() + score);

                return true;
            }
        }

        //  makes sure there is still room in database for the word, if there is, then it adds the word
        // and increments count and size by 1, and sets score
        if(size < capacity)
        {

            records[size].SetWord(word);
            records[size].SetCount(1);
            records[size].SetScoreTotal(score);

            size++;

            return true;
        }
        else
        {
            return false;
        }


    }
}

// Finds the word in database and divides its total score by its occurrences and sets the average score equal to that
// Parameters:
//      record - database
//      size - amount of words in database
//      word - word of the line
//      occurrences - amount of times word appears in the database
//      averageScore - finds the average score of the word score total / occurrences
// Returns:
//      nothing
// Error Handling:
//      makes sure the word appears in the database
//
void FindWordInDatabase(const Record records[], int size, const string& word, int& occurrences, double& averageScore)
{

    // Finds the word in database and divides its total score by its occurrences and sets the average score equal to that
    for(size_t i = 0; i < size; i++)
    {
        if(records[i].GetWord() == word)
        {
            occurrences = records[i].GetCount();
            averageScore = (double)records[i].GetScoreTotal() / (double)occurrences;

            return;
        }
        else
        {
            occurrences = 0;
            averageScore = NEUTRAL;
        }
    }
}

// Gets the min and max of occurrences and scores of the words in the database and sets them to the appropriate
// Parameters:
//      record - database
//      size - amount of words in database
//      numberWords - number of words in the database
//      maxOccurrences - highest appearances of a word in database
//      minOccurrences - lowest appearances of a word in database
//      maxScore - highest score among words in database
//      minScore - lowest score among words in database
//      ...
// Returns:
//      nothing
// Error Handling:
//      makes sure the review has files in it
//
void GetInfoAboutDatabase(const Record records[], int size, int& numberWords, int& maxOccurrences, int& minOccurrences, double& maxScore, double& minScore)
{
    maxOccurrences = 0;
    minOccurrences = INT32_MAX;

    maxScore = 0;
    minScore = INT32_MAX;

    // makes sure the file is not empty
    if(size == 0)
    {
        minScore = 0;
        minOccurrences = 0;

        cout << "\n\nNO REVIEWS IN FILE\n\n";
    }

    // gets minimum and maximum occurrences of words in the array and assigns them appropriately
    for(size_t i = 0; i < size; i++)
    {

        // finds and sets min occurrences
        if(records[i].GetCount() < minOccurrences && records[i].GetCount() > 0)
        {
            minOccurrences = records[i].GetCount();
        }

        // finds and sets max occurrences
        if(records[i].GetCount() > maxOccurrences)
        {
            maxOccurrences = records[i].GetCount();
        }

        // finds and sets minimum score
        if((double)records[i].GetScoreTotal() / (double)records[i].GetCount() < minScore)
        {
            minScore = (double)records[i].GetScoreTotal() / (double)records[i].GetCount();
        }

        // finds and sets maximum score
        if((double)records[i].GetScoreTotal() / (double)records[i].GetCount() > maxScore)
        {
            maxScore = (double)records[i].GetScoreTotal() / (double)records[i].GetCount();
        }

        // sizes number of words to size
        numberWords = size;

    }

}