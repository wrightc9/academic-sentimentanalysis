# Sentiment Analysis

## What is Sentiment Analysis?  
*“The process of computationally identifying and categorizing opinions expressed in a piece of text, especially in order to determine whether the writer's attitude towards a particular topic, product, etc. is positive, negative, or neutral.”*  - Oxford Dictionaries.

## Goal: 
Your assignment is to write a C++ program that reads in a file of movie reviews extracted from the Rotten Tomatoes movie review website and uses the information to build a database of the words it finds in the review data.   Your program will use this database to determine whether a movie review you enter indicates a generally positive, negative, or neutral sentiment.  

## Running the program with a very small movie review file

Below is the screenshot showing a run of the program where the movie review file `aFewReviews.txt` was entered.  This review file only contains 3 reviews, so it is useful for checking that your code works.  This file is supplied with the starter repo, but you will need to copy the file into your `cmake-build-debug` directory manually. (Alternatively you can use the file in your source code directory and input it as: `../aFewReviews.txt`)

![image](https://user-images.githubusercontent.com/58283777/147018919-3636e038-17e3-4006-af6c-36cdd7cf6272.png)

 
As you can see the program begins by prompting the user to enter the name of a movie review file.  Unless you enter a full path name, the program expects the file to be in the `cmake-build-debug` directory of your project.  

The program then builds a “database” from the information in the file.  When it finishes this task, it prints the time it took to read the file and build the database.  Your times will likely differ from the ones shown in the screenshots. You don't need to worry about the code to measure the time, it has been provided to you.

Next, the program prints summary information about the database that will give you some idea whether your database implementation is correct.

Following that, the user is prompted to type in a “review” for a movie so the program can determine numerical rating for the movie.  In the run shown above, just one or two words were entered for the review, so it is easier to understand how it works, but you can enter as many words as you would like before hitting [ENTER].

The user is allowed to enter as many reviews as desired.   When a blank line is entered, the program terminates.

## How the average score for a review is calculated

The file `aFewReviews.txt` looks like this:

 ![image](https://user-images.githubusercontent.com/58283777/147019058-200d2cfb-1716-4143-a20e-13011e4b194d.png)

It contains only three lines – the first and third lines are word wrapped because of their length.  Each line starts with an integer rating for a movie, followed by the text of the review.  The name of the movie is not given, because that isn’t important for what we are doing.

When the program opens a movie review file, it reads it line by line.  First it reads the numerical rating (score) and then it breaks the rest of the line into “words.”  For example, the “words” it finds on the second line would be:
```
This
quiet
,
introspective
and
entertaining
independent
is
worth
seeking
.
```
Note that a comma by itself or a period by itself is treated as a “word.”  If there were no blank characters between the letters of a word and the punctuation mark, then the letters and the punctuation mark together would form a “word.”  Blank characters  are used to break the string into words, but the blanks themselves never are “words” themselves.

Each time the program encounters a “word” it will record it in an in-memory “word database.” This database keeps track of how many times each word is seen (occurrence count) and maintains a running total of rating numbers (score totals). 

Here’s how it calculated the scores for the “reviews” entered in the run shown in the first screenshot in [Section 1](#Running-the-program-with-a-very-small-movie-review-file):
-	the word “`escapades`” is found once in the first review and nowhere else.  It would be recorded in the database with occurrence count of 1 and score total of 1 since the review it appeared once in a review that had rating 1.  Its average rating is 1/1 = 1.
-	the word “`introspective`” is found once in the second review and nowhere else.  It would be recorded in the database with occurrence count of 1 and score total of 4 since the review it appeared in had rating 4. Its average rating is 4/1 = 1.
-	The words “`This`” and “`this`” (**case matters!**) each appear once.  “`This`” appears on line 2 which has a rating of 4, so its average score is 4.  “`this`” appears on line 1 which has a rating of 1, so its average score is 1.
-	The word “`is`” appears twice in the first review, and once in the second review.  Hence, it will be stored in the database with occurrence count 3, and the score total will be 1+1+4 = 6.  It is 1+1 because of the two occurrences in a sentence with score 1, and adds the additional 4 because of the score of the second review. Its average rating is 6/3=2.
-	The word “`fantastic`” does not appear on any line.  It is not stored in the database, but when you query for its rating, the neutral rating of 2.0 is displayed.
-	When you enter multiple words, it takes the average of the word ratings.  So “`This is fantastic`” gets the score (4 + 2 + 2) / 3 = 2.66667, while “`this is fantastic`” gets the score (1 + 2 + 2) / 3 = 1.66667.


## Running the program with the full set of movie reviews

When everything seems to be working, you should try running with the file `movieReviews.txt`. You can type the name of the file if you wish, but if you enter a blank line, it defaults to this file. This is a considerably longer file.

![image](https://user-images.githubusercontent.com/58283777/147019513-8c6111de-95a7-4b99-83ae-59614ceb69d4.png)

## What you are given

In this lab, you are given a starter CLion project containing three .CPP files and two .H files.  

-	`main.cpp` – This file contains a completed main routine and a skeleton of the functions `BuildDatabase` and `AnalyzeReview` that you need to write.

-	`Database.h` –This file has been completed for you.  **Do NOT modify this file.**  It declares the four database interface functions used to access the database ADT.  These functions will be implemented in `Database.cpp`.  

-	`Database.cpp` – Except for `#include` and the definition of the constant `NEUTRAL`, the rest of this file’s implementation is left up to you.  You should finish the header comment for the file and add implementations for the four database interface functions.   Make sure a header comment precedes each of these four functions.

-	`Record.h` –This file has been completed for you.  **Do NOT modify this file.**  It declares the `Record` class which stores a word, the count of its occurrences, and a total of the scores for the word.

-	`Record.cpp` – Except for `#include` line, the rest of this file’s implementation is left up to you.  You should finish the header comment for the file and implement getters and setters for the private members of the class.

**Note**: Please follow these rules:

1)	Do not modify the main routine or change the declarations of `BuildDatabase` and `AnalyzeReview` in `main.cpp`.
2)	Do not make any modifications to the files `Database.h` and `Record.h`.
3) The only code that should make any changes to the *records* array should be code that is part of the four database functions declared in `Database.h`


## Recommended first steps

First, implement the getters and setters in `Record.cpp`.  

Next, stub out the four functions in `Database.cpp`.  In other words, add a skeleton implementation of the function to `Database.cpp`.  That way your project will build, because right now the link step will fail with undefined references.

When you stub out `AddWordToDatabase` it would be a very good idea to have it temporarily print a line that said it was called and the values of the word and score parameters.  That will make it easier for you to check that your implementation of `BuildDatabase` is working correctly.

## Implementing `BuildDatabase`

When you write the function `BuildDatabase` you get another chance to develop your skill in using the string class and reading from text files.  Here’s a rough sketch of what you need to do:

1. Open the file for reading.  You should check whether the file can be opened.  If not, you should print an informative message that includes the file name and return `false`.

2. Call `InitDatabase` to initialize the database.  

3. Begin a loop that continues until you hit the end of the file.  On each iteration of the loop

  a. Get the numerical score
  b. Get the rest of the line
  c. Break this line into “words”.  For each “word” you see call `AddWordToDatabase` to record the “word” and associated score in the database.  

HINT: there are multiple correct ways to write this logic, but you may want to consider using an `istringstream` object.

Before going further, spend enough time to check carefully that you are calling `AddWordToDatabase` with the correct words.

Here’s the start of what you might see with a correct implementation of `BuildDatabase`, and a stubbed implementation of `AddWordToDatabase` that print a message showing the values of the parameters word and score:
  
![image](https://user-images.githubusercontent.com/58283777/147019811-12248246-a300-49cf-9d25-14d0f4f6c1be.png)

Don’t forget to check the return value of `AddWordToDatabase`.  If it returns `false`, then you need to stop building the database and return `false`.

**Note**: the following parameters passed into `BuildDatabase` (`capacity`, `records`, and `size`) are part of the database interface.  You will pass them as parameters to `InitDatabase` and `AddWordToDatabase`, but you must not examine or modify their values when you implement `BuildDatabase`.  

## Implementing the database

You will be using an array of `Record` objects to implement your database.   

The array is declared within the main function, and this array along with its capacity (maximum number of words that can be stored) and its current size (number of words currently stored) are passed to the database interface functions in most cases.

Here are some notes about implementing each of these functions:

1) `InitDatabase`

This function must be called once before adding words to the database.  All it needs to do is set the number of words stored in the database to zero.

2) `AddWordToDatabase`

