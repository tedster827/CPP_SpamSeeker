/*
 *  Teddy Williams
 *  CS 421 Thoery of Computing
 *  Assignment 1 Spam Email Checker
 *  April 1, 2017
 *  NOTE:
 *  Only checks the body for keywords.
 *  Known Bugs: Emails with words like twin will be accepted even though
 *  they are not in the language. This is a fix that can be fixed by placing
 *  a space clause before checking for the keywords states.
 */

// Including the console input and out stream library.
#include <iostream>
// Including the input output management library.
#include <iomanip>
// Including the file stream library.
#include <fstream>
// Including the vector library.
#include <vector>
// Including the math library for pow(...).
#include <math.h>

using namespace std;

/*
 * Purpose: This is the non-deterministic finite automata
 * that accepts the string containing free_software,
 * free_trails, free_vacation, free_access, win, winner,
 * winners, and winnings.
 * Input: ifstream &if (Passing in by reference the file
 * stream)
 * Output: true (Spam Found)
 * false (No Spam Found)
 */
bool NDFA(ifstream &fin) {
  // Creating a vector with spam email mesage numbers.
  vector<int> mesNums;
  // Creating a vector to read in a single message number char by char.
  vector<int> aMesNum;
  // Creating an int variable to store and show what state it's in.
  int stateCounter = 0;
  // Creating a int variable to store the message number.
  int messageNum = 0;
  // Creating a char variable to store then read file input.
  char c = '<';
  // Displaying and output format.
  cout << "\nOutput Format: StateNumber:Input" << endl;
  // Going through the email.
  while(fin) {
    if(stateCounter%5 == 0 || stateCounter == 35 || stateCounter == 0) {
      cout << endl;
    }
    // Grabing a single char input from file.
    c = fin.get();
    /*
     * Format of each of the follow if/else/if else statements in this loop:
     * Check of the correct stateCounter value and expected char input value
     * to perform the correct change on the stateCounter.
     * Each if/else/if else block if display the state the non-deterministic
     * finite automata.
     */
    if(stateCounter == 0 && c == '<') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 1
    }
    else if(stateCounter == 1 && c == 'D') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 2
    }
    else if(stateCounter == 2 && c == 'O') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 3
    }
    else if(stateCounter == 3 && c == 'C') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 4
    }
    else if(stateCounter == 4 && c == '>') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 5
    }
    else if(stateCounter == 5 && c == '\n') {
      cout << setw(10) << stateCounter <<  ":\\n -> ";
      stateCounter++; // To State 6
    }
    else if(stateCounter == 6 && c == '<') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 7
    }
    else if(stateCounter == 7 && c == 'D') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 8
    }
    else if(stateCounter == 8 && c == 'O') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 9
    }
    else if(stateCounter == 9 && c == 'C') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 10
    }
    else if(stateCounter == 10 && c == 'I') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 11
    }
    else if(stateCounter == 11 && c == 'D') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 12
    }
    else if(stateCounter == 12 && c == '>') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 13
    }
    // Cases for the Message Number.
    else if(stateCounter == 13 && c == ' ') {
      cout << setw(10) << stateCounter <<  ":\" \" -> ";
      stateCounter = 14;
    }
    else if(stateCounter == 13 && c == 'm') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter = 15;
    }
    else if(stateCounter == 14 && c == 'm') {
      cout << setw(10) << stateCounter <<  ":\" \" -> ";
      stateCounter++; // Move to 15
    }
    else if(stateCounter == 15 && c == 's') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 16
    }
    else if(stateCounter == 16 && c == 'g') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 17
    }
    else if(stateCounter == 17) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      // Checking to see if the value is a number.
      if((int)c >= 48 && (int)c <= 57) {
        // Adding the values of the next number read.
        aMesNum.push_back((int)c -48);
        stateCounter++; // To State 18.
      }
      else if(c == ' ') {
        stateCounter++; // To State 19
      }
      else if(c == '<') {
        stateCounter = 20; // To State 20
      }
    }
    else if(stateCounter == 18) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == ' ') {
        stateCounter++; // To State 19.
      }
      else if(c == '<') {
        stateCounter = 20; // Starting to read </DOCID>
      }
      // Checking to see if the value is a number.
      else if((int)c >= 48 && (int)c <= 57) {
        // Adding the values of the next number read.
        aMesNum.push_back((int)c -48);
        stateCounter--; // Back to State 17.
      }
    }
    else if(stateCounter == 19 && c == '<') {
      cout << setw(10) << stateCounter <<  ":\" \" -> ";
      stateCounter++; // To State 20
    }
    else if(stateCounter == 20 && c == '/') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 21
    }
    else if(stateCounter == 21 && c == 'D') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 22
    }
    else if(stateCounter == 22 && c == 'O') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 23
    }
    else if(stateCounter == 23 && c == 'C') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 24
    }
    else if(stateCounter == 24 && c == 'I') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 25
    }
    else if(stateCounter == 25 && c == '>') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 26
    }
    else if(stateCounter == 26 && c == '\n') {
      cout << setw(10) << stateCounter <<  ":\\n -> ";
      stateCounter++; // To State 27
    }
    else if(stateCounter == 27 && c == 'S') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 28
    }
    else if(stateCounter == 28 && c == 'u') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 29
    }
    else if(stateCounter == 29 && c == 'b') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 30
    }
    else if(stateCounter == 30 && c == 'j') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 31
    }
    else if(stateCounter == 31 && c == 'e') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 32
    }
    else if(stateCounter == 32 && c == 'c') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 33
    }
    else if(stateCounter == 33 && c == 't') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 34
    }
    else if(stateCounter == 34 && c == ':') {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      stateCounter++; // To State 35
    }
    else if(stateCounter == 35) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == '\n') {
        stateCounter++; // To State 36
      }
      else {
        stateCounter = 35;
        // Back to State 35 to check for more characters
        // other then a new line.
      }
    }
    else if(stateCounter == 36 && c == '\n') {
      cout << setw(10) << stateCounter <<  ":\\n -> ";
      stateCounter++; // To State 37
    }
    else if(stateCounter == 37) {
      cout << setw(10) << stateCounter <<  ":" << c << endl;
      if(c == 'f') {
        stateCounter++; // To State 38
      }
      // Continue working with the win cases.
      else if(c == 'w') {
        stateCounter = 68;// Go to Win States (Starting with 68)
      }
      else if(c == '<') {
        stateCounter = 701; // New Email Checker States
      }
      else {
        stateCounter = 37; // Loop back to state 37 since it's not f or w.
      }
    }
    else if(stateCounter == 701) {
      cout << setw(10) << stateCounter <<  ":" << c << endl;
      if(c == '/') {
        stateCounter++; // To State 702
      }
      // Go back to main checking state (37) since it's not /
      else {
        stateCounter = 37;
      }
    }
    else if(stateCounter == 702) {
      cout << setw(10) << stateCounter <<  ":" << c << endl;
      if(c == 'D') {
        stateCounter++; // To State 703
      }
      // Go back to main checking state (37) since it's not D
      else {
        stateCounter = 37;
      }
    }
    else if(stateCounter == 703) {
      cout << setw(10) << stateCounter <<  ":" << c << endl;
      if(c == 'O') {
        stateCounter++; // To State 704
      }
      // Go back to main checking state (37) since it's not O
      else {
        stateCounter = 37;
      }
    }
    else if(stateCounter == 704) {
      cout << setw(10) << stateCounter <<  ":" << c << endl;
      if(c == 'C') {
        stateCounter++; // To State 705
      }
      // Go back to main checking state (37) since it's not C
      else {
        stateCounter = 37;
      }
    }
    else if(stateCounter == 705) {
      cout << setw(10) << stateCounter <<  ":" << c << endl;
      if(c == '>') {
        stateCounter++; // To State 706
      }
      // Go back to main checking state (37) since it's not >
      else {
        stateCounter = 37;
      }
    }
    else if(stateCounter == 706) {
      cout << setw(10) << stateCounter <<  ":" << c << endl;
      // Clearing message number tracks beause spam words were not found.
      messageNum = 0;
      aMesNum.clear();
      if(c == '\n') {
        stateCounter = 0; // Go to Start State Email Ended.
      }
      // Go back to main checking state (37) since it's not >
      else {
        stateCounter = 37;
      }
    }
    else if(stateCounter == 68) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'i') {
        stateCounter++; // To State 69
      }
      else {
        // Go back to main checking state (37) since it's not i
        stateCounter = 37;
      }
    }
    else if(stateCounter == 69) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'n') {
        stateCounter++; // To State 70
      }
      else {
        // Go back to main checking state (37) since it's not n
        stateCounter = 37;
      }
    }
    else if(stateCounter == 70) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(
        // Checking for !"#$%&'()*+'-./
        ((int)c >= 32 && (int)c <= 47)
        // Checking for {|}~
        || ((int)c >= 123 && (int)c <= 126)
        // Checking for [\]^_`
        || ((int)c >= 91 && (int)c <= 96)
        // Checking for :;=>?@ but not <
        || ((int)c >= 58 && (int)c <= 64 && c != '<')) {
          stateCounter = 77;// Go to </DOC> checking states.
          // Spacing found after keyword win
        }
      else if(c == 'n') {
        stateCounter++; // To State 71
      }
      else {
        // Go back to main checking state (37) since it's not n
        stateCounter = 37;
      }
    }
    else if(stateCounter == 71) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'e') {
        stateCounter++; // To State 72
      }
      else if(c == 'i') {
        stateCounter = 74;
      }
      else {
        // Go back to main checking state (37) since it's not e
        stateCounter = 37;
      }
    }
    else if(stateCounter == 72) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'r') {
        stateCounter++; // To State 73
      }
      else {
        // Go back to main checking state (37) since it's not r
        stateCounter = 37;
      }
    }
    else if(stateCounter == 73) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(
        // Checking for !"#$%&'()*+'-./
        ((int)c >= 32 && (int)c <= 47)
        // Checking for {|}~
        || ((int)c >= 123 && (int)c <= 126)
        // Checking for [\]^_`
        || ((int)c >= 91 && (int)c <= 96)
        // Checking for :;=>?@ but not <
        || ((int)c >= 58 && (int)c <= 64 && c != '<')) {
          stateCounter = 77;// Go to </DOC> checking states.
          // Spacing found after keyword winner
        }
      else if(c == 's') {
        stateCounter = 48; // To State 48 (Final Checking State for Keywords.)
      }
      else {
        // Go back to main checking state (37) since it's not r
        stateCounter = 37;
      }
    } // End of winners case.
    else if(stateCounter == 74) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'n') {
        stateCounter++; // To State 75
      }
      else {
        // Go back to main checking state (37) since it's not n
        stateCounter = 37;
      }
    }
    else if(stateCounter == 75) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'g') {
        stateCounter++; // To State 76
      }
      else {
        // Go back to main checking state (37) since it's not g
        stateCounter = 37;
      }
    }
    else if(stateCounter == 76) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 's') {
        stateCounter = 48; // To State 48 (Final Checking State for Keywords.)
      }
      else {
        // Go back to main checking state (37) since it's not s
        stateCounter = 37;
      }
    } // End of winnings and win cases.
    // Going into the free words states.
    else if(stateCounter == 38) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'r') {
        stateCounter++; // To State 39
      }
      else {
        // Go back to main checking state (37) since it's not r
        stateCounter = 37;
      }
    }
    else if(stateCounter == 39) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'e') {
        stateCounter++; // To State 40
      }
      else {
        // Go back to main checking state (37) since it's not e
        stateCounter = 37;
      }

    }
    else if(stateCounter == 40) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'e') {
        stateCounter++; // To State 41
      }
      else {
        // Go back to main checking state (37) since it's not e
        stateCounter = 37;
      }
    }
    else if(stateCounter == 41) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == ' ') {
        stateCounter++; // To State 42
      }
      else {
        // Go back to main checking state (37) since it's not a space
        stateCounter = 37;
      }
    }
    // free after the space cases.
    else if(stateCounter == 42) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'a') {
        stateCounter++; // To State 43
      }
      else if(c == 'v') {
        stateCounter = 49;// Go to free_vacation cases (Starting with 49).
      }
      else if(c == 's') {
        stateCounter = 56;// Go to free_software cases (Starting with 56).
      }
      else if(c == 't') {
        stateCounter = 63;// Go to free_trial cases (Starting with 63).
      }
      else if(c == 'w') {
        // Go to win(ner/ners/nings) cases (Starting with 68) w found.
        stateCounter = 68;
      }
      else {
        // Go back to main checking state (37) since it's not a, v, s, or t
        stateCounter = 37;
      }
    }
    // Checking the free_trail case.
    else if(stateCounter == 63) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'r') {
        stateCounter++; // To State 64
      }
      else {
        // Go back to main checking state (37) since it's not r
        stateCounter = 37;
      }
    }
    else if(stateCounter == 64) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'i') {
        stateCounter++; // To State 65
      }
      else {
        // Go back to main checking state (37) since it's not i
        stateCounter = 37;
      }
    }
    else if(stateCounter == 65) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'a') {
        stateCounter++; // To State 66
      }
      else {
        // Go back to main checking state (37) since it's not a
        stateCounter = 37;
      }
    }
    else if(stateCounter == 66) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'l') {
        stateCounter++; // To State 67
      }
      else {
        // Go back to main checking state (37) since it's not l
        stateCounter = 37;
      }
    }
    else if(stateCounter == 67) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 's') {
        stateCounter = 48; // To State 48 (Final Checking State for Keywords.)
      }
      else {
        // Go back to main checking state (37) since it's not s
        stateCounter = 37;
      }
    } // End of free_trails case.
    // Checking the free_software case.
    else if(stateCounter == 56) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'o') {
        stateCounter++; // To State 57
      }
      else {
        // Go back to main checking state (37) since it's not o
        stateCounter = 37;
      }
    }
    else if(stateCounter == 57) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'f') {
        stateCounter++; // To State 58
      }
      else {
        // Go back to main checking state (37) since it's not f
        stateCounter = 37;
      }
    }
    else if(stateCounter == 58) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 't') {
        stateCounter++; // To State 59
      }
      else {
        // Go back to main checking state (37) since it's not t
        stateCounter = 37;
      }
    }
    else if(stateCounter == 59) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'w') {
        stateCounter++; // To State 60
      }
      else {
        // Go back to main checking state (37) since it's not w
        stateCounter = 37;
      }
    }
    else if(stateCounter == 60) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'a') {
        stateCounter++; // To State 61
      }
      else {
        // Go back to main checking state (37) since it's not a
        stateCounter = 37;
      }
    }
    else if(stateCounter == 61) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'r') {
        stateCounter++; // To State 62
      }
      else {
        // Go back to main checking state (37) since it's not r
        stateCounter = 37;
      }
    }
    else if(stateCounter == 62) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'e') {
        stateCounter = 48; // To State 48 (Final Checking State for Keywords.)
      }
      else {
        // Go back to main checking state (37) since it's not e
        stateCounter = 37;
      }
    } // End of free_software case.
    // Checking the free_vacation case.
    else if(stateCounter == 49) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'a') {
        stateCounter++; // To State 50
      }
      else {
        // Go back to main checking state (37) since it's not a
        stateCounter = 37;
      }
    }
    else if(stateCounter == 50) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'c') {
        stateCounter++; // To State 51
      }
      else {
        // Go back to main checking state (37) since it's not c
        stateCounter = 37;
      }
    }
    else if(stateCounter == 51) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'a') {
        stateCounter++; // To State 52
      }
      else {
        // Go back to main checking state (37) since it's not a
        stateCounter = 37;
      }
    }
    else if(stateCounter == 52) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 't') {
        stateCounter++; // To State 53
      }
      else {
        // Go back to main checking state (37) since it's not t
        stateCounter = 37;
      }
    }
    else if(stateCounter == 53) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'i') {
        stateCounter++; // To State 54
      }
      else {
        // Go back to main checking state (37) since it's not i
        stateCounter = 37;
      }
    }
    else if(stateCounter == 54) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'o') {
        stateCounter++; // To State 55
      }
      else {
        // Go back to main checking state (37) since it's not o
        stateCounter = 37;
      }
    }
    else if(stateCounter == 55) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'n') {
        stateCounter = 48; // To State 48 (Final Checking State for Keywords.)
      }
      else {
        // Go back to main checking state (37) since it's not n
        stateCounter = 37;
      }
    } // End of free_vacation case.
    // Checking free_access case.
    else if(stateCounter == 43) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'c') {
        stateCounter++; // To State 44
      }
      else {
        // Go back to main checking state (37) since it's not c
        stateCounter = 37;
      }
    }
    else if(stateCounter == 44) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'c') {
        stateCounter++; // To State 45
      }
      else {
        // Go back to main checking state (37) since it's not c
        stateCounter = 37;
      }
    }
    else if(stateCounter == 45) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 'e') {
        stateCounter++; // To State 46
      }
      else {
        // Go back to main checking state (37) since it's not e
        stateCounter = 37;
      }
    }
    else if(stateCounter == 46) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 's') {
        stateCounter++; // To State 47
      }
      else {
        // Go back to main checking state (37) since it's not s
        stateCounter = 37;
      }
    }
    else if(stateCounter == 47) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c == 's') {
        stateCounter++; // To State 48 (Final Checking State for Keywords.)
      }
      else {
        // Go back to main checking state (37) since it's not s
        stateCounter = 37;
      }
    } // End of free_access case.
    else if (stateCounter == 48) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
        if(
          // Checking for !"#$%&'()*+'-./
          ((int)c >= 32 && (int)c <= 47)
          // Checking for {|}~
          || ((int)c >= 123 && (int)c <= 126)
          // Checking for [\]^_`
          || ((int)c >= 91 && (int)c <= 96)
          // Checking for :;=>?@ but not <
          || ((int)c >= 58 && (int)c <= 64 && c != '<')) {
            stateCounter = 77;// Go to </DOC> checking states.
          }
          else if(c == '<') {
            stateCounter = 78;// Go to state after < checking states (78)
          }
        }
    // State before </DOC> tag
    else if(stateCounter == 77) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c != '<') {
        stateCounter = 77; // Stay in state and wait for a <
      }
      else {
        stateCounter++; // To State 78
      }
    }
    else if(stateCounter == 78) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c != '/') {
        stateCounter = 77; // Go to state 77 and stay and wait for a <
      }
      else {
        stateCounter++; // To State 79
      }
    }
    else if(stateCounter == 79) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c != 'D') {
        stateCounter = 77; // Go to state 77 and stay and wait for a <
      }
      else {
        stateCounter++; // To State 80
      }
    }
    else if(stateCounter == 80) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c != 'O') {
        stateCounter = 77; // Go to state 77 and stay and wait for a <
      }
      else {
        stateCounter++; // To State 81
      }
    }
    else if(stateCounter == 81) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c != 'C') {
        stateCounter = 77; // Go to state 77 and stay and wait for a <
      }
      else {
        stateCounter++; // To State 82
      }
    }
    else if(stateCounter == 82) {
      cout << setw(10) << stateCounter <<  ":" << c << " -> ";
      if(c != '>') {
        stateCounter = 77; // Go to state 77 and stay and wait for a <
      }
      else {
        stateCounter++; // To State 83 (Final State!)
      }
    }
    else if(stateCounter == 83) {
      cout << setw(10) << "Final Accepted State:" <<stateCounter <<  ":" << c << " -> ";
      for(int i = 0; i < aMesNum.size(); i++) {
        messageNum += aMesNum[i]*pow(10, aMesNum.size() - i - 1);
      }
      cout << "\n Spam Email Found! Mes#" << messageNum << endl;
      // Pushing back message number because a keyword was found.
      mesNums.push_back(messageNum);
      // Clearing Message Number Values for new email(s).
      messageNum = 0;
      aMesNum.clear();
      stateCounter = 0; // Check next email
    }
  }
  if(mesNums.size() != 0) {
    cout << "Messages Identified As Spam: ";
    // Displaying spam message numbers.
    for(int i = 0; i < mesNums.size(); i++) {
      if(i == mesNums.size() - 1) {
        cout << mesNums[i] << ".";
      }
      else {
        cout << mesNums[i] << ", ";
      }
    }
    cout << endl;
    // One or more spam messages were found.
    return true;
  }
  // No Messages were spam.
  return false;
}
/*
 * Purpose: This function is the main driver function it will
 * Inputs: The integer argc is the number of arguments that are passing using the
 * execution command. The char const* (or C string array) stores all the arguments.
 * Output: Exit Code (0)
 */
int main(int argc, char const *argv[]) {
  // Checking for a valid amount of excution values (1 Only).
  if(argc == 1) {
    // Creating a file stream to read the file with emails.
    ifstream fin;
    // Opening the file using the input file stream.
    fin.open("messagefile.txt");
    // Displaying an error message if the file was not found in the directory.
    if(!fin) {
      cout << "File could not be opened." << endl;
      cout << "The most likely issue is that the file does not exist in " << endl;
      cout << "the current directory." << endl;
      // Exit Call (Error: -1)
      return -1;
    }
    // Calling NDFA to check emails
    if(NDFA(fin)) {
      cout << "Spam Found!" << endl;
    }
    else {
      cout << "No Messages held the correct words to be called an accepted" << endl;
      cout << "string in this language." << endl;
      // Closing file stream.
      fin.close();
      return 0;
    }
    // Closing file stream.
    fin.close();
    // Exit Call (No Error: 0)
    return 0;
  }
  /*
   * Displaying error message when more than one arguments are found in the
   * excution command.
   */
  else {
    cout << "No execution arguments are accepted by this console program.\n";
    cout << "Terminating Program." << endl;
    // Exit Call (Error: -2)
    return -2;
  }
  // Exit Call (Error: -3)
  return -3;
}