This function first iterates through the records array to determine if word already appears in the array.  If it does, it increments its occurrence count by 1, adds the score to the score total, and returns `true`.
If it doesn't find word in the records array, it will make sure that the number of elements stored hasn't reached its maximum.  If this is the case, it simply returns false to signal failure. 

Otherwise, it will use the `Record` object at the end of the records array to store word with occurrence count of 1 and the specified score.  Don’t forget to increase the count of elements in the array that are filled!  You should return `true` to indicate success.

3) `FindWordInDatabase`

This function will iterate through the records array to determine if the word appears in the array.  If it is found, it returns the count of `occurrences` and the average score in `averageScore` parameters.  If it is not found, occurrences should be set to 0 and averageScore to `NEUTRAL`.

4) `GetInfoAboutDatabase`

This function will iterate through the entire database and keep track of the minimum and maximum count of occurrences, and the minimum and maximum average scores.  The `numberWords` parameter simply returns the count of elements stored in the database.  

## Implementing `AnalyzeReview`

This function breaks the text in the parameter `review` into “words” in the same manner as `BuildDatabase`.  It looks up each “word” in the database to get its average score.  It should return the average of those scores.   


## Style

Your program will be graded on style as well as correctness.  Please refer to the style guidelines discussed in class and in reading assignments concerning

1)	Indention of code
2)	Consistent use of {}, preferably Stroustrup style
3)	Meaningful names of identifiers
4)	Naming conventions for identifiers
5)	No use of global variables
6)	Header comments for the file and each function
7)	Comments explaining sections of code or the purpose of a variable if not obvious
8)	Making sure object parameters are passed by reference (and declared const if appropriate)

As mentioned earlier, do not violate the ADT encapsulation.  Only the functions in database.cpp should access or modify the three arrays and the size and capacity arguments.


## Testing your code
Make sure you test your code thoroughly.  You should do your own testing of course, but for your convenience we are providing two files representing extreme edge cases:  noReviews.txt and tooManyReviews.txt.  Check previous screenshots to see what the expected output for those instances should look like.

## Grading Rubric

| Item                                          | Points |
|-----------------------------------------------|--------|
| File Reading, opens file                      | 5      |
| Validates file not found                      | 5      |
| Behaves correctly given `noReviews.txt`       | 5      |
| Behaves correctly given `tooManyReviews.txt`  | 5      |
| Counts number of words correctly              | 5      |
| Finds max occurrences for any word correctly | 5      |
| Finds min occurrences for any word correctly  | 5      |
| Finds max score for any word                  | 5      |
| Finds min score for any word                  | 5      |
| Calculates review average correctly (test 1)  | 10     |
| Calculates review average correctly (test 2)  | 5      |
| Calculates review average correctly (test 3)  | 15     |
| Calculates review average correctly (test 4)  | 10     |
| Calculates review average correctly (test 5)  | 10     |
| Program stops when entered empty file name    | 5      |

### Test Descriptions
* Test 1: Loads file `aFewReviews.txt`, calculates correctly:
  * "escapades"
  * "introspective"
* Test 2: Loads file `aFewReviews.txt`, calculates correctly:
  * "This is fantastic"
* Test 3: Loads file `movieReviews.txt`, calculates correctly:
  * "This was an awful movie"
  * "This was a fantastically good movie"
  * "vehement"
* Test 4: Loads file `movieReviews.txt`, calculates correctly a single word and a phrase (not given).
* Test 5: Loads file `ourMovieFile.txt` (not given), calculates correctly a single word and a phrase (not given).

### Deductions

* For each infraction on good programming practices there will be a deduction of 5 points
* If the program has a runtime error (the program crashes) there will be a deduction of 10 points
* If the program does not have comment headers there will be a deduction of 5 points
* If the program does not have comments on functions and appropriate additional comments there will be a deduction of 5 points
* If the program does not follow instructions, for instance if you did not implement any of the requested functions, there will be a deduction of 5 points per ignored instruction
* If the program does not compile, the grade will be zero.

### Grading yourself
It is possible, and **encouraged** that you grade your own assignment. The rubric provides a clear grading procedure. So, you should be able to discern 80% of your grade. The remaining 20% you can't accurately predict because it will be based on tests for which you don't have information, that is *Test 4* and *Test 5*. Make sure to run your program and compare your output with the output that we have shown in the screenshots. Accurately reproducing these results leads to a good grade. A warning: **hard-coding** your output will result in a zero grade!

## Academic Integrity

This programming assignment is to be done on an **individual** basis. At the same time, it is understood that learning from your peers is valid, and you are encouraged to talk among yourselves about programming in general and current assignments in particular.  Keep in mind, however, that each individual student must do the work in order to learn.  

Hence, the following guidelines are established:
* Feel free to discuss any and all programming assignments but do not allow other students to look at or copy your code. Do not give any student an electronic or printed copy of any program you write for this class.
* Gaining the ability to properly analyze common programming errors is an important experience. Do not deprive a fellow student of his/her opportunity to practice problem solving: control the urge to show them what to do by writing the code for them.
* If you’ve given the assignment a fair effort and still need help, see the instructor or a lab assistant.
* If there is any evidence that a program or other written assignment was copied from another student (or from any source), neither student will receive any credit for it. This rule will be enforced.
* Protect yourself: Handle throw-away program listings carefully.
* Remember to read the Academic Integrity guidelines provided in the class syllabus.

